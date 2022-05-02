#include "ClientForm.h"
#include "PaymentServiceWithQt.h"

ClientForm::ClientForm(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setFixedSize(QSize(811, 511));

	// Buttons
	connect(ui.pb_logOut, SIGNAL(clicked()), this, SLOT(logOut()));
}

ClientForm::~ClientForm()
{
}


void ClientForm::logOut() {
	PaymentServiceWithQt* entry = new PaymentServiceWithQt();
	entry->show();
	close();
}