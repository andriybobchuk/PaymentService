#include "EntryController.h"




EntryController::EntryController(QWidget* parent) : mParentWidget(parent) {

    std::future<bool> backgroungThread = std::async(std::launch::async, createDatabaseBackup);
    std::future_status status;

    if (status == std::future_status::ready) {
        // Backup is ready
    }

    pullFromDatabase();
    int test = getNewAccountUid();
}



bool EntryController::signUpClient(std::string username, std::string password, std::string email) {

    pullFromDatabase(); // Making sure to get the latest saved data

    if (Reservation::reserve(email)) {

        pushToDatabase(); // push a new reserved email, so that while we register a new user no one will interfere

        PaymentService::getInstance()->addClient(Client(username, passwordToHash(password), email)); // Adding a new client
        
        Reservation::complete(email);

        pushToDatabase(); // push a db with new registered user and cleared list of reserved users

        return true;
    }

    return false;
}

bool EntryController::signInClient(std::string login, std::string password) {

    pullFromDatabase(); // Making sure to get the latest saved data
    
    Client* currentLoggedInClient{};
    for (auto& client : PaymentService::getInstance()->getClients()) {
        if (
            client.getEmail() == login || client.getUsername() == login

            && comparePasswordToHash(password, client.getPassword())

            && client.getStatus() == APPROVED
            
            ) {

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

    pullFromDatabase(); // Making sure to get the latest saved data

    Staff* currentLoggedInStaff{};
    for (auto& staff : PaymentService::getInstance()->getStaff()) {
        if (
            staff.getEmail() == login || staff.getUsername() == login
            
            && comparePasswordToHash(password, staff.getPassword())
            
            ) {
            currentLoggedInStaff = &staff;
        }
    }

    if (!currentLoggedInStaff) { return false; }

    StaffController* staffController = new StaffController(currentLoggedInStaff);
    StaffForm* staffForm = new StaffForm(mParentWidget, staffController);
    staffForm->show();

    return true;
}


