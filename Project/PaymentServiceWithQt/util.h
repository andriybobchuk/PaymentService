//
// Created by Andriy Bobchuk on 4/2/2022.
//

#ifndef CLIONPROJECTMODEL_UTIL_H
#define CLIONPROJECTMODEL_UTIL_H


#include <string>
#include <regex>
#include "database.h"
#include "constants.h"
#include "PaymentService.h"



bool isPasswordSecure(std::string password);

bool isEmailValid(std::string email);

bool isLoginUnique(std::string username, std::string email);

/// <summary>
/// Generates primary key for accounts.
/// </summary>
/// <returns></returns>
int getNewAccountUid();


void pushToDatabase();

void pullFromDatabase();

inline double round(double val);


unsigned int stringToHashFunction(std::string string);

std::string unsignedIntToHex(unsigned int input);

std::string passwordToHash(std::string password);

bool comparePasswordToHash(std::string password, std::string hash);


#endif //CLIONPROJECTMODEL_UTIL_H
