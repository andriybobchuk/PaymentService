#include "BaseUser.h"

BaseUser::BaseUser() = default;

BaseUser::BaseUser(std::string username, std::string password, std::string email) {
    mUsername = username;
    mPassword = password;
    mEmail = email;
}

// move assignment
//BaseUser& BaseUser::operator=(BaseUser&& other) noexcept
//{
//    mUsername = std::move(other.getUsername());
//    mPassword = std::move(other.getPassword());
//    mEmail = std::move(other.getEmail());
//    return *this;
//}

//BaseUser::BaseUser& operator=(BaseUser::BaseUser&& other)
//{
//    // Guard self assignment
//    if (this == &other)
//        return *this; // delete[]/size=0 would also be ok
//
//    delete[] mArray;                               // release resource in *this
//    mArray = std::exchange(other.mArray, nullptr); // leave other in valid state
//    size = std::exchange(other.size, 0);
//    return *this;
//}

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
