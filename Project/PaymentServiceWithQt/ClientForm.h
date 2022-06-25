#pragma once

#include <QWidget>
#include <QDialog.h>
#include <QHeaderView>
#include <QHBoxLayout>
#include "ui_ClientForm.h"
#include "ClientController.h"
#include "constants.h"
#include "util.h"

#include "ui_AccountCreatorDialog.h"
#include "AccountCreatorDialog.h"


class ClientForm : public QDialog
{
	Q_OBJECT

public:
	ClientForm(QWidget *parent = Q_NULLPTR, ClientController* clientController = nullptr);
	~ClientForm();

	ClientController* mClientController;
	
private:
	Ui::ClientForm ui;

private slots:

	void recalculateBalances();

	void issueDebtReport();

	void setupAccountTab();

	void setupAccountTable();
	
	void setupTableActionButton(int id, std::vector<std::string>);

	void onClickTransferMoney();

	void onClickAddOwner();

	void onClickSuspend();

	void setupSettingsTab();

	void onClickCreateAccount();

	void logOut();


};
