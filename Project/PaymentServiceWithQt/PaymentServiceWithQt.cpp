#include "PaymentServiceWithQt.h"


PaymentServiceWithQt::PaymentServiceWithQt(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    mEntryController = new EntryController(this);

    ui.pb_clientSignUp->setAutoDefault(false);
    connect(ui.pb_clientSignUp, SIGNAL(clicked()), this, SLOT(onClickSignUpClient()));
    connect(ui.pb_clientSignIn, SIGNAL(clicked()), this, SLOT(onClickSignInClient()));
    connect(ui.pb_staffSignIn, SIGNAL(clicked()), this, SLOT(onClickSignInStaff()));

    ui.l_clientSignInError->setVisible(false);
    ui.l_clientSignUpError->setVisible(false);
    ui.l_staffSignInError->setVisible(false);

}

void PaymentServiceWithQt::onClickSignUpClient() {
    QString username = ui.le_clientSignUpUsername->text();
    QString password = ui.le_clientSignUpPassword->text();
    QString email = ui.le_clientSignUpEmail->text();


    // Now controller takes care of it and tells if registartion went successful.
    if (mEntryController->signUpClient(
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

    if (!mEntryController->signInClient(login.toStdString(), password.toStdString())) {
        ui.l_clientSignInError->setVisible(true);
    }
}


void PaymentServiceWithQt::onClickSignInStaff() {
    QString login = ui.le_staffSignInLogin->text();
    QString password = ui.le_staffSignInPassword->text();

    if (!mEntryController->signInStaff(login.toStdString(), password.toStdString())) {
        ui.l_staffSignInError->setVisible(true);
    }
}

