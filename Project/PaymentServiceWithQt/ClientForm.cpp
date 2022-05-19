#include "ClientForm.h"


ClientForm::ClientForm(QWidget *parent, Client* currentUser)
	: QDialog(parent), mCurrentUser(currentUser) {
	ui.setupUi(this);
	this->setFixedSize(QSize(1011, 511));
	parentWidget()->hide();

	setupCreateAccountPanel();

	setupSettingsTab();

	setupAccountTable();
}


ClientForm::~ClientForm()
{
}


void ClientForm::setupCreateAccountPanel() {

	QStringList list = (QStringList() << QString::fromStdString(DEBIT_ACCOUNT) << QString::fromStdString(CREDIT_ACCOUNT));
	ui.cb_type->addItems(list);

	QStringList list1 = (QStringList() << QString::fromStdString("PLN") << QString::fromStdString("USD"));
	ui.cb_currency->addItems(list1);

	connect(ui.pb_create, SIGNAL(clicked()), this, SLOT(registerAccount()));
	ui.l_message->setVisible(false);
}


void ClientForm::registerAccount() {
	QString type = ui.cb_type->currentText();
	QString currency = ui.cb_currency->currentText();
	QString amount = ui.le_amount->text();

	ui.l_message->setVisible(true);

	if (type.toStdString() == DEBIT_ACCOUNT) {
		if (createDebitAccount(currency.toStdString(),amount.toDouble(),mCurrentUser)) {
			ui.l_message->setText("Sent for approval");
		} else {
			ui.l_message->setText("Try again");
		}
	} else if (type.toStdString() == CREDIT_ACCOUNT) {
		if (createCreditAccount(currency.toStdString(),amount.toDouble(),mCurrentUser)) {
			ui.l_message->setText("Sent for approval");
		} else {
			ui.l_message->setText("Try again");
		}
	}
}


void ClientForm::setupAccountTable() {

	int it = 0;
	for (auto& debitAccount : PaymentService::getInstance()->getDebitAccounts()) {
		ui.tableWidget->insertRow(it);
		ui.tableWidget->setItem(it, 0, new QTableWidgetItem(QString::number(debitAccount.getUid())));
		ui.tableWidget->setItem(it, 1, new QTableWidgetItem(QString::fromStdString(DEBIT_ACCOUNT)));
		ui.tableWidget->setItem(it, 2, new QTableWidgetItem(QString::fromStdString(debitAccount.getCurrency() + " ") + QString::number(debitAccount.getAmount())));
		it++;
	}
}

void ClientForm::setupSettingsTab() {

	// Log Out button listener
	connect(ui.pb_logOut, SIGNAL(clicked()), this, SLOT(logOut()));

	// Populate Ui with the data about the current user
	ui.l_userUsername->setText(QString::fromStdString("Username: " + mCurrentUser->getUsername()));
	ui.l_userEmail->setText(QString::fromStdString("Email: " + mCurrentUser->getEmail()));
}

void ClientForm::logOut() {

	safelyEndSession(); // Save chnages to the database file
	parentWidget()->show();
	close();
}