#pragma once
#include <string>
#include <iostream>

class BaseAccount {

	int mId;
	std::string mCurrency;
	double mAmount;
public:
	int getId() const;

	void setId(int mId);

	const std::string& getCurrency() const;

	void setCurrency(const std::string& mCurrency);

	double getAmount() const;

	void setAmount(double mAmount);

public:
	BaseAccount(int id, std::string currency, double amount);

	[[nodiscard]] int getId();

	std::string getCurrency();

	[[nodiscard]] double getAmount();
};


