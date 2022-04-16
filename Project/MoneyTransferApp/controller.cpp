//
// Created by Andriy Bobchuk on 4/2/2022.
//

#include "controller.h"

void signUp(int id, std::string username, std::string password, std::string email) {
    if (
        isPasswordSecure(password)
        && isEmailValid(email)
        && isLoginUnique(username, email)
        )
        paymentService->addClient(Client(id, username, password, email));
}

void signUp(int id, std::string username, std::string password, std::string email, std::string position) {
    if (
        isPasswordSecure(password)
        && isEmailValid(email)
        && isLoginUnique(username, email)
        )
        paymentService->addStaff(Staff(id, username, password, email, position));
}

void signInClient(std::string login, std::string password) {
    auto it = std::find_if(
        paymentService->getClients().begin(),
        paymentService->getClients().end(),
        [&login](Client& client) {
            return client.getUsername() == login
                || client.getEmail() == login;
        });

    if (it != paymentService->getClients().end()) {
        // found element. it is an iterator to the first matching element.
        if (it->getPassword() == password) {
            // TODO: notify the UI
        }
    }
}

void signInStaff(std::string login, std::string password) {
    auto it = std::find_if(
        paymentService->getStaff().begin(),
        paymentService->getStaff().end(),
        [&login](Staff& staff) {
            return staff.getUsername() == login
                || staff.getEmail() == login;
        });

    if (it != paymentService->getStaff().end()) {
        // found element. it is an iterator to the first matching element.
        if (it->getPassword() == password) {
            // TODO: notify the UI
        }
    }
}
