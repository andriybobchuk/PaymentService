#include "Reservation.h"

bool Reservation::reserve(std::string email)
{

    std::vector<std::string> registeredEmails = PaymentService::getInstance()->getRegisteredEmails();
    std::vector<std::string> reservedEmails = PaymentService::getInstance()->getReservedEmails();

    if (
        std::find(
            registeredEmails.begin(),
            registeredEmails.end(),
            email) != registeredEmails.end()
        ) {
        return false;
    }

    if (
        std::find(
            reservedEmails.begin(),
            reservedEmails.end(),
            email) != reservedEmails.end()
        ) {
        return false;
    }

    PaymentService::getInstance()->addReservedEmail(email);


}


bool Reservation::complete(std::string email)
{
    std::vector<std::string> reservedEmails = PaymentService::getInstance()->getReservedEmails();

    if (
        std::find(
            reservedEmails.begin(),
            reservedEmails.end(),
            email) != reservedEmails.end() == false
        ) {
        return false;
    }

    PaymentService::getInstance()->removeReservedEmail(email);
    
    return true; 
}
