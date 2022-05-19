#include "DebitAccount.h"

DebitAccount::DebitAccount(
    int uid,
    std::string currency,
    double amount,
    std::string status,
    double depositRate) : BaseAccount(uid, currency, amount, status) {
    mDepositRate = depositRate;
}

double DebitAccount::getDepositRate() {
    return mDepositRate;
}

std::ostream& operator<<(std::ostream& os, DebitAccount& debitAccount) {
    os
        << "{\"uid\":" << debitAccount.getUid()
        << ",\"currency\":\"" << debitAccount.getCurrency()
        << "\",\"amount\":" << debitAccount.getAmount()
        << ",\"status\":\"" << debitAccount.getStatus()
        << "\",\"depositRate\":" << debitAccount.getDepositRate()
        << "}";
    return os;
}

double DebitAccount::getDepositRate() const {
    return mDepositRate;
}

void DebitAccount::setDepositRate(double mDepositRate) {
    DebitAccount::mDepositRate = mDepositRate;
}
