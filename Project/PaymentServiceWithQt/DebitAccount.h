#pragma once
#include "BaseAccount.h"
#include "constants.h"
//#include "util.h"

class DebitAccount : public BaseAccount {

public:

	std::string getType();

	DebitAccount(
		int uid,
		std::string currency,
		double amount,
		std::string status,
		std::string lastRecalculated
		
	);

	friend std::ostream& operator<<(std::ostream& os, DebitAccount& debitAccount);

	std::vector<std::string> toStringVector();

};

