#include "StaffController.h"



StaffController::StaffController(Staff* currentStaff) : mCurrentStaff(currentStaff) {}

StaffController::~StaffController() {
	delete mCurrentStaff;
}



/* =========================================================================================================== *
                              REGISTER REQUESTS TAB                                     
*  =========================================================================================================== */

std::vector<std::vector<std::string>> StaffController::getAllUsers() {

	std::vector<std::vector<std::string>> users;

	int it = 0;
	for (auto& client : PaymentService::getInstance()->getClients()) {

		users.push_back(
			{ 
				std::to_string(it),
				client.getUsername(),
				client.getEmail(),
				client.getStatus()
			}
		);

		it++;
	}
	return users;
}


bool StaffController::isClientApproved(int id) {
	if (PaymentService::getInstance()->getClients().at(id).getStatus() == APPROVED) {
		return true;
	}
	return false;
}


void StaffController::changeClientStatus(int clientId, std::string newStatus) {

	PaymentService::getInstance()->getClients().at(clientId).setStatus(newStatus);
	// IMPORTANT!
	pushToDatabase();
}


/* =========================================================================================================== *
							  ACCOUNTS TAB
*  =========================================================================================================== */

std::vector<std::vector<std::string>> StaffController::getAllAccounts() {

	std::vector<std::variant<DebitAccount,CreditAccount>> accounts;
	std::vector<std::vector<std::string>> result;

	for (auto& account : PaymentService::getInstance()->getDebitAccounts()) {
		accounts.push_back(account);
	}

	for (auto& account : PaymentService::getInstance()->getCreditAccounts()) {
		accounts.push_back(account);
	}

	for (auto& account : accounts) {
		std::visit([&result](auto& object) { 

			result.push_back(object.toStringVector());

		}, account);
	}

	return result;
}


bool StaffController::isAccountApproved(int id) {
	if (getAllAccounts()[id][4] == APPROVED) {
		return true;
	}
	return false;
}


void StaffController::changeAccountStatus(int accountId, std::string newStatus) {

	if (getAllAccounts()[accountId][3] == DEBIT_ACCOUNT) {

		for (auto& account : PaymentService::getInstance()->getDebitAccounts()) {
			if (std::to_string(account.getUid()) == getAllAccounts()[accountId][0]) {
				account.setStatus(newStatus);
			}
		}
	}
	else {
		for (auto& account : PaymentService::getInstance()->getCreditAccounts()) {
			if (std::to_string(account.getUid()) == getAllAccounts()[accountId][0]) {
				account.setStatus(newStatus);
			}
		}
	}

	// IMPORTANT!
	pushToDatabase();

}


/* =========================================================================================================== *
							  MORE TAB
*  =========================================================================================================== */

std::string StaffController::getCurrentUserEmail() {
	return mCurrentStaff->getEmail();
}
