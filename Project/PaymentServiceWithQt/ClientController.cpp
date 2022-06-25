#include "ClientController.h"


ClientController::ClientController(Client* currentCient) : mCurrentClient(currentCient) {

}



void ClientController::setCurrentAccount(std::string uid) {

	for (auto& account : getAllBaseAccounts()) {
		if (std::to_string(account->getUid()) == uid) {
			mCurrentAccount = account;
		}
	}
}


std::shared_ptr<BaseAccount> ClientController::getCurrentAccount() {
	return std::shared_ptr<BaseAccount>();
}

std::vector<std::string> ClientController::getCurrentStringAccount() {
	return mCurrentAccount->toString();
}


/* =========================================================================================================== *
                              ACCOUNTS TAB
*  =========================================================================================================== */

std::vector <std::shared_ptr<BaseAccount>> ClientController::getAllBaseAccounts() {

	std::vector <std::shared_ptr<BaseAccount>> result;
	//auto creditVec (PaymentService::getInstance()->getCreditAccounts());
	//auto debitVec (PaymentService::getInstance()->getDebitAccounts());

	//result.insert(result.end(), debitVec.begin(), debitVec.end());
	//result.insert(result.end(), creditVec.begin(), creditVec.end());


	for (auto& account : PaymentService::getInstance()->getDebitAccounts()) {
		if (account.getStatus() != SUSPENDED) {
			std::shared_ptr<DebitAccount> shared = std::make_shared<DebitAccount>(account);
			result.push_back(shared);
		}
	}

	for (auto& account : PaymentService::getInstance()->getCreditAccounts()) {
		if (account.getStatus() != SUSPENDED) {
			std::shared_ptr<CreditAccount> shared = std::make_shared<CreditAccount>(account);
			result.push_back(shared);
		}
	}

	return result;
}

std::vector <std::vector<std::string>> ClientController::getMyBaseAccounts() {

	std::vector <std::vector<std::string>> result;

	for (auto& account : getAllBaseAccounts()) {
		if (
			std::find(
				mCurrentClient->getDebitAccounts().begin(),
				mCurrentClient->getDebitAccounts().end(),
				account->getUid()
			) != mCurrentClient->getDebitAccounts().end()) {

			result.push_back(account->toString());
		}
		if (
			std::find(
				mCurrentClient->getCreditAccounts().begin(),
				mCurrentClient->getCreditAccounts().end(),
				account->getUid()
			) != mCurrentClient->getCreditAccounts().end()) {

			result.push_back(account->toString());
		}
	}

	

	return result;
}

std::vector<std::vector<std::string>> ClientController::getAllAccounts() {

	std::vector<std::variant<DebitAccount, CreditAccount>> accounts;
	std::vector<std::vector<std::string>> result;

	for (auto& account : PaymentService::getInstance()->getDebitAccounts()) {
		if (
			std::find(
			mCurrentClient->getDebitAccounts().begin(), 
			mCurrentClient->getDebitAccounts().end(), 
			account.getUid()
			) != mCurrentClient->getDebitAccounts().end()) {
			accounts.push_back(account);
		}
	}

	for (auto& account : PaymentService::getInstance()->getCreditAccounts()) {
		if (
			std::find(
				mCurrentClient->getCreditAccounts().begin(),
				mCurrentClient->getCreditAccounts().end(),
				account.getUid()
			) != mCurrentClient->getCreditAccounts().end()) {
			accounts.push_back(account);
		}
	}

	for (auto& account : accounts) {
		std::visit([&result](auto& object) {

			result.push_back(object.toStringVector());

		}, account);
	}

	return result;
}

bool ClientController::exists(int id) {
	for (auto& account : getAllBaseAccounts()) {
		if (account->getUid() == id
			&& account->getStatus() == APPROVED) {
			return true;
		}
	}
	return false;
}

bool ClientController::suspendAccount() {

	if (
		isCreditAccount(mCurrentAccount->getUid())
		&& mCurrentAccount->getAmount() < FOREIGN_LOAN_LIMIT(mCurrentAccount->getCurrency())
		) {
		return false;
	}
	mCurrentAccount->setStatus(SUSPENDED);

	// Saving
	PaymentService::getInstance()->updateAccount(mCurrentAccount);
	pushToDatabase();

	return true;
}

bool ClientController::isCreditAccount(int uid) {

	for (auto& account : getAllBaseAccounts()) {
		if (account->getUid() == uid) {
			if (account->getType() == CREDIT_ACCOUNT) {
				return true;
			}
		}
	}
	return false;
}

bool ClientController::addOwner(std::string email) {

	// You cannot make other people responsible for your loans.
	if (isCreditAccount(mCurrentAccount->getUid())) {
		return false;
	}

	for (auto& client : PaymentService::getInstance()->getClients()) {
		if (client.getEmail() == email) {
			client.addDebitAccount(mCurrentAccount->getUid());
			return true;
		}
	}

	pushToDatabase();
	return false;
}





