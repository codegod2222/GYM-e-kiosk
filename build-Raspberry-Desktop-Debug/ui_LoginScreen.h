/********************************************************************************
** Form generated from reading UI file 'LoginScreen.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINSCREEN_H
#define UI_LOGINSCREEN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginScreen
{
public:
    QPushButton *zaloguj;
    QPushButton *powrot;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *login;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *password;
    QLabel *komunikat;

    void setupUi(QDialog *LoginScreen)
    {
        if (LoginScreen->objectName().isEmpty())
            LoginScreen->setObjectName(QString::fromUtf8("LoginScreen"));
        LoginScreen->resize(1024, 768);
        LoginScreen->setMinimumSize(QSize(1024, 768));
        LoginScreen->setMaximumSize(QSize(1024, 768));
        QFont font;
        font.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        LoginScreen->setFont(font);
        LoginScreen->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 13, 13);"));
        zaloguj = new QPushButton(LoginScreen);
        zaloguj->setObjectName(QString::fromUtf8("zaloguj"));
        zaloguj->setGeometry(QRect(157, 250, 718, 108));
        zaloguj->setMinimumSize(QSize(718, 108));
        zaloguj->setMaximumSize(QSize(718, 108));
        zaloguj->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 13, 13);\n"
"border-style: solid;\n"
"border-width:4px;\n"
"border-radius:30px;\n"
"border-color: white;\n"
"max-width:710px;\n"
"max-height:100px;\n"
"min-width:710px;\n"
"min-height:100px;\n"
"\n"
"font: 75 30pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));
        powrot = new QPushButton(LoginScreen);
        powrot->setObjectName(QString::fromUtf8("powrot"));
        powrot->setGeometry(QRect(157, 370, 718, 108));
        powrot->setMinimumSize(QSize(718, 108));
        powrot->setMaximumSize(QSize(718, 108));
        powrot->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 13, 13);\n"
"border-style: solid;\n"
"border-width:4px;\n"
"border-radius:30px;\n"
"border-color: white;\n"
"max-width:710px;\n"
"max-height:100px;\n"
"min-width:710px;\n"
"min-height:100px;\n"
"\n"
"font: 75 30pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));
        layoutWidget = new QWidget(LoginScreen);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(160, 30, 711, 212));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(130, 100));
        label->setMaximumSize(QSize(130, 100));
        label->setLayoutDirection(Qt::RightToLeft);
        label->setStyleSheet(QString::fromUtf8("font: 75 30pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        login = new QLineEdit(layoutWidget);
        login->setObjectName(QString::fromUtf8("login"));
        login->setMinimumSize(QSize(0, 100));
        login->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"font: 75 30pt \"Tahoma\";\n"
"\n"
"border-style: solid;\n"
"border-width:4px;\n"
"border-radius:30px;"));

        horizontalLayout->addWidget(login);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(130, 100));
        label_2->setMaximumSize(QSize(130, 100));
        label_2->setStyleSheet(QString::fromUtf8("font: 75 30pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_2);

        password = new QLineEdit(layoutWidget);
        password->setObjectName(QString::fromUtf8("password"));
        password->setMinimumSize(QSize(0, 100));
        password->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"font: 75 30pt \"Tahoma\";\n"
"\n"
"border-style: solid;\n"
"border-width:4px;\n"
"border-radius:30px;"));
        password->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(password);


        verticalLayout->addLayout(horizontalLayout_2);

        komunikat = new QLabel(LoginScreen);
        komunikat->setObjectName(QString::fromUtf8("komunikat"));
        komunikat->setGeometry(QRect(157, 490, 718, 81));
        komunikat->setStyleSheet(QString::fromUtf8("font: 75 30pt \"Tahoma\";\n"
"color: rgb(218, 0, 0);"));
        komunikat->setAlignment(Qt::AlignCenter);
        layoutWidget->raise();
        zaloguj->raise();
        powrot->raise();
        komunikat->raise();

        retranslateUi(LoginScreen);

        QMetaObject::connectSlotsByName(LoginScreen);
    } // setupUi

    void retranslateUi(QDialog *LoginScreen)
    {
        LoginScreen->setWindowTitle(QApplication::translate("LoginScreen", "Dialog", 0, QApplication::UnicodeUTF8));
        zaloguj->setText(QApplication::translate("LoginScreen", "ZALOGUJ", 0, QApplication::UnicodeUTF8));
        powrot->setText(QApplication::translate("LoginScreen", "POWR\303\223T", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("LoginScreen", "LOGIN", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("LoginScreen", "HAS\305\201O", 0, QApplication::UnicodeUTF8));
        komunikat->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LoginScreen: public Ui_LoginScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINSCREEN_H
