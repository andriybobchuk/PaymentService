#pragma once

#include <QWidget>
#include "ui_ClientForm.h"
#include "controller.h"
#include "BaseUser.h"
#include <QDialog.h>


class ClientForm : public QDialog
{
	Q_OBJECT

public:
	ClientForm(QWidget *parent = Q_NULLPTR, Client* currentUser = nullptr);
	~ClientForm();

	Client* mCurrentUser;
	
private:
	Ui::ClientForm ui;

private slots:
	void logOut();
	void displayAccountList();
	void setupSettingsTab();
	void registerAccount();

};
