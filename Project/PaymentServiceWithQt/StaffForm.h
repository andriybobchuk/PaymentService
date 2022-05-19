#pragma once

#include <QWidget>
#include "ui_StaffForm.h"
#include <QDialog.h>
#include <QHeaderView>
#include "PaymentServiceWithQt.h"
#include <QHBoxLayout>
#include "constants.h"

class StaffForm : public QDialog
{
	Q_OBJECT

public:
	StaffForm(QWidget* parent = Q_NULLPTR, Staff* admin = nullptr);
	~StaffForm();

	Staff* mAdmin;

private:
	Ui::StaffForm ui;

private slots:
	void approveById(int id);
	void banById(int id);
	void setupActionButton(int it);
	void setupAccountTable();
	void logOut();
	void setupSettingsTab();
};
