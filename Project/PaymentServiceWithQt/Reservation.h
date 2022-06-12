#pragma once
#include <string>
#include "database.h"
#include "PaymentService.h"
#include<windows.h>

class Reservation
{
public:
	static bool reserve(std::string username);

	static bool complete(std::string username);
};

