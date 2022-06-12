#pragma once

#include <QDialog>
#include "ui_AccountCreatorDialog.h"

class AccountCreatorDialog : public QDialog
{
	Q_OBJECT

public:
	AccountCreatorDialog(QWidget *parent = Q_NULLPTR);
	~AccountCreatorDialog();

private:
	Ui::AccountCreatorDialog ui;
};
