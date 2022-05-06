//
// Created by Andriy Bobchuk on 4/2/2022.
//

#ifndef CLIONPROJECTMODEL_CONTROLLER_H
#define CLIONPROJECTMODEL_CONTROLLER_H


#include <string>
#include "PaymentService.h"
#include "util.h"

//PaymentService* paymentService = PaymentService::getInstance();

//BaseUser currentUser; // strores an instance of a current user, wheather it's a client or a staff member.


bool signUp(
    std::string username,
    std::string password,
    std::string email
);

bool signInClient(std::string login, std::string password);

bool signInStaff(std::string login, std::string password);

void approveClientById(int id);

void safelyEndSession();


#endif //CLIONPROJECTMODEL_CONTROLLER_H
