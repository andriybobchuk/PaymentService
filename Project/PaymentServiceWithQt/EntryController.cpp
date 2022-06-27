#include "EntryController.h"




EntryController::EntryController(QWidget* parent) : mParentWidget(parent) {

    std::future<bool> backgroungThread = std::async(std::launch::async, createDatabaseBackup);
    std::future_status status;
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

    
    if (DEBUG_MODE) {

        // UNOPTIMAL WAY
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
        
    }
    else {

        // OPTIMAL WAY
        auto clients = PaymentService::getInstance()->getClients();
        auto it = std::ranges::find_if(

            clients.begin(),
            clients.end(),
            [login, password](Client& client) {
                return (
                    login == client.getEmail()
                    && comparePasswordToHash(password, client.getPassword())
                    && client.getStatus() == APPROVED
                    );
            });

        if (clients.end() != it) {
            currentLoggedInClient = &(*it);
        }
        else {
            return false;
        }
        
    }


    // ClientController* clientController = new ClientController(currentLoggedInClient);
    std::shared_ptr<ClientController> clientController = std::make_shared<ClientController>(currentLoggedInClient);

    //ClientForm* clientForm = new ClientForm(mParentWidget, clientController);
    mClientForm = std::make_shared<ClientForm>(mParentWidget, clientController);
    mClientForm->show();

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

    // StaffController* staffController = new StaffController(currentLoggedInStaff);
    std::shared_ptr<StaffController> staffController = std::make_shared<StaffController>(currentLoggedInStaff);

    // StaffForm* staffForm = new StaffForm(mParentWidget, staffController);
    mStaffForm = std::make_shared<StaffForm>(mParentWidget, staffController);
    mStaffForm->show();

    return true;
}


