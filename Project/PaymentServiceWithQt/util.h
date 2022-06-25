//
// Created by Andriy Bobchuk on 4/2/2022.
//

#ifndef CLIONPROJECTMODEL_UTIL_H
#define CLIONPROJECTMODEL_UTIL_H


#include <string>
#include <regex>
#include <ranges>
#include <sstream>
#include <iomanip>
#include <filesystem>
#include "database.h"
#include "constants.h"
#include "PaymentService.h"



bool isPasswordSecure(std::string password);

bool isEmailValid(std::string email);

bool isTransferAmountValid(std::string amount);

int getNewAccountUid();

void pushToDatabase();

void pullFromDatabase();

unsigned int stringToHashFunction(std::string string);

std::string unsignedIntToHex(unsigned int input);

std::string passwordToHash(std::string password);

bool comparePasswordToHash(std::string password, std::string hash);

std::string doubleToString(double number);

void createDatabaseBackup();


struct Date {
    int d, m, y;
};

// To store number of days in
// all months from January to Dec.
const int monthDays[12]
= { 31, 28, 31, 30, 31, 30,
   31, 31, 30, 31, 30, 31 };

// This function counts number of
// leap years before the given date
int countLeapYears(Date d);

// This function returns number of
// days between two given dates
int getDifference(Date dt1, Date dt2);


Date stringToDate(const std::string& s, char delim);

double compoundInterest(double principal, double interestRate, int days);

double loanInterest(double principal, double interestRate, int days);

std::string getCurrentDate();

std::string getCurrentDateAndTime();








#endif //CLIONPROJECTMODEL_UTIL_H
