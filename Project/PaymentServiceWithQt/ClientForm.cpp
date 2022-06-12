#include "ClientForm.h"



ClientForm::ClientForm(QWidget *parent, ClientController* clientController)
	: QDialog(parent), mClientController(clientController) {

	ui.setupUi(this);
	this->setFixedSize(QSize(1018, 600));
	parentWidget()->hide();

	//setupCreateAccountPanel();

	setupAccountTab();
	onSendMoneyClick();
	onClickCreateAccount();

	setupSettingsTab();

	///-----------
	
	
}


ClientForm::~ClientForm()
{
}

// todo
//void ClientForm::setupCreateAccountPanel() {
//
//	QStringList list = (QStringList() << QString::fromStdString(DEBIT_ACCOUNT) << QString::fromStdString(CREDIT_ACCOUNT));
//	ui.cb_type->addItems(list);
//
//	QStringList list1 = (QStringList() << QString::fromStdString("PLN") << QString::fromStdString("USD"));
//	ui.cb_currency->addItems(list1);
//
//	connect(ui.pb_create, SIGNAL(clicked()), this, SLOT(registerAccount()));
//	ui.l_message->setVisible(false);
//}


// todo
void ClientForm::registerAccount() {
//	QString type = ui.cb_type->currentText();
//	QString currency = ui.cb_currency->currentText();
//	QString amount = ui.le_amount->text();
//
//	ui.l_message->setVisible(true);
//
//	if (type.toStdString() == DEBIT_ACCOUNT) {
//		if (currency.size() != 0) {
//			createDebitAccount(currency.toStdString());
//			ui.l_message->setText("Sent for approval");
//		}
//		else {
//			ui.l_message->setText("Currency missing");
//		}
//	} else if (type.toStdString() == CREDIT_ACCOUNT) {
//		
//		if (currency.size() != 0 && amount.toDouble() >= 0 
//			// Checking the upper loan limit in our currency rate map:
//			&& (amount.toDouble() <= LOAN_LIMIT / CURRENCY_RATES.find(currency.toStdString())->second)) {
//
//			createCreditAccount(currency.toStdString(), amount.toDouble());
//			ui.l_message->setText("Sent for approval");
//		}
//		else {
//			ui.l_message->setText("Limit exceeded or currency missing");
//		}
//	}
}

void ClientForm::onSendMoneyClick()
{
	ui.l_message->setVisible(false);

	connect(ui.pb_send, &QPushButton::clicked, [=]() {

		ui.l_message->setVisible(true);
		QString recipientAccountUid = ui.le_toAccount->text();
		QString amount = ui.le_toAmount->text();

		if (recipientAccountUid.toStdString() == "" || amount.toStdString() == "") {
			ui.l_message->setText("Fill all the fields!");
			return;
		}

		if (mClientController->sendMoney(recipientAccountUid.toStdString(), amount.toDouble())) {
			ui.l_message->setText("Money transfered successfully!");
			setupAccountTable(); // refresh the table with balance
		}
		else {
			ui.l_message->setText("Something went wrong");
		}
	});

}

void ClientForm::setupTableActionButton(int id, std::string uid) {

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

		mClientController->setCurrentDebitAccount(uid);

		ui.l_currentAccount->setText(QString::fromStdString("(" + uid + ")"));
		ui.w_placeholder->setVisible(false);
	});
}

void ClientForm::setupAccountTable() {

	ui.tw_accounts->clear();
	ui.tw_accounts->setRowCount(0);

	// Users data obtained from controller
	std::vector<std::vector<std::string>> users(mClientController->getAllAccounts());

	for (auto& user : users) {

		int id = stoi(user[0]);

		ui.tw_accounts->insertRow(id);
		ui.tw_accounts->setItem(id, 0, new QTableWidgetItem(QString::fromStdString(user[1]))); // Uid
		ui.tw_accounts->setItem(id, 1, new QTableWidgetItem(QString::fromStdString(user[2] + " " + user[3]))); // Currency + Amount 
		ui.tw_accounts->setItem(id, 2, new QTableWidgetItem(QString::fromStdString(user[4] + "(" + user[5] + "% / yr.)"))); // Type + rate

		setupTableActionButton(id, user[1]);
	}
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
		AccountCreatorDialog* accountCreatorDialog = new AccountCreatorDialog(this);
		accountCreatorDialog->show();
		parentWidget()->hide();
	});
}

void ClientForm::logOut() {

	pushToDatabase(); // Save chnages to the database file

	parentWidget()->show();
	close();
}