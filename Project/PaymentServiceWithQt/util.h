//
// Created by Andriy Bobchuk on 4/2/2022.
//

#ifndef CLIONPROJECTMODEL_UTIL_H
#define CLIONPROJECTMODEL_UTIL_H


#include <string>
#include <regex>
//#include "PaymentService.h"

//PaymentService* paymentService = PaymentService::getInstance();

// Constants used across the whole project
static const std::string PENDING_APPROVAL = "pending approval";
static const std::string APPROVED = "approved";


bool isPasswordSecure(std::string password);

bool isEmailValid(std::string email);

bool isLoginUnique(std::string username, std::string email);

bool isAccessCodeValid(std::string accessCode);


#endif //CLIONPROJECTMODEL_UTIL_H
