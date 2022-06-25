#pragma once
#include "BaseAccount.h"
#include "constants.h"
//#include "util.h"


class CreditAccount : public BaseAccount {

public:

	std::string getType();

	CreditAccount(
		int uid,
		std::string currency,
		double amount,
		std::string status,
		std::string lastRecalculation
	);

	friend std::ostream& operator<<(std::ostream& os, CreditAccount& creditAccount);

	std::vector<std::string> toStringVector();

};

