//
// Created by Andriy Bobchuk on 4/2/2022.
//

#include "controller.h"
#include "database.h"

bool signUp(std::string username, std::string password, std::string email) {
    if (
        isPasswordSecure(password)
        && isEmailValid(email)
        && isLoginUnique(username, email)
        ) {
        PaymentService::getInstance()->addClient(Client(username, password, email));
        serializeToDb("database.txt", PaymentService::getInstance());
        return true;
    }
    return false;
}

bool signUp(
    std::string username, 
    std::string password, 
    std::string email, 
    std::string position,
    std::string accessCode

) {
    if (
        isPasswordSecure(password)
        && isEmailValid(email)
        && isLoginUnique(username, email)
        && isAccessCodeValid(accessCode)
        ) {
        PaymentService::getInstance()->addStaff(Staff(username, password, email, position));
        serializeToDb("database.txt", PaymentService::getInstance());
        return true;
    }
    return false;
}

bool signIn(std::string login, std::string password) {
    auto it = std::find_if(
        PaymentService::getInstance()->getClients().begin(),
        PaymentService::getInstance()->getClients().end(),
        [&login](Client& client) {
            return client.getUsername() == login
                || client.getEmail() == login;
        });

    if (it != PaymentService::getInstance()->getClients().end()) {
        // found element. it is an iterator to the first matching element.
        if (it->getPassword() == password) {
            // notify the UI
            return true;
        }
    }
    auto itr = std::find_if(
        PaymentService::getInstance()->getStaff().begin(),
        PaymentService::getInstance()->getStaff().end(),
        [&login](Staff& staff) {
            return staff.getUsername() == login
                || staff.getEmail() == login;
        });

    if (itr != PaymentService::getInstance()->getStaff().end()) {
        // found element. it is an iterator to the first matching element.
        if (itr->getPassword() == password) {
            // notify the UI
            return true;
        }
    }
    return false;
}

