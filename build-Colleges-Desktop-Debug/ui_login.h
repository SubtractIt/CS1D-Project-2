/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QLabel *userLabel;
    QLabel *passLabel;
    QLineEdit *user;
    QLineEdit *pass;
    QPushButton *login;
    QLabel *label;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(400, 300);
        userLabel = new QLabel(Login);
        userLabel->setObjectName(QString::fromUtf8("userLabel"));
        userLabel->setGeometry(QRect(70, 100, 81, 21));
        QFont font;
        font.setPointSize(12);
        userLabel->setFont(font);
        passLabel = new QLabel(Login);
        passLabel->setObjectName(QString::fromUtf8("passLabel"));
        passLabel->setGeometry(QRect(70, 130, 81, 21));
        passLabel->setFont(font);
        user = new QLineEdit(Login);
        user->setObjectName(QString::fromUtf8("user"));
        user->setGeometry(QRect(150, 100, 181, 25));
        user->setFont(font);
        pass = new QLineEdit(Login);
        pass->setObjectName(QString::fromUtf8("pass"));
        pass->setGeometry(QRect(150, 130, 181, 25));
        pass->setFont(font);
        pass->setEchoMode(QLineEdit::Password);
        login = new QPushButton(Login);
        login->setObjectName(QString::fromUtf8("login"));
        login->setGeometry(QRect(240, 180, 89, 25));
        login->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/login.png"), QSize(), QIcon::Normal, QIcon::Off);
        login->setIcon(icon);
        label = new QLabel(Login);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 50, 201, 21));
        label->setFont(font);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Dialog", nullptr));
        userLabel->setText(QApplication::translate("Login", "Username: ", nullptr));
        passLabel->setText(QApplication::translate("Login", "Password:", nullptr));
        login->setText(QApplication::translate("Login", "Login", nullptr));
        label->setText(QApplication::translate("Login", "Enter Login Information: ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
