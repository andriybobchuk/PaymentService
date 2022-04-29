/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QWidget *line;
    QLineEdit *lineEdit_2;
    QWidget *line_2;
    QPushButton *btn_signin;
    QGroupBox *groupBox_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *le_username_su;
    QWidget *line_3;
    QLineEdit *le_password_su;
    QWidget *line_4;
    QPushButton *btn_signup;
    QLineEdit *le_email_su;
    QWidget *line_5;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(805, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8("icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8("#centralWidget {\n"
"\n"
"background: rgb(248, 248, 248)\n"
"\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QPalette palette;
        centralwidget->setPalette(palette);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(100, 90, 281, 361));
        groupBox->setStyleSheet(QString::fromUtf8("#groupBox {\n"
"\n"
"background: #FFFFFF\n"
"\n"
"}"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 40, 181, 51));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        label->setFont(font);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 90, 181, 41));
        QFont font1;
        font1.setPointSize(9);
        font1.setBold(false);
        label_2->setFont(font1);
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(50, 150, 181, 26));
        lineEdit->setFrame(false);
        line = new QWidget(groupBox);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(50, 180, 181, 1));
        line->setStyleSheet(QString::fromUtf8("#line {\n"
"\n"
"background:#e0e0e0\n"
"\n"
"}"));
        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(50, 200, 181, 26));
        lineEdit_2->setFrame(false);
        lineEdit_2->setEchoMode(QLineEdit::Password);
        line_2 = new QWidget(groupBox);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(50, 230, 181, 1));
        line_2->setStyleSheet(QString::fromUtf8("#line_2 {\n"
"\n"
"background:#e0e0e0\n"
"\n"
"}"));
        btn_signin = new QPushButton(groupBox);
        btn_signin->setObjectName(QString::fromUtf8("btn_signin"));
        btn_signin->setGeometry(QRect(50, 270, 181, 29));
        QFont font2;
        font2.setBold(true);
        btn_signin->setFont(font2);
        btn_signin->setStyleSheet(QString::fromUtf8("#btn_signin {\n"
"\n"
"background-color: #000000;\n"
"color: #FFFFFF;\n"
"border: none\n"
"\n"
"}"));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(420, 90, 281, 431));
        groupBox_2->setStyleSheet(QString::fromUtf8("#groupBox_2 {\n"
"\n"
"background: #FFFFFF\n"
"\n"
"}"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 40, 181, 51));
        label_3->setFont(font);
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(50, 90, 201, 41));
        label_4->setFont(font1);
        le_username_su = new QLineEdit(groupBox_2);
        le_username_su->setObjectName(QString::fromUtf8("le_username_su"));
        le_username_su->setGeometry(QRect(50, 150, 171, 26));
        le_username_su->setFrame(false);
        line_3 = new QWidget(groupBox_2);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(50, 180, 181, 1));
        line_3->setStyleSheet(QString::fromUtf8("#line_3 {\n"
"\n"
"background:#e0e0e0\n"
"\n"
"}"));
        le_password_su = new QLineEdit(groupBox_2);
        le_password_su->setObjectName(QString::fromUtf8("le_password_su"));
        le_password_su->setGeometry(QRect(50, 200, 221, 26));
        le_password_su->setFrame(false);
        le_password_su->setEchoMode(QLineEdit::Password);
        line_4 = new QWidget(groupBox_2);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(50, 230, 181, 1));
        line_4->setStyleSheet(QString::fromUtf8("#line_4 {\n"
"\n"
"background:#e0e0e0\n"
"\n"
"}"));
        btn_signup = new QPushButton(groupBox_2);
        btn_signup->setObjectName(QString::fromUtf8("btn_signup"));
        btn_signup->setGeometry(QRect(50, 330, 181, 29));
        btn_signup->setFont(font2);
        btn_signup->setStyleSheet(QString::fromUtf8("#btn_signup {\n"
"\n"
"background-color: #000000;\n"
"color: #FFFFFF;\n"
"border: none\n"
"\n"
"}"));
        le_email_su = new QLineEdit(groupBox_2);
        le_email_su->setObjectName(QString::fromUtf8("le_email_su"));
        le_email_su->setGeometry(QRect(50, 250, 221, 26));
        le_email_su->setFrame(false);
        line_5 = new QWidget(groupBox_2);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setGeometry(QRect(50, 280, 181, 1));
        line_5->setStyleSheet(QString::fromUtf8("#line_5 {\n"
"\n"
"background:#e0e0e0\n"
"\n"
"}"));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Login/Register", nullptr));
        groupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Sign In", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Log in to your account", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        btn_signin->setText(QCoreApplication::translate("MainWindow", "Sign In", nullptr));
        groupBox_2->setTitle(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "Sign Up", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Create a brand new account", nullptr));
        le_username_su->setPlaceholderText(QCoreApplication::translate("MainWindow", "Username", nullptr));
        le_password_su->setPlaceholderText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        btn_signup->setText(QCoreApplication::translate("MainWindow", "Sign Up", nullptr));
        le_email_su->setPlaceholderText(QCoreApplication::translate("MainWindow", "Email", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
