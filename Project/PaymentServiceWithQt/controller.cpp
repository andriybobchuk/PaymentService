//
// Created by Andriy Bobchuk on 4/2/2022.
//

#include "controller.h"
#include "database.h"
#include "constants.h"

BaseUser currentUser;

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

bool signInClient(std::string login, std::string password) {

    PaymentService::setInstance(0);
    deserialize(DATABASE_FILE, PaymentService::getInstance());

    for (auto client : PaymentService::getInstance()->getClients()) {
        if (client.getEmail() == login || client.getUsername() == login
            && client.getPassword() == password
            && client.getStatus() == APPROVED) {

            currentUser = client;
            return true;
        }
    }
    return false;
}

bool signInStaff(std::string login, std::string password) {

    PaymentService::setInstance(0);
    deserialize(DATABASE_FILE, PaymentService::getInstance());

    for (auto staff : PaymentService::getInstance()->getStaff()) {
        if (staff.getEmail() == login || staff.getUsername() == login
            && staff.getPassword() == password) {

            currentUser = staff;
            return true;
        }
    }
    return false;
}

void approveClientById(int id) {
    PaymentService::getInstance()->getClients().at(id).setStatus(APPROVED);
}

void safelyEndSession() {
    serializeToDb(DATABASE_FILE, PaymentService::getInstance());
    //PaymentService::setInstance(0);
}

