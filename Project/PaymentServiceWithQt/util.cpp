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


void pushToDatabase() {
    serialize();
}

void pullFromDatabase() {
    PaymentService::setInstance(0); // zeroing the previous instance not to have a double data
    deserialize();
}

inline double round(double val)
{
    if (val < 0) return ceil(val - 0.5);
    return floor(val + 0.5);
}


unsigned int stringToHashFunction(std::string string) {

    unsigned int init = 156754;
    unsigned int multiplier = 987655;
    unsigned int hash = init;

    for (int i = 0; i < string.length(); i++) {
        hash = hash ^ (string[i]); // XOR each byte of string
        hash = hash * multiplier;
    }
    return hash;
}


std::string unsignedIntToHex(unsigned int input) {
    std::string hexHash;
    std::stringstream sstream;
    sstream << std::hex << input;
    hexHash = sstream.str();
    std::transform(hexHash.begin(), hexHash.end(), hexHash.begin(), ::toupper);
    return hexHash;
}


std::string passwordToHash(std::string password) {
    return unsignedIntToHex(stringToHashFunction(password));
}


bool comparePasswordToHash(std::string password, std::string hash) {
    if (passwordToHash(password) == hash) {
        return true;
    }
    return false;
}


