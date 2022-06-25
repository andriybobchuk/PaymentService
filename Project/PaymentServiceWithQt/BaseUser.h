#pragma once

#include <string>
#include <iostream>

class BaseUser {

    std::string mUsername;
    std::string mPassword;
    std::string mEmail;

public:

    BaseUser();

    // &&
    //BaseUser& operator=(BaseUser&& other) noexcept;

    virtual const std::string& getUsername();

    //virtual double getInterest() {};

    void setUsername(const std::string& mUsername);

    const std::string& getPassword();

    void setPassword(const std::string& mPassword);

    const std::string& getEmail();

    void setEmail(const std::string& mEmail);

    BaseUser(std::string username, std::string password, std::string email);





};



