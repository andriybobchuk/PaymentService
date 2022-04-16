#include "Client.h"

Client::Client(int id, std::string username, std::string password, std::string email) : BaseUser(id, username, password, email) {

}

Client::Client(int id, std::string username, std::string password, std::string email, std::vector<int> debitAccounts,
    std::vector<int> creditAccounts) : BaseUser(id, username, password, email) {

    for (auto element : debitAccounts)
        mDebitAccounts.push_back(element);
    for (auto element : creditAccounts)
        mCreditAccounts.push_back(element);
}

std::vector<int>& Client::getDebitAccounts() {
    return mDebitAccounts;
}

void Client::setDebitAccounts(const std::vector<int>& mDebitAccounts) {
    Client::mDebitAccounts = mDebitAccounts;
}

std::vector<int>& Client::getCreditAccounts() {
    return mCreditAccounts;
}

void Client::setCreditAccounts(const std::vector<int>& mCreditAccounts) {
    Client::mCreditAccounts = mCreditAccounts;
}

std::ostream& operator<<(std::ostream& os, Client& client) {
    os
        << "{\"id\":" << client.getId()
        << ",\"username\":\"" << client.getUsername()
        << "\",\"email\":\"" << client.getEmail()
        << "\",\"password\":\"" << client.getPassword()
        << "\",\"debitAccounts\":[";
    for (int i = 0; i < client.getDebitAccounts().size(); i++) {
        os << client.getDebitAccounts().at(i);
        if (i < client.getDebitAccounts().size() - 1) {
            os << ",";
        }
    }
    os << "],\"creditAccounts\":[";
    for (int i = 0; i < client.getCreditAccounts().size(); i++) {
        os << client.getCreditAccounts().at(i);
        if (i < client.getCreditAccounts().size() - 1) {
            os << ",";
        }
    }
    os << "]";
    os << "}";
    return os;
}
