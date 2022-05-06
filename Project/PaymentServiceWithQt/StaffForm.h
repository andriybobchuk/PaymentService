#pragma once

#include <QWidget>
#include "ui_StaffForm.h"

class StaffForm : public QWidget
{
	Q_OBJECT

public:
	StaffForm(QWidget* parent = Q_NULLPTR);
	~StaffForm();

private:
	Ui::StaffForm ui;

private slots:
	void logOut();
	void approveById(int id);
};
