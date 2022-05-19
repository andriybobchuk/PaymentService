//
// Created by Andriy Bobchuk on 4/2/2022.
//

#ifndef CLIONPROJECTMODEL_UTIL_H
#define CLIONPROJECTMODEL_UTIL_H


#include <string>
#include <regex>


bool isPasswordSecure(std::string password);

bool isEmailValid(std::string email);

bool isLoginUnique(std::string username, std::string email);

/// <summary>
/// Generates primary key for accounts.
/// </summary>
/// <returns></returns>
int getNewAccountUid();


#endif //CLIONPROJECTMODEL_UTIL_H
