//
// Created by Andriy Bobchuk on 4/2/2022.
//

#include "util.h"




bool isPasswordSecure(std::string password) {


    //todo: Remove on release
    return true;


    std::regex validPasswordPattern(
        R"(^(?=.*?[A-Z])(?=.*?[a-z])(?=.*?[0-9])(?=.*?[^ a-zA-Z0-9]).{8,}$)"
    );

    if (!std::regex_match(password, validPasswordPattern)) {
        return false;
    }
    else {
        return true;
    }
}

bool isEmailValid(std::string email) {

    std::regex validEmailPattern("([a-zA-Z0-9.]+@[a-zA-Z]+\\.[a-zA-Z.]{2,})");

    if (!std::regex_match(email, validEmailPattern)) {
        return false;
    }
    else {
        return true;
    }
}

bool isTransferAmountValid(std::string amount) {

    std::regex validAmountPattern("^[+]?\\d+([.]\\d+)?$");

    if (!std::regex_match(amount, validAmountPattern)) {
        return false;
    }
    else {
        return true;
    }
}

void createDatabaseBackup() {

    const std::filesystem::path source = DATABASE_FILE;
    const std::filesystem::path destination = std::string(
        "databaseBackup of " 
        + getCurrentDateAndTime() 
        + DATABASE_EXTENSION
    );

    std::filesystem::copy_file(
        source, 
        destination, 
        std::filesystem::copy_options::overwrite_existing
    );
}

int getNewAccountUid() {


   // auto result = std::ranges::max_element(v.begin(), v.end());



    int newAccountUid = 1000;

    for (auto debitAccount : PaymentService::getInstance()->getDebitAccounts()) {
        if (debitAccount.getUid() >= newAccountUid) {
            newAccountUid = debitAccount.getUid() + 1;
        }
    }
    for (auto creditAccount : PaymentService::getInstance()->getCreditAccounts()) {
        if (creditAccount.getUid() >= newAccountUid) {
            newAccountUid = creditAccount.getUid() + 1;
        }
    }

    return newAccountUid;
}


void pushToDatabase() {
    serialize();
}

void pullFromDatabase() {
    PaymentService::setInstance(0); // zeroing the previous instance not to have a double data
    deserialize();
}


unsigned int stringToHashFunction(std::string string) {

    unsigned int init = 156754;
    unsigned int multiplier = 987655;
    unsigned int hash = init;

    for (int i = 0; i < string.length(); i++) {
        hash = hash ^ (string[i]); // XOR each byte of string
        hash = hash * multiplier;
    }
    return hash;
}


std::string unsignedIntToHex(unsigned int input) {
    std::string hexHash;
    std::stringstream sstream;
    sstream << std::hex << input;
    hexHash = sstream.str();
    std::transform(hexHash.begin(), hexHash.end(), hexHash.begin(), ::toupper);
    return hexHash;
}


std::string passwordToHash(std::string password) {
    return unsignedIntToHex(stringToHashFunction(password));
}


bool comparePasswordToHash(std::string password, std::string hash) {
    if (passwordToHash(password) == hash) {
        return true;
    }
    return false;
}


std::string doubleToString(double number) {

    // Create an output string stream
    std::ostringstream streamObj3;

    // Set Fixed -Point Notation
    streamObj3 << std::fixed;

    // Set precision to 2 digits
    streamObj3 << std::setprecision(2);

    //Add double to stream
    streamObj3 << number;

    // Get string from output string stream
    std::string strObj3 = streamObj3.str();

    // returning the result
    return strObj3;
}

int countLeapYears(Date d)
{
    int years = d.y;

    // Check if the current year needs to be
    //  considered for the count of leap years
    // or not
    if (d.m <= 2)
        years--;

    // An year is a leap year if it
    // is a multiple of 4,
    // multiple of 400 and not a
     // multiple of 100.
    return years / 4
        - years / 100
        + years / 400;
}

int getDifference(Date dt1, Date dt2)
{
    // COUNT TOTAL NUMBER OF DAYS
// BEFORE FIRST DATE 'dt1'

// initialize count using years and day
    long int n1 = dt1.y * 365 + dt1.d;

    // Add days for months in given date
    for (int i = 0; i < dt1.m - 1; i++)
        n1 += monthDays[i];

    // Since every leap year is of 366 days,
    // Add a day for every leap year
    n1 += countLeapYears(dt1);

    // SIMILARLY, COUNT TOTAL NUMBER OF
    // DAYS BEFORE 'dt2'

    long int n2 = dt2.y * 365 + dt2.d;
    for (int i = 0; i < dt2.m - 1; i++)
        n2 += monthDays[i];
    n2 += countLeapYears(dt2);

    // return difference between two counts
    return (n2 - n1);
}

Date stringToDate(const std::string& s, char delim) {
    Date date;
    std::stringstream ss(s);
    std::string item;

    std::vector<int> vec;
    while (getline(ss, item, delim)) {
        vec.push_back(std::stoi(item));
    }

    date.d = vec[0];
    date.m = vec[1];
    date.y = vec[2];

    return date;
}

double compoundInterest(double principal, double interestRate, int days) {
    return principal * std::pow((1 + (interestRate / 100)), days);
}

double loanInterest(double principal, double interestRate, int days) {
    return principal / std::pow((1 + (interestRate / 100)), days);
}

std::string getCurrentDate() {

    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%d-%m-%Y");
    auto currentDateString = oss.str();

     return currentDateString;
}

std::string getCurrentDateAndTime() {

    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%d-%m-%Y %H-%M-%S");
    auto currentDateString = oss.str();

    return currentDateString;
}
   