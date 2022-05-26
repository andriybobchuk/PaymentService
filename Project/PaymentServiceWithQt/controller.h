//
// Created by Andriy Bobchuk on 4/2/2022.
//

#ifndef CLIONPROJECTMODEL_CONTROLLER_H
#define CLIONPROJECTMODEL_CONTROLLER_H


#include <string>
#include "PaymentService.h"
#include "util.h"
#include "database.h"
#include "constants.h"

//PaymentService* paymentService = PaymentService::getInstance();

//BaseUser currentUser; // strores an instance of a current user, wheather it's a client or a staff member.


bool signUp(
    std::string username,
    std::string password,
    std::string email
);

// Clients management

Client* signInClient(std::string login, std::string password);

Staff* signInStaff(std::string login, std::string password);








void approveClientById(int id);

void banClientById(int id);

Client& getClientFromUsername(std::string username);







// Account management

bool createDebitAccount(std::string currency, double amount, Client* currentUser);

bool createCreditAccount(std::string currency, double amount, Client* currentUser);

void approveDebitAccountById(int id);

void approveCreditAccountById(int id);

void banDebitAccountById(int id);

void banCreditAccountById(int id);







// Other

void safelyEndSession();

std::string getCurrentUser();

std::string getCurrentUserEmail();

std::string getAdminEmail();

#endif //CLIONPROJECTMODEL_CONTROLLER_H
