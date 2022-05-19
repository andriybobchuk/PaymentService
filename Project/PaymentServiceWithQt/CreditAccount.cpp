#include "CreditAccount.h"

CreditAccount::CreditAccount(
    int uid, 
    std::string currency, 
    double amount, 
    std::string status,
    double loanRate
) : BaseAccount(uid, currency, amount, status) {
    mLoanRate = loanRate;
}

double CreditAccount::getLoanRate() const {
    return mLoanRate;
}

void CreditAccount::setLoanRate(double mLoanRate) {
    CreditAccount::mLoanRate = mLoanRate;
}

std::ostream& operator<<(std::ostream& os, CreditAccount& creditAccount) {
    os
        << "{\"uid\":" << creditAccount.getUid()
        << ",\"currency\":\"" << creditAccount.getCurrency()
        << "\",\"amount\":" << creditAccount.getAmount()
        << ",\"status\":\"" << creditAccount.getStatus()
        << "\",\"loanRate\":" << creditAccount.getLoanRate()
        << "}";
    return os;
}
