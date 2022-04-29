#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_PaymentServiceWithQt.h"

class PaymentServiceWithQt : public QMainWindow
{
    Q_OBJECT

public:
    PaymentServiceWithQt(QWidget *parent = Q_NULLPTR);

private:
    Ui::PaymentServiceWithQtClass ui;
};
