#include "PaymentService.h"

PaymentService* PaymentService::instance = 0;


/* Static access method. */
PaymentService* PaymentService::getInstance() {
    if (instance == 0) {
        instance = new PaymentService();
    }
    return instance;
}

void PaymentService::setInstance(PaymentService* instance) {
    PaymentService::instance = instance;
}

std::vector<Client>& PaymentService::getClients() {
    return mClients;
}

void PaymentService::setClients(const std::vector<Client>& mClients) {
    PaymentService::mClients = mClients;
}

std::vector<Staff>& PaymentService::getStaff() {
    return mStaff;
}

void PaymentService::setStaff(const std::vector<Staff>& mStaff) {
    PaymentService::mStaff = mStaff;
}

std::vector<DebitAccount>& PaymentService::getDebitAccounts() {
    return mDebitAccounts;
}

void PaymentService::setDebitAccounts(const std::vector<DebitAccount>& mDebitAccounts) {
    PaymentService::mDebitAccounts = mDebitAccounts;
}

std::vector<CreditAccount>& PaymentService::getCreditAccounts() {
    return mCreditAccounts;
}

void PaymentService::setCreditAccounts(const std::vector<CreditAccount>& mCreditAccounts) {
    PaymentService::mCreditAccounts = mCreditAccounts;
}

std::ostream& operator<<(std::ostream& os, PaymentService* paymentService) {
    os << "{\"clients\":[";
    for (int i = 0; i < paymentService->mClients.size(); i++) {
        os << paymentService->mClients.at(i);
        if (i < paymentService->mClients.size() - 1) {
            os << ",";
        }
    }
    os << "],\"staff\": [";

    for (int i = 0; i < paymentService->mStaff.size(); i++) {
        os << paymentService->mStaff.at(i);
        if (i < paymentService->mStaff.size() - 1) {
            os << ",";
        }
    }
    os << "],\"debitAccounts\": [";

    for (int i = 0; i < paymentService->mDebitAccounts.size(); i++) {
        os << paymentService->mDebitAccounts.at(i);
        if (i < paymentService->mDebitAccounts.size() - 1) {
            os << ",";
        }
    }
    os << "],\"creditAccounts\": [";

    for (int i = 0; i < paymentService->mCreditAccounts.size(); i++) {
        os << paymentService->mCreditAccounts.at(i);
        if (i < paymentService->mCreditAccounts.size() - 1) {
            os << ",";
        }
    }
    os << "]}";

    return os;
}

void PaymentService::addDebitAccount(DebitAccount debitAccount) {
    mDebitAccounts.push_back(debitAccount);
}

void PaymentService::addCreditAccount(CreditAccount creditAccount) {
    mCreditAccounts.push_back(creditAccount);
}

void PaymentService::addClient(Client client) {
    mClients.push_back(client);
}

void PaymentService::addStaff(Staff staff) {
    mStaff.push_back(staff);
}
