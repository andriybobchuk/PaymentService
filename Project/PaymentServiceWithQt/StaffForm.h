#pragma once

#include <QWidget>
#include "ui_StaffForm.h"
#include <QDialog.h>
#include <QHeaderView>
#include <QHBoxLayout>

#include "StaffController.h"
#include "constants.h"
#include "util.h"


class StaffForm : public QDialog
{
	Q_OBJECT

public:
	StaffForm(QWidget* parent = Q_NULLPTR, StaffController* staffController = nullptr);
	~StaffForm();

private:
	Ui::StaffForm ui;
	StaffController* mStaffController;

private slots:
	void approveById(int id);
	void banById(int id);
	void setupActionButton(int it);
	void setupAccountTable();
	void logOut();
	void setupSettingsTab();
};
