#include "BaseAccount.h"

#include <utility>
#include "util.h"


BaseAccount::BaseAccount(int uid, std::string currency, double amount, std::string status, std::string lastRecalculation) {
    mUid = uid;
    mCurrency = currency;
    mAmount = amount;
    mStatus = status;
    mLastBalanceRecalculation = lastRecalculation;
}

std::string BaseAccount::getCurrency() {
    return mCurrency;
}

double BaseAccount::getAmount() {
    return mAmount;
}

const int BaseAccount::getUid() const {
    return mUid;
}

void BaseAccount::setUid(const int mUid)
{
    BaseAccount::mUid = mUid;
}

const std::string& BaseAccount::getCurrency() const {
    return mCurrency;
}

void BaseAccount::setCurrency(const std::string& mCurrency) {
    BaseAccount::mCurrency = mCurrency;
}

double BaseAccount::getAmount() const {
    return mAmount;
}

void BaseAccount::setAmount(double mAmount) {
    BaseAccount::mAmount = mAmount;
}

std::string BaseAccount::getStatus() const{
    return mStatus;
}

void BaseAccount::setStatus(const std::string& mStatus) {
    BaseAccount::mStatus = mStatus;
}

std::string BaseAccount::getLastBalanceRecalculation() const{
    return mLastBalanceRecalculation;
}

void BaseAccount::setLastBalanceRecalculation(const std::string& mLastBalanceRecalculation) {
    BaseAccount::mLastBalanceRecalculation = mLastBalanceRecalculation;
}

std::vector<std::string> BaseAccount::toString() {
    return {
       std::to_string(getUid()),
       (getCurrency() + " " + doubleToString(getAmount())),
       getStatus(),
       getType()
    };
}

bool BaseAccount::send(BaseAccount& beneficiary, double amount) {

    ////if(exists(getCurrentDebitAccount()[0]))
    if (BaseAccount::getAmount() >= amount) {

        if (beneficiary.getCurrency() == getCurrency()) {

            // add money to recipient
            beneficiary.setAmount(beneficiary.getAmount() + amount);

            // substract money from sender
            setAmount(getAmount() - amount);

            return true;
        }
    }
    return false;
}
