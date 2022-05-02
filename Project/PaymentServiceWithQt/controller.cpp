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

void signInClient(std::string login, std::string password) {

    deserialize("database.txt", PaymentService::getInstance());

    for (auto client : PaymentService::getInstance()->getClients()) {
        if (client.getEmail() == login
            || client.getUsername() == login
            && client.getPassword() == password) {
            //return client;
        }
    }
}

void signInStaff(std::string login, std::string password) {

    deserialize("database.txt", PaymentService::getInstance());

    for (auto client : PaymentService::getInstance()->getClients()) {
        if (client.getEmail() == login
            || client.getUsername() == login
            && client.getPassword() == password) {
            //return client;
        }
    }
}

