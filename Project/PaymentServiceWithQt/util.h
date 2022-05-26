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


void save();

void read();


#endif //CLIONPROJECTMODEL_UTIL_H
