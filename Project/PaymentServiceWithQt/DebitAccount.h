#pragma once
#include "BaseAccount.h"

class DebitAccount : public BaseAccount {

	double mDepositRate;

public:
	double getDepositRate() const;

	void setDepositRate(double mDepositRate);

	DebitAccount(
		int uid,
		std::string currency,
		double amount,
		std::string status,
		double depositRate
		
	);

	double getDepositRate();

	friend std::ostream& operator<<(std::ostream& os, DebitAccount& debitAccount);

};

