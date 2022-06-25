#pragma once

#include <QDialog>
#include "ui_AccountCreatorDialog.h"
#include "util.h"
#include "ClientController.h"
#include "ClientForm.h"
#include "constants.h"

class AccountCreatorDialog : public QDialog
{
	Q_OBJECT

public:
	AccountCreatorDialog(QWidget *parent = Q_NULLPTR, 
		ClientController* clientController = nullptr
	);
	~AccountCreatorDialog();

	ClientController* mClientController;


private:
	Ui::AccountCreatorDialog ui;

private slots:

	void onClickCreateAccount();

};
