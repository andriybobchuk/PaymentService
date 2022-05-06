#pragma once
#include "DebitAccount.h"
#include "CreditAccount.h"
#include "BaseUser.h"

#include <vector>
class Client : public BaseUser {

	std::string mStatus;
	std::vector<int> mDebitAccounts{};
	std::vector<int> mCreditAccounts{};

public:

	Client(
		std::string username,
		std::string password,
		std::string email
	);

	Client(
		std::string username,
		std::string password,
		std::string email,
		std::string status
	);

	Client(
		std::string username,
		std::string password,
		std::string email,
		std::string status,
		std::vector<int> debitAccounts,
		std::vector<int> creditAccounts
	);

	// &&
	//Client& operator=(Client&& other) noexcept;

	const std::string& getStatus();

	void setStatus(const std::string& mPassword);

	[[nodiscard]] std::vector<int>& getDebitAccounts();

	void setDebitAccounts(const std::vector<int>& mDebitAccounts);

	[[nodiscard]] std::vector<int>& getCreditAccounts();

	void setCreditAccounts(const std::vector<int>& mCreditAccounts);

	friend std::ostream& operator<<(std::ostream& os, Client& client);

};

