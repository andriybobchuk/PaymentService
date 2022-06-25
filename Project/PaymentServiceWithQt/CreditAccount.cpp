#include "CreditAccount.h"
#include "util.h"



CreditAccount::CreditAccount(
    int uid, 
    std::string currency, 
    double amount, 
    std::string status,
    std::string lastRecalculation
) : BaseAccount(uid, currency, amount, status, lastRecalculation) {
}

std::string CreditAccount::getType() {
    return CREDIT_ACCOUNT;
}

std::ostream& operator<<(std::ostream& os, CreditAccount& creditAccount) {
    os
        << "{\"uid\":" << creditAccount.getUid()
        << ",\"currency\":\"" << creditAccount.getCurrency()
        << "\",\"amount\":" << creditAccount.getAmount()
        << ",\"status\":\"" << creditAccount.getStatus()
        << "\",\"lastRecalculation\":\"" << creditAccount.getLastBalanceRecalculation()
        << "\"}";
    return os;
}

std::vector<std::string> CreditAccount::toStringVector() {

    return {

       std::to_string(getUid()),
       getCurrency(),
       doubleToString(getAmount()),
       CREDIT_ACCOUNT,
       getStatus(),
       getType()
    
    };

}
