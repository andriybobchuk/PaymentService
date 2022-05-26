#include "EntryController.h"



EntryController::EntryController(QWidget* parent) : mParentWidget(parent)
{
}

bool EntryController::signUpClient(std::string username, std::string password, std::string email) {

    // Todo: clearing the PaymentService here is weird
    PaymentService::setInstance(0);
    deserialize(DATABASE_FILE, PaymentService::getInstance());

    if (isPasswordSecure(password) && isEmailValid(email) && isLoginUnique(username, email)) {

        PaymentService::getInstance()->addClient(Client(username, password, email));
        serializeToDb(DATABASE_FILE, PaymentService::getInstance()); //Todo: this is also weird

        return true;
    }
    return false;
}

bool EntryController::signInClient(std::string login, std::string password) {

    PaymentService::setInstance(0);
    read();

    Client* currentLoggedInClient;
    for (auto& client : PaymentService::getInstance()->getClients()) {
        if (client.getEmail() == login || client.getUsername() == login
            && client.getPassword() == password
            && client.getStatus() == APPROVED) {

            currentLoggedInClient = &client;
        }
    }

    if (!currentLoggedInClient) { return false; }

    ClientController* clientController = new ClientController(currentLoggedInClient);
    ClientForm* clientForm = new ClientForm(mParentWidget, clientController);
    clientForm->show();

    return true;
}

bool EntryController::signInStaff(std::string login, std::string password) {

    PaymentService::setInstance(0);
    read();

    Staff* currentLoggedInStaff;
    for (auto& staff : PaymentService::getInstance()->getStaff()) {
        if (staff.getEmail() == login || staff.getUsername() == login
            && staff.getPassword() == password) {
            currentLoggedInStaff = &staff;
        }
    }

    if (!currentLoggedInStaff) { return false; }

    StaffController* staffController = new StaffController(currentLoggedInStaff);
    StaffForm* staffForm = new StaffForm(mParentWidget, staffController);
    staffForm->show();

    return true;
}


