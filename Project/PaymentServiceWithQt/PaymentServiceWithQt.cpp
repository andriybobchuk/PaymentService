#include "PaymentServiceWithQt.h"
#include "../MoneyTransferApp/controller.h"
#include "ClientForm.h"
#include "StaffForm.h"

PaymentServiceWithQt::PaymentServiceWithQt(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    ui.pb_clientSignUp->setAutoDefault(false);
    connect(ui.pb_clientSignUp, SIGNAL(clicked()), this, SLOT(signUpClient()));
    connect(ui.pb_clientSignIn, SIGNAL(clicked()), this, SLOT(signInClient()));
    connect(ui.pb_staffSignIn, SIGNAL(clicked()), this, SLOT(signInStaff()));

    ui.l_clientSignInError->setVisible(false);
    ui.l_clientSignUpError->setVisible(false);
    ui.l_staffSignInError->setVisible(false);

}

void PaymentServiceWithQt::signUpClient() {
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


void PaymentServiceWithQt::signInClient() {
    QString login = ui.le_clientSignInLogin->text();
    QString password = ui.le_clientSignUpPassword->text();

    ClientForm* clientForm = new ClientForm();
    clientForm->show();
    close();//this will disappear main window
}


void PaymentServiceWithQt::signInStaff() {


    StaffForm* staffForm = new StaffForm();
    staffForm->show();
    close();//this will disappear main window

}

