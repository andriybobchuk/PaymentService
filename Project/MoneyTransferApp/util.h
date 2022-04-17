//
// Created by Andriy Bobchuk on 4/2/2022.
//

#ifndef CLIONPROJECTMODEL_UTIL_H
#define CLIONPROJECTMODEL_UTIL_H


#include <string>
#include <regex>
//#include "PaymentService.h"

//PaymentService* paymentService = PaymentService::getInstance();


bool isPasswordSecure(std::string password);

bool isEmailValid(std::string email);

bool isLoginUnique(std::string username, std::string email);

bool isAccessCodeValid(std::string accessCode);


#endif //CLIONPROJECTMODEL_UTIL_H
