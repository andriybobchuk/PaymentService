#include "database.h"
#include <string>
#include "PaymentService.h"
#include "json.hpp"

void serializeToDb(const std::string& fileName, PaymentService* paymentService) {
    std::ofstream outputFile;
    outputFile.open(fileName);
    outputFile << paymentService;
    outputFile.close();
}

using json = nlohmann::json;

void deserialize(const std::string& fileName, PaymentService* paymentService) {

    std::ifstream inputFileStream(fileName);
    std::stringstream bufferStringStream;
    bufferStringStream << inputFileStream.rdbuf();
    std::string fileAsString = bufferStringStream.str();


    try {
        nlohmann::json j = nlohmann::json::parse(fileAsString);

        nlohmann::json::iterator c = j.find("debitAccounts");
        if (c.key() == "debitAccounts") {
            for (int i = 0; i < c.value().size(); i++) {
                DebitAccount currentDebitAccount(
                    j["debitAccounts"][i]["id"].get<int>(),
                    j["debitAccounts"][i]["currency"].get<std::string>(),
                    j["debitAccounts"][i]["amount"].get<double>(),
                    j["debitAccounts"][i]["depositRate"].get<double>()
                );
                paymentService->addDebitAccount(currentDebitAccount);
            }
        }

        nlohmann::json::iterator c1 = j.find("creditAccounts");
        if (c1.key() == "creditAccounts") {
            for (int i = 0; i < c1.value().size(); i++) {
                CreditAccount currentCreditAccount(
                    j["creditAccounts"][i]["id"].get<int>(),
                    j["creditAccounts"][i]["currency"].get<std::string>(),
                    j["creditAccounts"][i]["amount"].get<double>(),
                    j["creditAccounts"][i]["loanRate"].get<double>()
                );
                paymentService->addCreditAccount(currentCreditAccount);
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

                paymentService->addClient(currentClient);
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

                paymentService->addStaff(currentStaff);
            }
        }

    }
    catch (const std::exception& e) {
        std::cout << "Bad file " << e.what() << '\n';
    }

}
