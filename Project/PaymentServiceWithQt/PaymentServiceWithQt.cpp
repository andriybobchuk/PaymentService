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

PaymentServiceWithQt::~PaymentServiceWithQt() {
    delete clientForm;
    delete mEntryController;
}

void PaymentServiceWithQt::onClickSignUpClient() {
    QString username = ui.le_clientSignUpUsername->text();
    QString password = ui.le_clientSignUpPassword->text();
    QString email = ui.le_clientSignUpEmail->text();

    ui.l_clientSignUpError->setVisible(true);

    if (
        isPasswordSecure(password.toStdString())
        && isEmailValid(email.toStdString())
        ) {

        // Actual registering of a client
        if (!mEntryController->signUpClient(
            username.toStdString(),
            password.toStdString(),
            email.toStdString())) {
            ui.l_clientSignUpError->setText("Account with this email exists!");
        }
        else {
            // Clearing edit text fields
            ui.le_clientSignUpUsername->clear();
            ui.le_clientSignUpPassword->clear();
            ui.le_clientSignUpEmail->clear();

            ui.l_clientSignUpError->setText("Success, now wait for the approval.");
        }
    }
    else if (!isPasswordSecure(password.toStdString())) {
        ui.l_clientSignUpError->setText("Your password isn't secure!");
    }
    else if (!isEmailValid(email.toStdString())) {
        ui.l_clientSignUpError->setText("Invalid email address!");
    }
}


void PaymentServiceWithQt::onClickSignInClient() {
    QString login = ui.le_clientSignInLogin->text();
    QString password = ui.le_clientSignInPassword->text();

    if (mEntryController->signInClient(login.toStdString(), password.toStdString())) {
        
        // Clearing edit text fields
        ui.le_clientSignInLogin->clear();
        ui.le_clientSignInPassword->clear();
    }
    else {
        ui.l_clientSignInError->setVisible(true);
    }
}


void PaymentServiceWithQt::onClickSignInStaff() {
    QString login = ui.le_staffSignInLogin->text();
    QString password = ui.le_staffSignInPassword->text();

    if (mEntryController->signInStaff(login.toStdString(), password.toStdString())) {

        // Clearing edit text fields
        ui.le_staffSignInLogin->clear();
        ui.le_staffSignInPassword->clear();
    }
    else {
        ui.l_staffSignInError->setVisible(true);
    }
}

