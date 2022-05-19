#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_PaymentServiceWithQt.h"
#include "ClientForm.h"
#include "StaffForm.h"
#include "database.h"
#include "constants.h"

class PaymentServiceWithQt : public QMainWindow, private Ui::PaymentServiceWithQtClass 
{
    Q_OBJECT

public:
    PaymentServiceWithQt(QWidget *parent = Q_NULLPTR);

private:
    Ui::PaymentServiceWithQtClass ui;
    ClientForm* clientForm;



private slots:
    void onClickSignUpClient();
    void onClickSignInClient();
    void onClickSignInStaff();



};
