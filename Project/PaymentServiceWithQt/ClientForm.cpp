#include "ClientForm.h"



ClientForm::ClientForm(QWidget *parent, std::shared_ptr<ClientController> clientController)
	: QDialog(parent), mClientController(clientController) {

	ui.setupUi(this);
	this->setFixedSize(QSize(1018, 600));
	parentWidget()->hide();

	// SETUPS:

	ui.l_message->setVisible(false);

	recalculateBalances();

	setupAccountTab();

	setupSettingsTab();


	// ONCLICKS:

	onClickTransferMoney();

	onClickCreateAccount();

	onClickSuspend();

	onClickAddOwner();




}

ClientForm::~ClientForm() {
	//delete mClientController;
}

void ClientForm::recalculateBalances() {

	ui.w_debt->setVisible(false);

	if (!mClientController->recalculationSuccessful()) {
		issueDebtReport();
	}
}

// Done
void ClientForm::onClickTransferMoney() {
	ui.l_message->setVisible(false);

	connect(ui.pb_send, &QPushButton::clicked, [=]() {

		ui.l_message->setVisible(true);
		QString recipientAccountUid = ui.le_toAccount->text();
		QString amount = ui.le_toAmount->text();

		if (recipientAccountUid.toStdString() == "" || amount.toStdString() == "") {
			ui.l_message->setText("Fill all the fields!");
			return;
		}

		if (!isTransferAmountValid(amount.toStdString())) {
			ui.l_message->setText("Enter proper amount!");
			return;
		}

		if (mClientController->sendMoney(recipientAccountUid.toInt(), amount.toDouble())) {
			ui.l_message->setText("Money transfered successfully!");
			ui.le_toAccount->clear();
			ui.le_toAmount->clear();
			setupAccountTable(); // refresh the table with balance

			// refresh bottom panel
			ui.l_accountAmount->setText(QString::fromStdString(mClientController->getCurrentStringAccount()[1]));
		}
		else {
			ui.l_message->setText("Something went wrong");
		}
	});

}

void ClientForm::onClickAddOwner() {

	connect(ui.pb_addOwner, &QPushButton::clicked, [=]() {\

		ui.l_message->setVisible(true);

		QString email = ui.le_newOwner->text();

		if (isEmailValid(email.toStdString())) {

			if (mClientController->addOwner(email.toStdString())) {
				ui.l_message->setText("New owner added!");
				ui.le_newOwner->clear();
			}
			else {
				ui.l_message->setText("Something went wrong");
			}
		}
		else {
			ui.l_message->setText("Email is invalid!");
		}
	});
}

void ClientForm::onClickSuspend() {

	connect(ui.pb_suspend, &QPushButton::clicked, [=]() {

		ui.l_message->setVisible(true);

		if (mClientController->suspendAccount()) {

			ui.w_placeholder->setVisible(true);
			ui.l_message->setText("Account deleted!");
			setupAccountTable(); // refresh
		}
		else {
			ui.l_message->setText("Pay off the debt first!");
		}
	});
}

void ClientForm::setupTableActionButton(int id, std::vector<std::string> currentAccount) {

	QWidget* pWidget = new QWidget();
	QPushButton* pb_userAction = new QPushButton();
	pb_userAction->setObjectName("pb_useraction"); // Layout id

	pb_userAction->setText("Manage");
	pb_userAction->setStyleSheet("#pb_useraction {\nborder-style: outset;\nborder-radius: 10px;\nborder-color:#000000;\nborder-width: 0.5px;\nmin-width: 5em;\nfont: bold 10px;\npadding: 3px;\nmargin: 2px;\nbackground-color: #FFFFFF;\ncolor: #000000}");


	//Button styling which can be done ONLY programmatically
	QHBoxLayout* pLayout = new QHBoxLayout(pWidget);
	pLayout->addWidget(pb_userAction);
	pLayout->setAlignment(Qt::AlignCenter);
	pLayout->setContentsMargins(0, 0, 0, 0);
	pWidget->setLayout(pLayout);
	ui.tw_accounts->setCellWidget(id, 3, pWidget);

	// just do whatever you should and reload the database
	connect(pb_userAction, &QPushButton::clicked, [=]() {

		mClientController->setCurrentAccount(currentAccount[0]);

		ui.l_currentAccount->setText(QString::fromStdString("Current selected account: #" + currentAccount[0] + "."));
		ui.l_accountAmount->setText(QString::fromStdString(currentAccount[1]));
		ui.l_accountType->setText(QString::fromStdString(currentAccount[3] + " - " + currentAccount[2]));
		if (currentAccount[3] == DEBIT_ACCOUNT) {
			ui.I_accountFeature->setText(QString::fromStdString(DEBIT_FEATURE));
		}
		else {
			ui.I_accountFeature->setText(QString::fromStdString(CREDIT_FEATURE));
		}
		ui.w_placeholder->setVisible(false);
	});
}

void ClientForm::setupAccountTable() {

	ui.tw_accounts->clear();
	ui.tw_accounts->setRowCount(0);

	// Users data obtained from controller
	auto accounts(mClientController->getMyBaseAccounts());

	int itr = 0;
	for (auto& account : accounts) {

		ui.tw_accounts->insertRow(itr);
		ui.tw_accounts->setItem(itr, 0, new QTableWidgetItem(QString::fromStdString(account[0]))); // Uid
		ui.tw_accounts->setItem(itr, 1, new QTableWidgetItem(QString::fromStdString(account[1]))); // Currency + Amount 
		ui.tw_accounts->setItem(itr, 2, new QTableWidgetItem(QString::fromStdString(account[3]))); // Type
		ui.tw_accounts->setItem(itr, 3, new QTableWidgetItem(QString::fromStdString(account[2]))); // Status

		if (account[2] == APPROVED) {
			setupTableActionButton(itr, account);
		}
		itr++;
	}
}


void ClientForm::issueDebtReport() {
	ui.w_debt->setVisible(true);
}

void ClientForm::setupAccountTab() {

	setupAccountTable();
}


void ClientForm::setupSettingsTab() {

	// Log Out button listener
	connect(ui.pb_logOut, SIGNAL(clicked()), this, SLOT(logOut()));

	// Populate Ui with the data about the current user
	ui.l_userEmail->setText(QString::fromStdString(mClientController->getCurrentUserEmail()));
}

void ClientForm::onClickCreateAccount()
{
	connect(ui.pb_new, &QPushButton::clicked, [=]() {

		//AccountCreatorDialog* rawAccountCreatorDialog = new AccountCreatorDialog(this, mClientController);
		mAccountCreatorDialog = std::make_shared<AccountCreatorDialog>(this, mClientController);

		mAccountCreatorDialog->show();
		parentWidget()->hide();
	});
}

void ClientForm::logOut() {

	pushToDatabase(); // Save chnages to the database file

	parentWidget()->show();
	close();
}