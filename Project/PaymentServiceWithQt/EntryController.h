#pragma once

#include <string>
#include "PaymentService.h"
#include "util.h"
#include "database.h"
#include "constants.h"

#include "ClientForm.h"
#include "StaffForm.h"

#include "ClientController.h"
#include "StaffController.h"


class EntryController
{
private:

	QWidget* mParentWidget = Q_NULLPTR;

public:

	EntryController(QWidget* parent = Q_NULLPTR);

	bool signUpClient(std::string username, std::string password, std::string email);

	bool signInClient(std::string login, std::string password);

	bool signInStaff(std::string login, std::string password);
};


