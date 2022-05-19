/*
 * Constants used across the whole project
 */

#pragma once
#include <string>

// Clients' and accounts' statuses
static const std::string PENDING_APPROVAL = "pending approval";
static const std::string APPROVED = "approved";
static const std::string BANNED = "banned";

// Serialization File
static const std::string DATABASE_FILE = "database.txt";

// Standard load/deposit rates in my bank
static const double DEPOSIT_RATE = 0.05;
static const double LOAN_RATE = 4.5;

// Types of accounts fro spinners
static const std::string DEBIT_ACCOUNT = "debit";
static const std::string CREDIT_ACCOUNT = "credit";
