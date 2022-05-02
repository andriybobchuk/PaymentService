#include "CreditAccount.h"

CreditAccount::CreditAccount(int id, std::string currency, double amount, double loanRate) : BaseAccount(id, currency, amount) {
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
        << "{\"id\":" << creditAccount.getId()
        << ",\"currency\":\"" << creditAccount.getCurrency()
        << "\",\"amount\":" << creditAccount.getAmount()
        << ",\"depositRate\":" << creditAccount.getLoanRate()
        << "}";
    return os;
}
