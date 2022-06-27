#pragma once

#include "Client.h"
#include "util.h"
#include <variant>
#include <sstream>
#include <chrono>
#include <time.h>
#include <cmath>
#include <ranges>

class ClientController
{
private:
	std::shared_ptr<BaseAccount> mCurrentAccount;
	Client* mCurrentClient;

public:
	ClientController(Client* currentClient);

	~ClientController();

	std::vector <std::shared_ptr<BaseAccount>> getAllBaseAccounts();
	std::vector <std::vector<std::string>> getMyBaseAccounts();
	std::vector <std::vector<std::string>> getAllAccounts();

	void setCurrentAccount(std::string uid);

	std::shared_ptr<BaseAccount> getCurrentAccount();

	std::vector<std::string> getCurrentStringAccount();

	bool isCreditAccount(int uid);

	bool addOwner(std::string email);

	void recalculateDepositBalance(std::shared_ptr<BaseAccount> account);

	bool recalculateCreditBalance(std::shared_ptr<BaseAccount> account);
	
	void createAccount(std::string type, std::string currency);

	bool recalculationSuccessful();

	bool exists(int id);

	bool suspendAccount();

	bool sendMoney(int recipientAccountUid, double amount);

	std::string getCurrentUserEmail();

};

