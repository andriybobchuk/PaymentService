#include "StaffForm.h"
#include <QHeaderView>
#include "PaymentServiceWithQt.h"
#include <QHBoxLayout>

StaffForm::StaffForm(QWidget *parent) :
    QWidget(parent)
{
	ui.setupUi(this);
	this->setFixedSize(QSize(811, 511));

	// Buttons
	connect(ui.pb_logOut, SIGNAL(clicked()), this, SLOT(logOut()));

	// Populate Ui with the data about the current user
	extern BaseUser currentUser; // same currentUser as we get from login credentials in controller.cpp
	ui.l_user->setText(QString::fromStdString(currentUser.getEmail()));

	// Table
	ui.tableWidget->setRowCount(PaymentService::getInstance()->getClients().size());
	ui.tableWidget->setColumnCount(4);
	ui.tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

	QStringList labels;
	labels << "Username" << "Email" << "Status" << "Action";
	ui.tableWidget->setHorizontalHeaderLabels(labels);

	for (int i = 0; i < PaymentService::getInstance()->getClients().size(); i++) {
		QTableWidgetItem* item;

		QTableWidgetItem* itemUsername = new QTableWidgetItem;
		QTableWidgetItem* itemEmail = new QTableWidgetItem;
		QTableWidgetItem* itemStatus = new QTableWidgetItem;

		itemUsername->setText(
			QString::fromStdString(PaymentService::getInstance()->getClients().at(i).getUsername())
			);
		ui.tableWidget->setItem(i, 0, itemUsername);
		ui.tableWidget->item(i, 0)->setTextAlignment(Qt::AlignCenter);

		itemEmail->setText(
			QString::fromStdString(PaymentService::getInstance()->getClients().at(i).getEmail())
		);
		ui.tableWidget->setItem(i, 1, itemEmail);
		ui.tableWidget->item(i, 1)->setTextAlignment(Qt::AlignCenter);

		itemStatus->setText(
			QString::fromStdString(PaymentService::getInstance()->getClients().at(i).getStatus())
		);
		ui.tableWidget->setItem(i, 2, itemStatus);
		ui.tableWidget->item(i, 2)->setTextAlignment(Qt::AlignCenter);


		// Approve Buttons
		QWidget* pWidget = new QWidget();

		QPushButton* pb_approve = new QPushButton();
		pb_approve->setText("Approve");

		pb_approve->setObjectName("pb_approve");
		pb_approve->setStyleSheet("#pb_approve {\nborder-style: outset;\nborder-radius: 10px;\nborder-color:#000000;\nborder-width: 1px;\nmin-width: 5em;\nfont: bold 12px;\npadding: 3px;\nbackground-color: #FFFFFF;\ncolor: #000000}");

		QHBoxLayout* pLayout = new QHBoxLayout(pWidget);
		pLayout->addWidget(pb_approve);
		pLayout->setAlignment(Qt::AlignCenter);
		pLayout->setContentsMargins(0, 0, 0, 0);
		pWidget->setLayout(pLayout);

		ui.tableWidget->setCellWidget(i, 3, pWidget);

		//connect(pb_approve, SIGNAL(clicked()), this, SLOT(approveById(i)));
		connect(pb_approve, &QPushButton::clicked, [=]() {
			approveById(i);     // Call the function which uses i 
			itemStatus->setText(
				QString::fromStdString(PaymentService::getInstance()->getClients().at(i).getStatus())
			);
		});

	}

	ui.tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
	ui.tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.tableWidget->setTextElideMode(Qt::ElideRight);
	ui.tableWidget->setSortingEnabled(true);
	ui.tableWidget->setShowGrid(false);

	ui.tableWidget->horizontalHeader()->setVisible(true);
	ui.tableWidget->horizontalHeader()->setDefaultSectionSize(167);	
	ui.tableWidget->horizontalHeader()->setStretchLastSection(true);
	ui.tableWidget->verticalHeader()->setVisible(false);
	


}

StaffForm::~StaffForm()
{
}


void StaffForm::logOut() {

	ui.tableWidget->clear();
	ui.tableWidget->setRowCount(0); // clears old data

	safelyEndSession();

	PaymentServiceWithQt* entry = new PaymentServiceWithQt();
	entry->show();
	close();
}


void StaffForm::approveById(int id) {

	approveClientById(id); // Kindly ask controller.cpp to change the database

	ui.l_signUpInfo->setText(
		QString::fromStdString("You have just approved user " + PaymentService::getInstance()->getClients().at(id).getUsername())
	);

	
}
