#pragma once
#include <string>
#include <iostream>

class BaseAccount {

	int mUid;
	std::string mCurrency;
	double mAmount;
	std::string mStatus;

public:

	const int getUid() const;

	void setUid(const int mUid);

	const std::string& getCurrency() const;

	void setCurrency(const std::string& mCurrency);

	double getAmount() const;

	void setAmount(double mAmount);

	std::string getStatus() const;

	void setStatus(const std::string& mStatus);

public:
	BaseAccount(
		int uid, 
		std::string currency, 
		double amount, 
		std::string status
	);

	std::string getCurrency();

	[[nodiscard]] double getAmount();
};


