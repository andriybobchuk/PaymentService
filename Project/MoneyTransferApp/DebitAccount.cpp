#include "DebitAccount.h"

DebitAccount::DebitAccount(int id, std::string currency, double amount, double depositRate) : BaseAccount(id, currency, amount) {
    mDepositRate = depositRate;
}

double DebitAccount::getDepositRate() {
    return mDepositRate;
}

std::ostream& operator<<(std::ostream& os, DebitAccount& debitAccount) {
    os
        << "{\"id\":" << debitAccount.getId()
        << ",\"currency\":\"" << debitAccount.getCurrency()
        << "\",\"amount\":" << debitAccount.getAmount()
        << ",\"depositRate\":" << debitAccount.getDepositRate()
        << "}";
    return os;
}

double DebitAccount::getDepositRate() const {
    return mDepositRate;
}

void DebitAccount::setDepositRate(double mDepositRate) {
    DebitAccount::mDepositRate = mDepositRate;
}
