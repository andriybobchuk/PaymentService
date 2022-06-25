/*
 * Constants used across the whole project
 */

#pragma once
#include <string>
#include <map>

 // Database serialization file
static const std::string DATABASE_FILE_PATH = "E:/Documents/cpp_projects/polsl-aei-cp4-ang/2d98c560-gr12-repo/Project/PaymentServiceWithQt/database.txt";
static const std::string DATABASE_FILE = "database.txt";
static const std::string DATABASE_EXTENSION = ".txt";

// Clients' and accounts' statuses
static const std::string PENDING_APPROVAL = "pending approval";
static const std::string APPROVED = "approved";
static const std::string BANNED = "banned";
static const std::string SUSPENDED = "suspended";

// Currency exchange rate table (Relative to USD) 
static std::map<std::string, double> RATES = {
	{"USD", 1},
	{"PLN", 0.5},
	{"EUR", 1.1},
	{"UAH", 0.4}
};

// Standard loan/deposit rates in my bank (Per day)
static const double BASE_DEPOSIT_INTEREST = 0.03;
static const double BASE_LOAN_INTEREST = 0.07;
static const double MIN_INTEREST_FREE = 0.7;
static const double CRITICAL_AMOUNT = 0.1;

// Foreign loan/deposit rates
static const double FOREIGN_DEPOSIT_INTEREST(std::string currencyTag) {
	return BASE_DEPOSIT_INTEREST / RATES.find(currencyTag)->second;
}
static const double FOREIGN_LOAN_INTEREST(std::string currencyTag) {
	return BASE_LOAN_INTEREST / RATES.find(currencyTag)->second;
}

// Standard loan limit (In USD)
static double BASE_LOAN_LIMIT = 10000;

// Calculates loan limit for foreign currencies
static const double FOREIGN_LOAN_LIMIT(std::string currencyTag) { 
	return BASE_LOAN_LIMIT / RATES.find(currencyTag)->second;
}

// Types of accounts for spinners
static const std::string DEBIT_ACCOUNT = "debit";
static const std::string CREDIT_ACCOUNT = "credit";

// Descriptions for UI based on account types
static const std::string DEBIT_FEATURE = "You receive an interest rate every day just for \nkeeping your money in our bank";
static const std::string CREDIT_FEATURE = "You have a limit of 10K in USD equivalent. You pay loan interest \nevery day ONLY if your current balance goes below 70%";







