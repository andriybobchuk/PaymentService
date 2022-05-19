#include "ClientForm.h"



ClientForm::ClientForm(QWidget *parent, Client* currentUser)
	: QDialog(parent), mCurrentUser(currentUser)
{

	//Todo: move code from constructor to separate methods
	ui.setupUi(this);
	parentWidget()->hide();

	this->setFixedSize(QSize(1011, 511));

	ui.l_message->setVisible(false);

	connect(ui.pb_create, SIGNAL(clicked()), this, SLOT(registerAccount()));

	QStringList list = (QStringList() << QString::fromStdString(DEBIT_ACCOUNT) << QString::fromStdString(CREDIT_ACCOUNT));
	ui.cb_type->addItems(list);

	QStringList list1 = (QStringList() << QString::fromStdString("PLN") << QString::fromStdString("USD"));
	ui.cb_currency->addItems(list1);

	setupSettingsTab();

	displayAccountList();

}

ClientForm::~ClientForm()
{
}


// Todo: optimize account regisatration
void ClientForm::registerAccount() {
	QString type = ui.cb_type->currentText();
	QString currency = ui.cb_currency->currentText();
	QString amount = ui.le_amount->text();

	if (type.toStdString() == DEBIT_ACCOUNT) {
		if (createDebitAccount(
			currency.toStdString(),
			amount.toDouble(),
			mCurrentUser
		)) {
			ui.l_message->setVisible(true);
			ui.l_message->setText("Sent for approval");
		}
		else {
			ui.l_message->setVisible(true);
			ui.l_message->setText("Try again");
		}
	}
	else if (type.toStdString() == CREDIT_ACCOUNT) {
		if (createCreditAccount(
			currency.toStdString(),
			amount.toDouble(),
			mCurrentUser
		)) {
			ui.l_message->setVisible(true);
			ui.l_message->setText("Sent for approval");
		}
		else {
			ui.l_message->setVisible(true);
			ui.l_message->setText("Try again");
		}
	}
	
}


void ClientForm::displayAccountList() {

	int it = 0;
	for (auto& debitAccount : PaymentService::getInstance()->getDebitAccounts()) {
		ui.tableWidget->insertRow(it);
		ui.tableWidget->setItem(it, 0, new QTableWidgetItem(QString::number(debitAccount.getUid())));
		ui.tableWidget->setItem(it, 1, new QTableWidgetItem(QString::fromStdString(DEBIT_ACCOUNT)));
		ui.tableWidget->setItem(it, 2, new QTableWidgetItem(QString::fromStdString(debitAccount.getCurrency() + " ") + QString::number(debitAccount.getAmount())));
		it++;
	}




	//for (int i = 0; i < mCurrentUser->getDebitAccounts().size(); i++) {
	//	QTableWidgetItem* item;

	//	QTableWidgetItem* itemUid = new QTableWidgetItem;
	//	QTableWidgetItem* itemType = new QTableWidgetItem;
	//	QTableWidgetItem* itemAmount = new QTableWidgetItem;

	//	itemUid->setText(
	//		QString::fromStdString(PaymentService::getInstance()->getClients().at(i).getUsername())
	//	);
	//	ui.tableWidget->setItem(i, 0, itemUsername);
	//	ui.tableWidget->item(i, 0)->setTextAlignment(Qt::AlignCenter);

	//	itemEmail->setText(
	//		QString::fromStdString(PaymentService::getInstance()->getClients().at(i).getEmail())
	//	);
	//	ui.tableWidget->setItem(i, 1, itemEmail);
	//	ui.tableWidget->item(i, 1)->setTextAlignment(Qt::AlignCenter);

	//	itemStatus->setText(
	//		QString::fromStdString(PaymentService::getInstance()->getClients().at(i).getStatus())
	//	);
	//	ui.tableWidget->setItem(i, 2, itemStatus);
	//	ui.tableWidget->item(i, 2)->setTextAlignment(Qt::AlignCenter);

	//	// Approve Buttons
	//	QWidget* pWidget = new QWidget();
	//	QPushButton* pb_approve = new QPushButton();
	//	pb_approve->setObjectName("pb_approve");

	//	if (PaymentService::getInstance()->getClients().at(i).getStatus() == APPROVED) {
	//		pb_approve->setText("Ban");
	//		pb_approve->setStyleSheet("#pb_approve {\nborder-style: outset;\nborder-radius: 10px;\nborder-color:#000000;\nborder-width: 1px;\nmin-width: 5em;\nfont: bold 12px;\npadding: 3px;\nbackground-color: #000000;\ncolor: #FFFFFF}");
	//	}
	//	else {
	//		pb_approve->setText("Approve");
	//		pb_approve->setStyleSheet("#pb_approve {\nborder-style: outset;\nborder-radius: 10px;\nborder-color:#000000;\nborder-width: 1px;\nmin-width: 5em;\nfont: bold 12px;\npadding: 3px;\nbackground-color: #FFFFFF;\ncolor: #000000}");
	//	}

	//	QHBoxLayout* pLayout = new QHBoxLayout(pWidget);
	//	pLayout->addWidget(pb_approve);
	//	pLayout->setAlignment(Qt::AlignCenter);
	//	pLayout->setContentsMargins(0, 0, 0, 0);
	//	pWidget->setLayout(pLayout);

	//	ui.tableWidget->setCellWidget(i, 3, pWidget);

	//	//connect(pb_approve, SIGNAL(clicked()), this, SLOT(approveById(i)));
	//	connect(pb_approve, &QPushButton::clicked, [=]() {

	//		if (pb_approve->text() == "Approve") {
	//			approveById(i);     // Call the function which uses i 
	//			itemStatus->setText(
	//				QString::fromStdString(PaymentService::getInstance()->getClients().at(i).getStatus())
	//			);

	//			pb_approve->setText("Ban");
	//			pb_approve->setStyleSheet("#pb_approve {\nborder-style: outset;\nborder-radius: 10px;\nborder-color:#000000;\nborder-width: 1px;\nmin-width: 5em;\nfont: bold 12px;\npadding: 3px;\nbackground-color: #000000;\ncolor: #FFFFFF}");
	//		}
	//		else if (pb_approve->text() == "Ban") {
	//			banById(i);
	//			itemStatus->setText(
	//				QString::fromStdString(PaymentService::getInstance()->getClients().at(i).getStatus())
	//			);
	//			pb_approve->setText("Approve");
	//			pb_approve->setStyleSheet("#pb_approve {\nborder-style: outset;\nborder-radius: 10px;\nborder-color:#000000;\nborder-width: 1px;\nmin-width: 5em;\nfont: bold 12px;\npadding: 3px;\nbackground-color: #FFFFFF;\ncolor: #000000}");
	//		}

	//		});

	//}

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