#include "StaffForm.h"


StaffForm::StaffForm(QWidget *parent, std::shared_ptr<StaffController> staffController) :
    QDialog(parent), mStaffController(staffController) {

	ui.setupUi(this);
	this->setFixedSize(QSize(811, 511));
	parentWidget()->hide();


	// Display the table with user sign up requests
	setupUsersListTab();

	// Display the table with account requests
	setupAccountsListTab();


	setupSettingsTab();
}

StaffForm::~StaffForm() {
}

void StaffForm::setupUsersActionButton(int id) {

	QWidget* pWidget = new QWidget();
	QPushButton* pb_userAction = new QPushButton();
	pb_userAction->setObjectName("pb_useraction"); // Layout id

	if (mStaffController->isClientApproved(id)) {
		pb_userAction->setText("Ban");
		pb_userAction->setStyleSheet("#pb_useraction {\nborder-style: outset;\nborder-radius: 10px;\nborder-color:#000000;\nborder-width: 0.5px;\nmin-width: 5em;\nfont: bold 10px;\npadding: 3px;\nmargin: 2px;\nbackground-color: #000000;\ncolor: #FFFFFF}");
	} else {
		pb_userAction->setText("Approve");
		pb_userAction->setStyleSheet("#pb_useraction {\nborder-style: outset;\nborder-radius: 10px;\nborder-color:#000000;\nborder-width: 0.5px;\nmin-width: 5em;\nfont: bold 10px;\npadding: 3px;\nmargin: 2px;\nbackground-color: #FFFFFF;\ncolor: #000000}");
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
			mStaffController->changeClientStatus(id, APPROVED); // Ask controller to approve him    
		} else {
			mStaffController->changeClientStatus(id, BANNED); // Ask controller to ban him 
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
		ui.tw_users->setItem(id, 0, new QTableWidgetItem(QString::fromStdString(client[1])));
		ui.tw_users->setItem(id, 1, new QTableWidgetItem(QString::fromStdString(client[2])));
		ui.tw_users->setItem(id, 2, new QTableWidgetItem(QString::fromStdString(client[3])));

		setupUsersActionButton(id);
	}
}

void StaffForm::setupAccountActionButton(int id) {

	QWidget* pWidget = new QWidget();
	QPushButton* pb_accountAction = new QPushButton();
	pb_accountAction->setObjectName("pb_accountaction"); // Layout id

	if (mStaffController->isAccountApproved(id)) {
		pb_accountAction->setText("Ban");
		pb_accountAction->setStyleSheet("#pb_accountaction {\nborder-style: outset;\nborder-radius: 10px;\nborder-color:#000000;\nborder-width: 0.5px;\nmin-width: 5em;\nfont: bold 10px;\npadding: 3px;\nmargin: 2px;\nbackground-color: #000000;\ncolor: #FFFFFF}");
	}
	else {
		pb_accountAction->setText("Approve");
		pb_accountAction->setStyleSheet("#pb_accountaction {\nborder-style: outset;\nborder-radius: 10px;\nborder-color:#000000;\nborder-width: 0.5px;\nmin-width: 5em;\nfont: bold 10px;\npadding: 3px;\nmargin: 2px;\nbackground-color: #FFFFFF;\ncolor: #000000}");
	}

	// Button styling which can be done ONLY programmatically
	QHBoxLayout* pLayout = new QHBoxLayout(pWidget);
	pLayout->addWidget(pb_accountAction);
	pLayout->setAlignment(Qt::AlignCenter);
	pLayout->setContentsMargins(0, 0, 0, 0);
	pWidget->setLayout(pLayout);
	ui.tw_accounts->setCellWidget(id, 4, pWidget);

	// just do whatever you should and reload the database
	connect(pb_accountAction, &QPushButton::clicked, [=]() {
		if (pb_accountAction->text() == "Approve") {
			mStaffController->changeAccountStatus(id, APPROVED); // Ask controller to approve him    
		}
		else {
			mStaffController->changeAccountStatus(id, BANNED); // Ask controller to ban him 
		}
		setupAccountTable(); // Reload the table so that the user can see changes
	});
}


void StaffForm::setupAccountTable() {

	ui.tw_accounts->clear();
	ui.tw_accounts->setRowCount(0);

	// Users data obtained from controller
	std::vector<std::vector<std::string>> accounts(mStaffController->getAllAccounts());

	int itr = 0;
	for (auto& account : accounts) {

		ui.tw_accounts->insertRow(itr);
		ui.tw_accounts->setItem(itr, 0, new QTableWidgetItem(QString::fromStdString("  " + account[0]))); // Uid
		ui.tw_accounts->setItem(itr, 1, new QTableWidgetItem(QString::fromStdString(account[1] + " " + account[2]))); // Currency + Amount 
		ui.tw_accounts->setItem(itr, 2, new QTableWidgetItem(QString::fromStdString(account[3]))); // Type
		ui.tw_accounts->setItem(itr, 3, new QTableWidgetItem(QString::fromStdString(account[4]))); // Status

		setupAccountActionButton(itr);

		itr++;
	}
}


void StaffForm::setupUsersListTab() {
	setupUserTable();
}

void StaffForm::setupAccountsListTab() {
	setupAccountTable();
}


void StaffForm::setupSettingsTab() {

	// OnClick() for log out button
	connect(ui.pb_logOut, SIGNAL(clicked()), this, SLOT(logOut()));

	// Populate the textView with the current user email
	ui.l_user->setText(QString::fromStdString(mStaffController->getCurrentUserEmail()));
}


void StaffForm::logOut() {

	pushToDatabase(); // Save changes to the database file

	// Switch windows
	parentWidget()->show();
	close();
}