#include "StaffForm.h"


StaffForm::StaffForm(QWidget *parent, StaffController* staffController) :
    QDialog(parent), mStaffController(staffController) {

	ui.setupUi(this);
	this->setFixedSize(QSize(811, 511));
	parentWidget()->hide();


	setupUsersListTab();

	setupAccountsListTab();

	setupSettingsTab();



	
}

StaffForm::~StaffForm()
{
}




void StaffForm::setupUsersActionButton(int id) {

	QWidget* pWidget = new QWidget();
	QPushButton* pb_userAction = new QPushButton();
	pb_userAction->setObjectName("pb_useraction"); // Layout id

	if (mStaffController->isClientApproved(id)) {
		pb_userAction->setText("Ban");
		pb_userAction->setStyleSheet("#pb_useraction {\nborder-style: outset;\nborder-radius: 10px;\nborder-color:#000000;\nborder-width: 1px;\nmin-width: 5em;\nfont: bold 12px;\npadding: 3px;\nbackground-color: #000000;\ncolor: #FFFFFF}");
	} else {
		pb_userAction->setText("Approve");
		pb_userAction->setStyleSheet("#pb_useraction {\nborder-style: outset;\nborder-radius: 10px;\nborder-color:#000000;\nborder-width: 1px;\nmin-width: 5em;\nfont: bold 12px;\npadding: 3px;\nbackground-color: #FFFFFF;\ncolor: #000000}");
	}

	// Button styling which can be done ONLY programmatically
	QHBoxLayout* pLayout = new QHBoxLayout(pWidget);
	pLayout->addWidget(pb_userAction);
	pLayout->setAlignment(Qt::AlignCenter);
	pLayout->setContentsMargins(0, 0, 0, 0);
	pWidget->setLayout(pLayout);
	ui.tw_users->setCellWidget(id, 3, pWidget);

	// just do whatever you should and reload the database
	connect(pb_userAction, &QPushButton::clicked, [=]() {
		if (pb_userAction->text() == "Approve") {
			mStaffController->approveClientById(id); // Ask controller to approve him    
		} else {
			mStaffController->banClientById(id); // Ask controller to ban him 
		}
		setupUserTable(); // Reload the table so that the user can see changes
	});
}

void StaffForm::setupUserTable() {

	ui.tw_users->clear();
	ui.tw_users->setRowCount(0);

	// Users data obtained from controller
	std::vector<std::vector<std::string>> users(mStaffController->getAllUsers());

	for (auto& client : users) {

		int id = stoi(client[0]);

		ui.tw_users->insertRow(id);
		ui.tw_users->setItem(id, 0, new QTableWidgetItem(QString::fromStdString("    " + client[1])));
		ui.tw_users->setItem(id, 1, new QTableWidgetItem(QString::fromStdString(client[2])));
		ui.tw_users->setItem(id, 2, new QTableWidgetItem(QString::fromStdString(client[3])));

		setupUsersActionButton(id);

	}
}

// todo button for accounts
void StaffForm::setupAccountActionButton(int id)
{
}


void StaffForm::setupAccountTable() {

	ui.tw_accounts->clear();
	ui.tw_accounts->setRowCount(0);

	// Users data obtained from controller
	std::vector<std::vector<std::string>> users(mStaffController->getAllAccounts());

	for (auto& user : users) {

		int id = stoi(user[0]);

		ui.tw_accounts->insertRow(id);
		ui.tw_accounts->setItem(id, 0, new QTableWidgetItem(QString::fromStdString("  " + user[1]))); // Uid
		ui.tw_accounts->setItem(id, 1, new QTableWidgetItem(QString::fromStdString(user[2] + " " + user[3]))); // Currency + Amount 
		ui.tw_accounts->setItem(id, 2, new QTableWidgetItem(QString::fromStdString(user[4] + "(" + user[5] + "% / yr.)"))); // Type + rate
		ui.tw_accounts->setItem(id, 3, new QTableWidgetItem(QString::fromStdString(user[6]))); // Status

		setupAccountActionButton(id);
	}
}


void StaffForm::setupUsersListTab() {
	setupUserTable();
}

void StaffForm::setupAccountsListTab() {
	// Todo("Not yet implemented");
	setupAccountTable();
}


void StaffForm::setupSettingsTab() {

	// OnClick() for log out button
	connect(ui.pb_logOut, SIGNAL(clicked()), this, SLOT(logOut()));

	// Populate the textView with the current user email
	ui.l_user->setText(QString::fromStdString(mStaffController->getCurrentUserEmail()));
}


void StaffForm::logOut() {

	pushToDatabase(); // Save chnages to the database file

	// Switch windows
	parentWidget()->show();
	close();
}