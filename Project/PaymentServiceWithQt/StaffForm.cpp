#include "StaffForm.h"


StaffForm::StaffForm(QWidget *parent, Staff* admin) :
    QDialog(parent), mAdmin(admin) {
	ui.setupUi(this);
	this->setFixedSize(QSize(811, 511));
	parentWidget()->hide();

	setupSettingsTab();

	setupAccountTable();
}

StaffForm::~StaffForm()
{
}

void StaffForm::approveById(int id) {
	approveClientById(id); // Kindly ask controller.cpp to change the database
	setupAccountTable();
}

void StaffForm::banById(int id) {
	banClientById(id); // Kindly ask controller.cpp to change the database
	setupAccountTable();
}


void StaffForm::setupActionButton(int it) {

	QWidget* pWidget = new QWidget();
	QPushButton* pb_action = new QPushButton();
	pb_action->setObjectName("pb_action"); // Layout id

	// Todo: You shouldn't access the model through view
	if (PaymentService::getInstance()->getClients().at(it).getStatus() == APPROVED) {
		pb_action->setText("Ban");
		pb_action->setStyleSheet("#pb_action {\nborder-style: outset;\nborder-radius: 10px;\nborder-color:#000000;\nborder-width: 1px;\nmin-width: 5em;\nfont: bold 12px;\npadding: 3px;\nbackground-color: #000000;\ncolor: #FFFFFF}");
	} else {
		pb_action->setText("Approve");
		pb_action->setStyleSheet("#pb_action {\nborder-style: outset;\nborder-radius: 10px;\nborder-color:#000000;\nborder-width: 1px;\nmin-width: 5em;\nfont: bold 12px;\npadding: 3px;\nbackground-color: #FFFFFF;\ncolor: #000000}");
	}

	// Is it dead code??
	QHBoxLayout* pLayout = new QHBoxLayout(pWidget);
	pLayout->addWidget(pb_action);
	pLayout->setAlignment(Qt::AlignCenter);
	pLayout->setContentsMargins(0, 0, 0, 0);
	pWidget->setLayout(pLayout);
	ui.tableWidget->setCellWidget(it, 3, pWidget);

	// just do whatever you should and reload the database
	connect(pb_action, &QPushButton::clicked, [=]() {
		if (pb_action->text() == "Approve") {
			approveById(it);    
			setupAccountTable();
		} else {
			banById(it);
			setupAccountTable();
		}
	});
}

void StaffForm::setupAccountTable() {

	ui.tableWidget->clear();
	ui.tableWidget->setRowCount(0);

	int it = 0;
	// Todo: You shouldn't access the model through view
	for (auto& client : PaymentService::getInstance()->getClients()) {
		ui.tableWidget->insertRow(it);
		ui.tableWidget->setItem(it, 0, new QTableWidgetItem(QString::fromStdString(client.getUsername())));
		ui.tableWidget->setItem(it, 1, new QTableWidgetItem(QString::fromStdString(client.getEmail())));
		ui.tableWidget->setItem(it, 2, new QTableWidgetItem(QString::fromStdString(client.getStatus())));

		setupActionButton(it);

		it++;
	}
}

void StaffForm::setupSettingsTab() {
	connect(ui.pb_logOut, SIGNAL(clicked()), this, SLOT(logOut()));
	ui.l_user->setText(QString::fromStdString(mAdmin->getEmail()));
}


void StaffForm::logOut() {
	safelyEndSession(); // Save chnages to the database file
	parentWidget()->show();
	close();
}