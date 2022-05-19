//
// Created by Andriy Bobchuk on 4/2/2022.
//

#include "controller.h"



bool signUp(std::string username, std::string password, std::string email) {

    PaymentService::setInstance(0);
    deserialize(DATABASE_FILE, PaymentService::getInstance());

    if (
        isPasswordSecure(password)
        && isEmailValid(email)
        && isLoginUnique(username, email)
        ) {

        PaymentService::getInstance()->addClient(Client(username, password, email));
        serializeToDb(DATABASE_FILE, PaymentService::getInstance());
        
        return true;
    }
    return false;
}

Client* signInClient(std::string login, std::string password) {

    PaymentService::setInstance(0);
    if (!deserialize(DATABASE_FILE, PaymentService::getInstance())) {
        return nullptr;
    }

    for (auto& client : PaymentService::getInstance()->getClients()) {
        if (client.getEmail() == login || client.getUsername() == login
            && client.getPassword() == password
            && client.getStatus() == APPROVED) {

            return &client;
        }
    }
    return nullptr;
}

Staff* signInStaff(std::string login, std::string password) {

    PaymentService::setInstance(0);
    deserialize(DATABASE_FILE, PaymentService::getInstance());

    for (auto& staff : PaymentService::getInstance()->getStaff()) {
        if (staff.getEmail() == login || staff.getUsername() == login
            && staff.getPassword() == password) {

            return &staff;
        }
    }
    return nullptr;
}

void approveClientById(int id) {
    PaymentService::getInstance()->getClients().at(id).setStatus(APPROVED);
}

void banClientById(int id) {
    PaymentService::getInstance()->getClients().at(id).setStatus(BANNED);
}

bool createDebitAccount(std::string currency, double amount, Client* currentUser)
{
    int uid = getRandomUid();
    if (
        currency.size() != 0
        && amount >= 0
        ) {

        PaymentService::getInstance()->addDebitAccount(
            DebitAccount(
                uid,
                currency,
                amount,
                PENDING_APPROVAL,
                DEPOSIT_RATE)
        );

        currentUser->addDebitAccount(uid);

        return true;
    }
    return false;
}

bool createCreditAccount(std::string currency, double amount, Client* currentUser)
{
    int uid = getRandomUid();
    if (
        currency.size() != 0
        && amount >= 0
        ) {

        PaymentService::getInstance()->addCreditAccount(
            CreditAccount(
                uid,
                currency,
                amount,
                PENDING_APPROVAL,
                LOAN_RATE)
        );

        currentUser->addCreditAccount(uid);

        return true;
    }
    return false;
}

void approveDebitAccountById(int id)
{
    PaymentService::getInstance()->getDebitAccounts().at(id).setStatus(APPROVED);
}

void approveCreditAccountById(int id)
{
    PaymentService::getInstance()->getCreditAccounts().at(id).setStatus(APPROVED);
}

void banDebitAccountById(int id)
{
    PaymentService::getInstance()->getDebitAccounts().at(id).setStatus(BANNED);
}

void banCreditAccountById(int id)
{
    PaymentService::getInstance()->getCreditAccounts().at(id).setStatus(BANNED);
}

void safelyEndSession() {
    serializeToDb(DATABASE_FILE, PaymentService::getInstance());
}


