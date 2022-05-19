#include "PaymentServiceWithQt.h"


PaymentServiceWithQt::PaymentServiceWithQt(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

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

    
    Client* currentUser = signInClient(login.toStdString(), password.toStdString());
    if (currentUser != nullptr) {
        clientForm = new ClientForm(this, currentUser);
        clientForm->show();
    }
    else {
        ui.l_clientSignInError->setVisible(true);
    }
    
}


void PaymentServiceWithQt::onClickSignInStaff() {
    QString login = ui.le_staffSignInLogin->text();
    QString password = ui.le_staffSignInPassword->text();

    Staff* admin = signInStaff(login.toStdString(), password.toStdString());
    if (admin != nullptr) {
        StaffForm* staffForm = new StaffForm(this, admin);
        staffForm->show();
    }
    else {
        ui.l_staffSignInError->setVisible(true);
    }
}

