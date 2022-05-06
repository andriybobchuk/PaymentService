#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_PaymentServiceWithQt.h"
#include "controller.h"

class PaymentServiceWithQt : public QMainWindow, private Ui::PaymentServiceWithQtClass 
{
    Q_OBJECT

public:
    PaymentServiceWithQt(QWidget *parent = Q_NULLPTR);

private:
    Ui::PaymentServiceWithQtClass ui;



private slots:
    void onClickSignUpClient();
    void onClickSignInClient();
    void onClickSignInStaff();



};
