#include "BaseUser.h"

BaseUser::BaseUser(std::string username, std::string password, std::string email) {
    mUsername = username;
    mPassword = password;
    mEmail = email;
}

const std::string& BaseUser::getUsername() {
    return mUsername;
}

void BaseUser::setUsername(const std::string& mUsername) {
    BaseUser::mUsername = mUsername;
}

const std::string& BaseUser::getPassword() {
    return mPassword;
}

void BaseUser::setPassword(const std::string& mPassword) {
    BaseUser::mPassword = mPassword;
}

const std::string& BaseUser::getEmail() {
    return mEmail;
}

void BaseUser::setEmail(const std::string& mEmail) {
    BaseUser::mEmail = mEmail;
}
