#include "ClientController.h"


ClientController::ClientController(Client* currentCient) : mCurrentClient(currentCient) {

}

void ClientController::setCurrentDebitAccount(std::string uid)
{
	for (auto& account : PaymentService::getInstance()->getDebitAccounts()) {
		if (std::to_string(account.getUid()) == uid) {
			mCurrentDebitAccount = &account;
		}
	}
}

std::vector<std::string> ClientController::getCurrentDebitAccount()
{
	return { std::to_string(mCurrentDebitAccount->getUid()),
						mCurrentDebitAccount->getCurrency(),
						std::to_string(mCurrentDebitAccount->getAmount()),
						std::to_string(mCurrentDebitAccount->getDepositRate()),
						mCurrentDebitAccount->getStatus()
	};
}


/* =========================================================================================================== *
                              ACCOUNTS TAB
*  =========================================================================================================== */


std::vector<std::vector<std::string>> ClientController::getAllAccounts() {

	std::vector<std::vector<std::string>> accounts;

	int it = 0;
	for (auto& account : PaymentService::getInstance()->getDebitAccounts()) {

		for (auto& userAccount : mCurrentClient->getDebitAccounts()) {
			if (account.getUid() == userAccount) {
				accounts.push_back(
					{
						std::to_string(it),
						std::to_string(account.getUid()),
						account.getCurrency(),
						std::to_string(floor((account.getAmount() * 100) + 0.5) / 100.00),
						DEBIT_ACCOUNT,
						std::to_string(round(account.getDepositRate() * 100.0) / 100.0),
						account.getStatus(),
					}
				);
				it++;
			}
		}
	}
	//for (auto& account : PaymentService::getInstance()->getCreditAccounts()) {

	//	accounts.push_back(
	//		{
	//			std::to_string(it),
	//			std::to_string(account.getUid()),
	//			account.getCurrency(),
	//			std::to_string(account.getAmount()),
	//			account.getStatus(),
	//			std::to_string(account.getLoanRate())
	//		}
	//	);

	//	it++;
	//}

	return accounts;
}


void ClientController::createDebitAccount(std::string currency)
{
    int uid = getNewAccountUid();
    
    PaymentService::getInstance()->addDebitAccount(
       DebitAccount(
                uid,
                currency,
                0.00,
                PENDING_APPROVAL,
                DEPOSIT_RATE)
        );

        mCurrentClient->addDebitAccount(uid);
}

void ClientController::createCreditAccount(std::string currency, double amount)
{
    int uid = getNewAccountUid();
        PaymentService::getInstance()->addCreditAccount(
            CreditAccount(
                uid,
                currency,
                amount,
                PENDING_APPROVAL,
                LOAN_RATE)
        );

        mCurrentClient->addCreditAccount(uid);
}


bool ClientController::sendMoney(std::string recipientAccountUid, double amount)
{
	if (mCurrentDebitAccount->getAmount() >= amount) {
		for (auto& account : PaymentService::getInstance()->getDebitAccounts()) {
			if (std::to_string(account.getUid()) == recipientAccountUid) {
				if (account.getCurrency() == mCurrentDebitAccount->getCurrency()) {

					// add money to recipient
					account.setAmount(account.getAmount() + amount);

					// substract money from sender
					mCurrentDebitAccount->setAmount(mCurrentDebitAccount->getAmount() - amount);

					return true;
				}
			}
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