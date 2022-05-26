#pragma once

#include <QWidget>
#include <QDialog.h>
#include "ui_ClientForm.h"

#include "ClientController.h"
#include "constants.h"
#include "util.h"


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
	void setupCreateAccountPanel();
	void logOut();
	void setupAccountTable();
	void setupSettingsTab();
	void registerAccount();

};