/*
* 1. Take the balance 
* 2. Take the date of the previous recalculation (from the account property)
* 3. Convert string date to Date struct
* 4. Get present date and convert it to Date struct
* 5. Get the difference in days
* 6. Do compoundInterestFunction
*/
void ClientController::recalculateDepositBalance(std::shared_ptr<BaseAccount> account) {

	double initialBalance = account->getAmount();
	std::string currency = account->getCurrency();
	std::string lastRecalculationString = account->getLastBalanceRecalculation(); // DD MM YYYY

	Date lastRecalculation = stringToDate(lastRecalculationString, '-');

	Date currentDate = stringToDate(getCurrentDate(), '-');

	int days = getDifference(lastRecalculation, currentDate);

	double newBalance = compoundInterest(initialBalance, FOREIGN_DEPOSIT_INTEREST(currency), days);

	account->setAmount(newBalance);

	account->setLastBalanceRecalculation(getCurrentDate());

	PaymentService::getInstance()->updateAccount(account);
}



/*
* 1. Take the balance
* 2. If it is <70% out of 10K in USD -> 
*	3. Take previous recaalculation date
*	4. Convert string date to Date struct using regex
*	5. Get present date and convert it to Date struct
*	6. Get the difference in days
*	7. Do loan function
*/
bool ClientController::recalculateCreditBalance(std::shared_ptr<BaseAccount> account) {

	double initialBalance = account->getAmount();
	std::string currency = account->getCurrency();
	std::string lastRecalculationString = account->getLastBalanceRecalculation(); // DD MM YYYY

	if (initialBalance < (FOREIGN_LOAN_LIMIT(currency) * CRITICAL_AMOUNT)) {

		return false;

	} else if (initialBalance < (FOREIGN_LOAN_LIMIT(currency) * MIN_INTEREST_FREE)) {

		Date lastRecalculation = stringToDate(lastRecalculationString, '-');

		Date currentDate = stringToDate(getCurrentDate(), '-');

		int days = getDifference(lastRecalculation, currentDate);

		double newBalance = loanInterest(initialBalance, FOREIGN_LOAN_INTEREST(currency), days);

		account->setAmount(newBalance);

		account->setLastBalanceRecalculation(getCurrentDate());

		PaymentService::getInstance()->updateAccount(account);

	}
	else {
		account->setLastBalanceRecalculation(getCurrentDate());
	}

	return true;
}


void ClientController::createAccount(std::string type, std::string currency)
{

	int uid = getNewAccountUid();


	if (type == DEBIT_ACCOUNT) {
		PaymentService::getInstance()->addDebitAccount(
			DebitAccount(
				uid,
				currency,
				0.00,
				PENDING_APPROVAL,
				getCurrentDate())
		);

		mCurrentClient->addDebitAccount(uid);
	}
	else {
		PaymentService::getInstance()->addCreditAccount(
			CreditAccount(
				uid,
				currency,
				FOREIGN_LOAN_LIMIT(currency),
				PENDING_APPROVAL,
				getCurrentDate())
		);

		mCurrentClient->addCreditAccount(uid);
	}

	pushToDatabase();
}

bool ClientController::recalculationSuccessful() {

	for (auto& account : getAllBaseAccounts()) {


		if (account->getType() == DEBIT_ACCOUNT) {
			recalculateDepositBalance(account);
		}
		else {
			if (!recalculateCreditBalance(account)) {

				// is it mine?
				if (std::find(
					mCurrentClient->getCreditAccounts().begin(),
					mCurrentClient->getCreditAccounts().end(),
					account->getUid()
				) != mCurrentClient->getCreditAccounts().end()) {
					return false;
				}
			}
		}
	}
	pushToDatabase();
	pullFromDatabase();
	return true;
}

// Done
bool ClientController::sendMoney(int recipientAccountUid, double amount) {

	for (auto& account : getAllBaseAccounts()) {
		if (
			account->getUid() == recipientAccountUid
			&& exists(recipientAccountUid)
			&& mCurrentAccount->getAmount() >= amount
			) {

			// add money to recipient
			account->setAmount(account->getAmount() + (amount / RATES.find(account->getCurrency())->second));
			PaymentService::getInstance()->updateAccount(account);

			// substract money from sender
			mCurrentAccount->setAmount(mCurrentAccount->getAmount() - amount);
			PaymentService::getInstance()->updateAccount(mCurrentAccount);


			pushToDatabase();
			return true;
		}
	}
	return false;
}



/* =========================================================================================================== *
							  MORE TAB
*  =========================================================================================================== */



std::string ClientController::getCurrentUserEmail() {
	return mCurrentClient->getEmail();
}