//
// Created by Andriy Bobchuk on 4/2/2022.
//

#ifndef CLIONPROJECTMODEL_CONTROLLER_H
#define CLIONPROJECTMODEL_CONTROLLER_H


#include <string>
#include "PaymentService.h"
#include "util.h"

//PaymentService* paymentService = PaymentService::getInstance();

bool signUp(
    std::string username,
    std::string password,
    std::string email
);

void signInClient(std::string login, std::string password);

void signInStaff(std::string login, std::string password);


#endif //CLIONPROJECTMODEL_CONTROLLER_H
