#include "Staff.h"

Staff::Staff() = default;

Staff::Staff(
    std::string username, 
    std::string password, 
    std::string email, 
    std::string position
) : BaseUser(username, password, email) {
    mPosition = position;
}

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
