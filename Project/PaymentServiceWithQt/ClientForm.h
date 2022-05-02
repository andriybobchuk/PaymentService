#pragma once

#include <QWidget>
#include "ui_ClientForm.h"

class ClientForm : public QWidget
{
	Q_OBJECT

public:
	ClientForm(QWidget *parent = Q_NULLPTR);
	~ClientForm();

private:
	Ui::ClientForm ui;

private slots:
	void logOut();

};
