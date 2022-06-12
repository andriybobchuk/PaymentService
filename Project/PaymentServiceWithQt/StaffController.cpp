#include "StaffController.h"


StaffController::StaffController(Staff* currentStaff) : mCurrentStaff(currentStaff) {}



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

void StaffController::approveClientById(int id) {
	PaymentService::getInstance()->getClients().at(id).setStatus(APPROVED);
}

void StaffController::banClientById(int id) {
	PaymentService::getInstance()->getClients().at(id).setStatus(BANNED);
}



/* =========================================================================================================== *
							  ACCOUNTS TAB
*  =========================================================================================================== */

std::vector<std::vector<std::string>> StaffController::getAllAccounts() {

	std::vector<std::vector<std::string>> accounts;

	int it = 0;
	for (auto& account : PaymentService::getInstance()->getDebitAccounts()) {

		accounts.push_back(
			{
				std::to_string(it),
				std::to_string(account.getUid()),
				account.getCurrency(),
				std::to_string(round(account.getAmount() * 100.0) / 100.0),
				DEBIT_ACCOUNT,
				std::to_string(round(account.getDepositRate() * 100.0) / 100.0),
				account.getStatus(),
			}
		);

		it++;
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

void StaffController::approveAccountById(int id) {

	// to be implemented

	//PaymentService::getInstance()->getClients().at(id).setStatus(APPROVED);
}

void StaffController::banAccountById(int id) {

	// to be implemented

	//PaymentService::getInstance()->getClients().at(id).setStatus(BANNED);
}




/* =========================================================================================================== *
							  MORE TAB
*  =========================================================================================================== */

std::string StaffController::getCurrentUserEmail() {
	return mCurrentStaff->getEmail();
}
