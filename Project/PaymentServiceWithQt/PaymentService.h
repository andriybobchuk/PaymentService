#pragma once

#include "Client.h"
#include "Staff.h"
#include "DebitAccount.h"
#include "CreditAccount.h"

#include <vector>
#include <iostream>
#include<fstream>
#include<sstream>

/// <summary>
/// Singleton pattern class storing information about all users and their accounts
/// </summary>
class PaymentService {

	/* Here will be the instance stored. */
	static PaymentService* instance;

	/* Private constructor to prevent instancing. */
	PaymentService() = default;

	/* Info about users and accounts. */
	std::vector<std::string> mReservedEmails;
	std::vector<Client> mClients;
	std::vector<Staff> mStaff;
	std::vector<DebitAccount> mDebitAccounts;
	std::vector<CreditAccount> mCreditAccounts;

public:

	/* Static access method. */
	static PaymentService* getInstance();

	void addReservedEmail(std::string reservedEmail);

	void removeReservedEmail(std::string reservedEmail);

	void setReservedEmails(const std::vector<std::string>& mReservedEmails);



	std::vector<std::string>& getReservedEmails();

	std::vector<std::string> getRegisteredEmails();



	void addDebitAccount(DebitAccount debitAccount);

	void addCreditAccount(CreditAccount creditAccount);

	void addClient(Client client);

	void addStaff(Staff staff);

	static void setInstance(PaymentService* instance);

	[[nodiscard]] std::vector<Client>& getClients();

	void setClients(const std::vector<Client>& mClients);

	[[nodiscard]] std::vector<Staff>& getStaff();

	void setStaff(const std::vector<Staff>& mStaff);

	[[nodiscard]] std::vector<DebitAccount>& getDebitAccounts();

	void setDebitAccounts(const std::vector<DebitAccount>& mDebitAccounts);

	[[nodiscard]] std::vector<CreditAccount>& getCreditAccounts();

	void setCreditAccounts(const std::vector<CreditAccount>& mCreditAccounts);

	friend std::ostream& operator<<(std::ostream& os, PaymentService* paymentService);

};

