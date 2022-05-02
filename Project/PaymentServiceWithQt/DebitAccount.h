#pragma once
#include "BaseAccount.h"

class DebitAccount : public BaseAccount {

	double mDepositRate;

public:
	double getDepositRate() const;

	void setDepositRate(double mDepositRate);

	DebitAccount(
		int id,
		std::string currency,
		double amount,
		double depositRate
	);

	double getDepositRate();

	friend std::ostream& operator<<(std::ostream& os, DebitAccount& debitAccount);

};

