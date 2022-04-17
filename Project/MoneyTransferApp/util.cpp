//
// Created by Andriy Bobchuk on 4/2/2022.
//

#include "util.h"
#include "PaymentService.h"


bool isPasswordSecure(std::string password) {

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

    std::regex validEmailPattern("([a-zA-Z0-9.]+@[a-zA-Z]+\\.[a-zA-Z.]{2,})");

    if (!std::regex_match(email, validEmailPattern)) {
        return false;
    }
    else {
        return true;
    }
}

bool isLoginUnique(std::string username, std::string email) {

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

bool isAccessCodeValid(std::string accessCode) {

    std::vector<std::string> accessCodes{
    "5LTLx?.]",
    "s~]Tz#3q",
    "p3tA:&'<",
    "}Hz9(&$a"
    };

    if (std::find(
        accessCodes.begin(), 
        accessCodes.end(), 
        accessCode) != accessCodes.end()){
        return true;
    }
    return true;
}
