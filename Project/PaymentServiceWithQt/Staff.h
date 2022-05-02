#pragma once
#include "BaseUser.h"

class Staff : public BaseUser {

	std::string mPosition;

public:
	std::string& getPosition();

	void setPosition(const std::string& mPosition);

	Staff(
		std::string username,
		std::string password,
		std::string email,
		std::string position
	);


	friend std::ostream& operator<<(std::ostream& os, Staff& staff);

};

