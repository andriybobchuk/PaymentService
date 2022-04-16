#include "Staff.h"

Staff::Staff(int id, std::string username, std::string password, std::string email, std::string position) : BaseUser(id, username, password, email) {
    mPosition = position;
}

std::ostream& operator<<(std::ostream& os, Staff& staff) {
    os
        << "{\"id\":" << staff.getId()
        << ",\"username\":\"" << staff.getUsername()
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
