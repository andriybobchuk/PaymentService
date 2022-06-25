#pragma once

#include <string>
#include <variant>
#include "Staff.h"
#include "PaymentService.h"
#include "constants.h"
#include "util.h"



class StaffController
{
private:
	Staff* mCurrentStaff;

public:
	StaffController(Staff* currentStaff);

	std::vector<std::vector<std::string>> getAllUsers();

	bool isClientApproved(int id);

	// void approveClientById(int id);
	// void banClientById(int id);
	void changeClientStatus(int clientId, std::string newStatus);



	std::vector<std::vector<std::string>> getAllAccounts();

	bool isAccountApproved(int id);

	// void approveAccountById(int id);
	// void banAccountById(int id);
	void changeAccountStatus(int accountId, std::string newStatus);



	std::string getCurrentUserEmail();
};

