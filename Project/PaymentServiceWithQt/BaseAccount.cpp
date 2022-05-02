#include "BaseAccount.h"

#include <utility>

BaseAccount::BaseAccount(int id, std::string currency, double amount) {
    mId = id;
    mCurrency = std::move(currency);
    mAmount = amount;
}

int BaseAccount::getId() {
    return mId;
}

std::string BaseAccount::getCurrency() {
    return mCurrency;
}

double BaseAccount::getAmount() {
    return mAmount;
}

int BaseAccount::getId() const {
    return mId;
}

void BaseAccount::setId(int mId) {
    BaseAccount::mId = mId;
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
