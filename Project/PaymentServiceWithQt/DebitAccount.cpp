#include "DebitAccount.h"
#include "util.h"


std::string DebitAccount::getType()
{
    return DEBIT_ACCOUNT;
}

DebitAccount::DebitAccount(
    int uid,
    std::string currency,
    double amount,
    std::string status,
    std::string lastRecalculation
    ) : BaseAccount(uid, currency, amount, status, lastRecalculation) {
}


std::ostream& operator<<(std::ostream& os, DebitAccount& debitAccount) {
    os
        << "{\"uid\":" << debitAccount.getUid()
        << ",\"currency\":\"" << debitAccount.getCurrency()
        << "\",\"amount\":" << debitAccount.getAmount()
        << ",\"status\":\"" << debitAccount.getStatus()
        << "\",\"lastRecalculation\":\"" << debitAccount.getLastBalanceRecalculation()
        << "\"}";
    return os;
}

std::vector<std::string> DebitAccount::toStringVector() {

    return {

       std::to_string(getUid()),
       getCurrency(),
       doubleToString(getAmount()),
       DEBIT_ACCOUNT,
       getStatus(),
       getType()

    };

}
