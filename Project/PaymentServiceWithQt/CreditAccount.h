#pragma once
#include "BaseAccount.h"


class CreditAccount : public BaseAccount {

	double mLoanRate;

public:

	CreditAccount(
		int uid,
		std::string currency,
		double amount,
		std::string status,
		double loanRate
	);

	void setLoanRate(double mLoanRate);

	double getLoanRate() const;

	friend std::ostream& operator<<(std::ostream& os, CreditAccount& creditAccount);

};

