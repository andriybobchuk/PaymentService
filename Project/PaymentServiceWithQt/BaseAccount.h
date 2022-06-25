#pragma once
#include <string>
#include <iostream>
#include <vector>
//#include "util.h"

class BaseAccount {

	int mUid;
	std::string mCurrency;
	double mAmount;
	std::string mStatus;
	std::string mLastBalanceRecalculation;
	

public:

	virtual std::vector<std::string> toStringVector() = 0;

	virtual std::string getType() = 0;

	const int getUid() const;

	void setUid(const int mUid);

	const std::string& getCurrency() const;

	void setCurrency(const std::string& mCurrency);

	double getAmount() const;

	void setAmount(double mAmount);

	std::string getStatus() const;

	void setStatus(const std::string& mStatus);

	std::string getLastBalanceRecalculation() const;

	void setLastBalanceRecalculation(const std::string& mLastBalanceRecalculation);

	std::vector<std::string> toString();

	bool send(BaseAccount& beneficiary, double amount);

public:
	BaseAccount(
		int uid, 
		std::string currency, 
		double amount, 
		std::string status,
		std::string lastRecalculation
	);

	std::string getCurrency();

	[[nodiscard]] double getAmount();
};


