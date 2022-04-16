#pragma once

#include <string>
#include <iostream>

class BaseUser {

    int mId;
    std::string mUsername;
    std::string mPassword;
    std::string mEmail;

public:
    int getId();

    void setId(int mId);

    const std::string& getUsername();

    void setUsername(const std::string& mUsername);

    const std::string& getPassword();

    void setPassword(const std::string& mPassword);

    const std::string& getEmail();

    void setEmail(const std::string& mEmail);

    BaseUser(int id, std::string username, std::string password, std::string email);





};



