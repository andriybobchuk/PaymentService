#pragma once
#include "DebitAccount.h"
#include "CreditAccount.h"
#include "BaseUser.h"

#include <vector>
class Client : public BaseUser {

	std::vector<int> mDebitAccounts{};
	std::vector<int> mCreditAccounts{};

public:

	Client(
		int id,
		std::string username,
		std::string password,
		std::string email
	);

	Client(
		int id,
		std::string username,
		std::string password,
		std::string email,
		std::vector<int> debitAccounts,
		std::vector<int> creditAccounts
	);

	[[nodiscard]] std::vector<int>& getDebitAccounts();

	void setDebitAccounts(const std::vector<int>& mDebitAccounts);

	[[nodiscard]] std::vector<int>& getCreditAccounts();

	void setCreditAccounts(const std::vector<int>& mCreditAccounts);

	friend std::ostream& operator<<(std::ostream& os, Client& client);

};

