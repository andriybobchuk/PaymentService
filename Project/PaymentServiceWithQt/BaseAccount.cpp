#include "BaseAccount.h"

#include <utility>

BaseAccount::BaseAccount(int uid, std::string currency, double amount, std::string status) {
    mUid = uid;
    mCurrency = currency;
    mAmount = amount;
    mStatus = status;
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