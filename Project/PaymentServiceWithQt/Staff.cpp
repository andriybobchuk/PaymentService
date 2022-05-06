#include "Staff.h"

Staff::Staff(
    std::string username, 
    std::string password, 
    std::string email, 
    std::string position
) : BaseUser(username, password, email) {
    mPosition = position;
}

// move assignment
//Staff& Staff::operator=(Staff&& other) noexcept
//{
//    mPosition = std::move(other.getPosition());
//    return *this;
//}

std::ostream& operator<<(std::ostream& os, Staff& staff) {
    os
        << "{\"username\":\"" << staff.getUsername()
        << "\",\"email\":\"" << staff.getEmail()
        << "\",\"password\":\"" << staff.getPassword()
        << "\",\"position\":\"" << staff.getPosition()
        << "\"}";
    return os;
}

std::string& Staff::getPosition() {
    return mPosition;
}

void Staff::setPosition(const std::string& mPosition) {
    Staff::mPosition = mPosition;
}
