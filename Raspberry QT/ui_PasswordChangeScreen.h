/********************************************************************************
** Form generated from reading UI file 'PasswordChangeScreen.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSWORDCHANGESCREEN_H
#define UI_PASSWORDCHANGESCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_PasswordChangeScreen
{
public:
    QPushButton *potwierdz;
    QLabel *forma;
    QLabel *kupujesz;
    QPushButton *close;
    QLabel *forma_2;
    QLineEdit *oldPassword;
    QLineEdit *newPassword;
    QLineEdit *newPassword2;
    QPushButton *pushButton;

    void setupUi(QDialog *PasswordChangeScreen)
    {
        if (PasswordChangeScreen->objectName().isEmpty())
            PasswordChangeScreen->setObjectName(QString::fromUtf8("PasswordChangeScreen"));
        PasswordChangeScreen->setWindowModality(Qt::NonModal);
        PasswordChangeScreen->resize(1024, 768);
        PasswordChangeScreen->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 13, 13);\n"
""));
        potwierdz = new QPushButton(PasswordChangeScreen);
        potwierdz->setObjectName(QString::fromUtf8("potwierdz"));
        potwierdz->setGeometry(QRect(312, 434, 400, 90));
        potwierdz->setMinimumSize(QSize(0, 0));
        potwierdz->setMaximumSize(QSize(16777215, 16777215));
        potwierdz->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 13, 13);\n"
"border-style: solid;\n"
"border-width:4px;\n"
"border-radius:30px;\n"
"border-color: white;\n"
"\n"
"font: 75 30pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));
        forma = new QLabel(PasswordChangeScreen);
        forma->setObjectName(QString::fromUtf8("forma"));
        forma->setGeometry(QRect(172, 200, 300, 90));
        forma->setMinimumSize(QSize(300, 90));
        forma->setMaximumSize(QSize(300, 90));
        forma->setLayoutDirection(Qt::RightToLeft);
        forma->setStyleSheet(QString::fromUtf8("border-style: none;\n"
"font: 75 30pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));
        forma->setAlignment(Qt::AlignCenter);
        kupujesz = new QLabel(PasswordChangeScreen);
        kupujesz->setObjectName(QString::fromUtf8("kupujesz"));
        kupujesz->setGeometry(QRect(172, 100, 300, 90));
        kupujesz->setMinimumSize(QSize(300, 90));
        kupujesz->setMaximumSize(QSize(300, 90));
        kupujesz->setLayoutDirection(Qt::RightToLeft);
        kupujesz->setStyleSheet(QString::fromUtf8("font: 75 30pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);\n"
"border-style: none;"));
        kupujesz->setAlignment(Qt::AlignCenter);
        close = new QPushButton(PasswordChangeScreen);
        close->setObjectName(QString::fromUtf8("close"));
        close->setGeometry(QRect(312, 554, 400, 90));
        close->setMinimumSize(QSize(0, 0));
        close->setMaximumSize(QSize(16777215, 16777215));
        close->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 13, 13);\n"
"border-style: solid;\n"
"border-width:4px;\n"
"border-radius:30px;\n"
"border-color: white;\n"
"\n"
"font: 75 30pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));
        forma_2 = new QLabel(PasswordChangeScreen);
        forma_2->setObjectName(QString::fromUtf8("forma_2"));
        forma_2->setGeometry(QRect(167, 300, 300, 90));
        forma_2->setMinimumSize(QSize(300, 90));
        forma_2->setMaximumSize(QSize(300, 90));
        forma_2->setLayoutDirection(Qt::RightToLeft);
        forma_2->setStyleSheet(QString::fromUtf8("border-style: none;\n"
"font: 75 19pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));
        forma_2->setAlignment(Qt::AlignCenter);
        oldPassword = new QLineEdit(PasswordChangeScreen);
        oldPassword->setObjectName(QString::fromUtf8("oldPassword"));
        oldPassword->setGeometry(QRect(469, 100, 385, 90));
        oldPassword->setMinimumSize(QSize(385, 90));
        oldPassword->setMaximumSize(QSize(385, 90));
        oldPassword->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"font: 75 30pt \"Tahoma\";\n"
"\n"
"border-style: none;\n"
"border-width:4px;\n"
"border-radius:30px;"));
        oldPassword->setEchoMode(QLineEdit::Password);
        newPassword = new QLineEdit(PasswordChangeScreen);
        newPassword->setObjectName(QString::fromUtf8("newPassword"));
        newPassword->setGeometry(QRect(469, 200, 385, 90));
        newPassword->setMinimumSize(QSize(385, 90));
        newPassword->setMaximumSize(QSize(385, 90));
        newPassword->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"font: 75 30pt \"Tahoma\";\n"
"\n"
"border-style: none;\n"
"border-width:4px;\n"
"border-radius:30px;"));
        newPassword->setEchoMode(QLineEdit::Password);
        newPassword2 = new QLineEdit(PasswordChangeScreen);
        newPassword2->setObjectName(QString::fromUtf8("newPassword2"));
        newPassword2->setGeometry(QRect(469, 300, 385, 90));
        newPassword2->setMinimumSize(QSize(385, 90));
        newPassword2->setMaximumSize(QSize(385, 90));
        newPassword2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"font: 75 30pt \"Tahoma\";\n"
"\n"
"border-style: none;\n"
"border-width:4px;\n"
"border-radius:30px;"));
        newPassword2->setEchoMode(QLineEdit::Password);
        pushButton = new QPushButton(PasswordChangeScreen);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(162, 84, 700, 600));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 13, 13);\n"
"border-style: solid;\n"
"border-width:4px;\n"
"border-radius:30px;\n"
"border-color:  rgb(218, 0, 0);;"));
        pushButton->raise();
        potwierdz->raise();
        forma->raise();
        kupujesz->raise();
        close->raise();
        forma_2->raise();
        oldPassword->raise();
        newPassword->raise();
        newPassword2->raise();

        retranslateUi(PasswordChangeScreen);

        QMetaObject::connectSlotsByName(PasswordChangeScreen);
    } // setupUi

    void retranslateUi(QDialog *PasswordChangeScreen)
    {
        PasswordChangeScreen->setWindowTitle(QCoreApplication::translate("PasswordChangeScreen", "Dialog", nullptr));
        potwierdz->setText(QCoreApplication::translate("PasswordChangeScreen", "POTWIERD\305\271", nullptr));
        forma->setText(QCoreApplication::translate("PasswordChangeScreen", "NOWE HAS\305\201O:", nullptr));
        kupujesz->setText(QCoreApplication::translate("PasswordChangeScreen", "STARE HAS\305\201O:", nullptr));
        close->setText(QCoreApplication::translate("PasswordChangeScreen", "ANULUJ", nullptr));
        forma_2->setText(QCoreApplication::translate("PasswordChangeScreen", "POWT\303\223RZ NOWE HAS\305\201O:", nullptr));
        pushButton->setText(QCoreApplication::translate("PasswordChangeScreen", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PasswordChangeScreen: public Ui_PasswordChangeScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSWORDCHANGESCREEN_H
