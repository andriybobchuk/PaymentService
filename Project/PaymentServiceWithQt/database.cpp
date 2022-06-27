#include "database.h"
#include <string>
#include "PaymentService.h"
#include "json.hpp"

void serialize() {
    std::ofstream outputFile;
    outputFile.open(FILE_NAME);
    outputFile << PaymentService::getInstance();
    outputFile.close();
}

using json = nlohmann::json;

bool deserialize() {

    std::ifstream inputFileStream(FILE_NAME);
    std::stringstream bufferStringStream;
    bufferStringStream << inputFileStream.rdbuf();
    std::string fileAsString = bufferStringStream.str();


    try {
        nlohmann::json j = nlohmann::json::parse(fileAsString);

        nlohmann::json::iterator c = j.find("debitAccounts");
        if (c.key() == "debitAccounts") {
            for (int i = 0; i < c.value().size(); i++) {
                DebitAccount currentDebitAccount(
                    j["debitAccounts"][i]["uid"].get<int>(),
                    j["debitAccounts"][i]["currency"].get<std::string>(),
                    j["debitAccounts"][i]["amount"].get<double>(),
                    j["debitAccounts"][i]["status"].get<std::string>(),
                    j["debitAccounts"][i]["lastRecalculation"].get<std::string>()
                );
                if (currentDebitAccount.getUid() == 0) {
                }
                PaymentService::getInstance()->addDebitAccount(currentDebitAccount);
            }
        }

        nlohmann::json::iterator c1 = j.find("creditAccounts");
        if (c1.key() == "creditAccounts") {
            for (int i = 0; i < c1.value().size(); i++) {
                CreditAccount currentCreditAccount(
                    j["creditAccounts"][i]["uid"].get<int>(),
                    j["creditAccounts"][i]["currency"].get<std::string>(),
                    j["creditAccounts"][i]["amount"].get<double>(),
                    j["creditAccounts"][i]["status"].get<std::string>(),
                    j["creditAccounts"][i]["lastRecalculation"].get<std::string>()
                );
                PaymentService::getInstance()->addCreditAccount(currentCreditAccount);
            }
        }

        nlohmann::json::iterator c2 = j.find("clients");
        if (c2.key() == "clients") {
            for (int i = 0; i < c2.value().size(); i++) {

                Client currentClient(
                    j["clients"][i]["username"].get<std::string>(),
                    j["clients"][i]["password"].get<std::string>(),
                    j["clients"][i]["email"].get<std::string>(),
                    j["clients"][i]["status"].get<std::string>()

                );
                j["clients"][i]["debitAccounts"].get_to<std::vector<int>>(currentClient.getDebitAccounts());
                j["clients"][i]["creditAccounts"].get_to<std::vector<int>>(currentClient.getCreditAccounts());

                PaymentService::getInstance()->addClient(currentClient);
            }
        }

        nlohmann::json::iterator c3 = j.find("staff");
        if (c3.key() == "staff") {

            for (int i = 0; i < c3.value().size(); i++) {

                Staff currentStaff(
                    j["staff"][i]["username"].get<std::string>(),
                    j["staff"][i]["password"].get<std::string>(),
                    j["staff"][i]["email"].get<std::string>(),
                    j["staff"][i]["position"].get<std::string>()
                );

                PaymentService::getInstance()->addStaff(currentStaff);
            }
        }

        nlohmann::json::iterator c4 = j.find("reservedEmails");
        if (c4.key() == "reservedEmails") {

            for (int i = 0; i < c4.value().size(); i++) {

                PaymentService::getInstance()->addReservedEmail(j["reservedEmails"][i].get<std::string>());
            }
        }

    }
    catch (const std::exception& e) {
        std::cout << "Bad file " << e.what() << '\n';
    }
    return true;
}

