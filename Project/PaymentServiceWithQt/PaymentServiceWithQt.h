#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_PaymentServiceWithQt.h"

class PaymentServiceWithQt : public QMainWindow, private Ui::PaymentServiceWithQtClass 
{
    Q_OBJECT

public:
    PaymentServiceWithQt(QWidget *parent = Q_NULLPTR);

private:
    Ui::PaymentServiceWithQtClass ui;



private slots:
    void signUpClient();
    void signInClient();
    void signInStaff();



};
