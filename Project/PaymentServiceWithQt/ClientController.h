#pragma once

#include "Client.h"
#include "util.h"

class ClientController
{
private:
	Client* mCurrentClient;
	DebitAccount* mCurrentDebitAccount;

public:
	ClientController(Client* currentClient);

	void setCurrentDebitAccount(std::string uid);

	std::vector<std::string> getCurrentDebitAccount();

	// To be implemented
	std::vector<std::vector<std::string>> getAllAccounts();
//	bool isAccountApproved(int id);
	//void approveAccountById(int id);
	//void banAccountById(int id);


	void createDebitAccount(std::string currency);

	void createCreditAccount(std::string currency, double amount);


	//pb_suspend
	void suspendDebitAccount();
	void suspendCreditAccount();


	bool sendMoney(std::string recipientAccountUid, double amount);




	std::string getCurrentUserEmail();

};

