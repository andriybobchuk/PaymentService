#include "AccountCreatorDialog.h"



AccountCreatorDialog::AccountCreatorDialog(QWidget *parent, ClientController* clientController)
	: QDialog(parent), mClientController(clientController)
{
	ui.setupUi(this);

	QStringList list = (QStringList() 
		<< QString::fromStdString(DEBIT_ACCOUNT) 
		<< QString::fromStdString(CREDIT_ACCOUNT));
	ui.cb_type->addItems(list);
	
	QStringList list1 = (QStringList() 
		<< QString::fromStdString("USD") 
		<< QString::fromStdString("PLN") 
		<< QString::fromStdString("EUR")
		<< QString::fromStdString("UAH"));
	ui.cb_currency->addItems(list1);

	onClickCreateAccount();

}

AccountCreatorDialog::~AccountCreatorDialog()
{
}


void AccountCreatorDialog::onClickCreateAccount() {


	ui.l_message->setVisible(false);

	connect(ui.pb_create, &QPushButton::clicked, [=]() {


		QString type = ui.cb_type->currentText();
		QString currency = ui.cb_currency->currentText();

		ui.l_message->setVisible(true);
		if (type.toStdString() == "" || currency.toStdString() == "") {
			ui.l_message->setText("Fill all fields!");
		}
		else {
			mClientController->createAccount(type.toStdString(), currency.toStdString());

			pushToDatabase(); // Save chnages to the database file
			ui.l_message->setText("Sent for approval");
			parentWidget()->show();
			
			//mClientForm->setupAccountTable();

			close();
		}
	});
}