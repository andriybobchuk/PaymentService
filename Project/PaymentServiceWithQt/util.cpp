//
// Created by Andriy Bobchuk on 4/2/2022.
//

#include "util.h"



bool isPasswordSecure(std::string password) {


    //todo: Remove on release
    return true;


    std::regex validPasswordPattern(
        R"(^(?=.*?[A-Z])(?=.*?[a-z])(?=.*?[0-9])(?=.*?[^ a-zA-Z0-9]).{8,}$)"
    );

    if (!std::regex_match(password, validPasswordPattern)) {
        return false;
    }
    else {
        return true;
    }
}

bool isEmailValid(std::string email) {

    //todo: Remove on release
    return true;


    std::regex validEmailPattern("([a-zA-Z0-9.]+@[a-zA-Z]+\\.[a-zA-Z.]{2,})");

    if (!std::regex_match(email, validEmailPattern)) {
        return false;
    }
    else {
        return true;
    }
}

bool isLoginUnique(std::string username, std::string email) {

    //todo: Remove on release
    return true;


    for (auto client : PaymentService::getInstance()->getClients()) {
        if (client.getUsername() == username || client.getEmail() == email) {
            return false;
        }
    }
    for (auto staff : PaymentService::getInstance()->getStaff()) {
        if (staff.getUsername() == username || staff.getEmail() == email) {
            return false;
        }
    }
    return true;
}


int getNewAccountUid() {

    int newAccountUid = 0;

    for (auto debitAccount : PaymentService::getInstance()->getDebitAccounts()) {
        if (debitAccount.getUid() > newAccountUid) {
            newAccountUid = debitAccount.getUid() + 1;
        }
    }
    for (auto creditAccount : PaymentService::getInstance()->getCreditAccounts()) {
        if (creditAccount.getUid() > newAccountUid) {
            newAccountUid = creditAccount.getUid() + 1;
        }
    }

    return newAccountUid;
}


void save() {
    serializeToDb(DATABASE_FILE, PaymentService::getInstance());
}

void read() {
    deserialize(DATABASE_FILE, PaymentService::getInstance());
}