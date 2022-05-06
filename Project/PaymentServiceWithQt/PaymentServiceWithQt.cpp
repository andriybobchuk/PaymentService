#include "PaymentServiceWithQt.h"
#include "../MoneyTransferApp/controller.h"
#include "ClientForm.h"
#include "StaffForm.h"
#include "database.h"
#include "constants.h"

PaymentServiceWithQt::PaymentServiceWithQt(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    ui.pb_clientSignUp->setAutoDefault(false);
    connect(ui.pb_clientSignUp, SIGNAL(clicked()), this, SLOT(onClickSignUpClient()));
    connect(ui.pb_clientSignIn, SIGNAL(clicked()), this, SLOT(onClickSignInClient()));
    connect(ui.pb_staffSignIn, SIGNAL(clicked()), this, SLOT(onClickSignInStaff()));

    ui.l_clientSignInError->setVisible(false);
    //ui.l_clientSignInError->setText(QString::fromStdString("c:" + PaymentService::getInstance()->getClients().size()));
    ui.l_clientSignUpError->setVisible(false);
    ui.l_staffSignInError->setVisible(false);

}

void PaymentServiceWithQt::onClickSignUpClient() {
    QString username = ui.le_clientSignUpUsername->text();
    QString password = ui.le_clientSignUpPassword->text();
    QString email = ui.le_clientSignUpEmail->text();


    if (signUp(
        username.toStdString(), 
        password.toStdString(), 
        email.toStdString())) {

        ui.l_clientSignUpError->setVisible(true);
        ui.l_clientSignUpError->setText("Success, now wait for the approval.");

    } else {
        ui.l_clientSignUpError->setVisible(true);
        ui.l_clientSignUpError->setText("Unappropriate email or password!");
    }
}


void PaymentServiceWithQt::onClickSignInClient() {
    QString login = ui.le_clientSignInLogin->text();
    QString password = ui.le_clientSignInPassword->text();

    if (signInClient(login.toStdString(), password.toStdString())) {
        ClientForm* clientForm = new ClientForm();
        clientForm->show();
        close();//this will disappear main window
    }
    else {
        ui.l_clientSignInError->setVisible(true);
    }
    
}


void PaymentServiceWithQt::onClickSignInStaff() {
    QString login = ui.le_staffSignInLogin->text();
    QString password = ui.le_staffSignInPassword->text();

    if (signInStaff(login.toStdString(),password.toStdString())) {

        StaffForm* staffForm = new StaffForm();
        staffForm->show();
        close();//this will disappear main window
    }
    else {
        ui.l_staffSignInError->setVisible(true);
    }
}

