/********************************************************************************
** Form generated from reading UI file 'RegistrationScreen.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRATIONSCREEN_H
#define UI_REGISTRATIONSCREEN_H

#include <QtCore/QVariant>
#include <QApplication>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

QT_BEGIN_NAMESPACE

class Ui_RegistrationScreen
{
public:
    QPushButton *powrot;
    QPushButton *pushButton;
    QPushButton *dodajZdjecie;
    QLabel *imieLabel;
    QLineEdit *imie;
    QLabel *hasloLabel;
    QLineEdit *haslo;
    QLabel *nazwiskoLabel;
    QLineEdit *nazwisko;
    QLabel *emailLabel;
    QLineEdit *email;
    QLabel *powtHasloLabel;
    QLineEdit *powtHaslo;

    void setupUi(QDialog *RegistrationScreen)
    {
        if (RegistrationScreen->objectName().isEmpty())
            RegistrationScreen->setObjectName(QString::fromUtf8("RegistrationScreen"));
        RegistrationScreen->resize(1024, 768);
        RegistrationScreen->setMinimumSize(QSize(1024, 768));
        RegistrationScreen->setMaximumSize(QSize(1024, 768));
        RegistrationScreen->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 13, 13);"));
        powrot = new QPushButton(RegistrationScreen);
        powrot->setObjectName(QString::fromUtf8("powrot"));
        powrot->setGeometry(QRect(153, 650, 718, 90));
        powrot->setMinimumSize(QSize(718, 90));
        powrot->setMaximumSize(QSize(718, 90));
        powrot->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 13, 13);\n"
"border-style: solid;\n"
"border-width:4px;\n"
"border-radius:30px;\n"
"border-color: white;\n"
"max-width:710px;\n"
"max-height:82px;\n"
"min-width:710px;\n"
"min-height:82px;\n"
"\n"
"font: 75 30pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));
        pushButton = new QPushButton(RegistrationScreen);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(153, 555, 718, 90));
        pushButton->setMinimumSize(QSize(718, 90));
        pushButton->setMaximumSize(QSize(718, 90));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 13, 13);\n"
"border-style: solid;\n"
"border-width:4px;\n"
"border-radius:30px;\n"
"border-color: white;\n"
"max-width:710px;\n"
"max-height:82px;\n"
"min-width:710px;\n"
"min-height:82px;\n"
"\n"
"font: 75 30pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));
        dodajZdjecie = new QPushButton(RegistrationScreen);
        dodajZdjecie->setObjectName(QString::fromUtf8("dodajZdjecie"));
        dodajZdjecie->setGeometry(QRect(153, 460, 718, 90));
        dodajZdjecie->setMinimumSize(QSize(718, 90));
        dodajZdjecie->setMaximumSize(QSize(718, 90));
        dodajZdjecie->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 13, 13);\n"
"border-style: solid;\n"
"border-width:4px;\n"
"border-radius:30px;\n"
"border-color: white;\n"
"max-width:710px;\n"
"max-height:82px;\n"
"min-width:710px;\n"
"min-height:82px;\n"
"\n"
"font: 75 30pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));
        imieLabel = new QLabel(RegistrationScreen);
        imieLabel->setObjectName(QString::fromUtf8("imieLabel"));
        imieLabel->setGeometry(QRect(153, 2, 200, 90));
        imieLabel->setMinimumSize(QSize(200, 90));
        imieLabel->setMaximumSize(QSize(200, 90));
        imieLabel->setLayoutDirection(Qt::RightToLeft);
        imieLabel->setStyleSheet(QString::fromUtf8("font: 75 30pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));
        imieLabel->setAlignment(Qt::AlignCenter);
        imie = new QLineEdit(RegistrationScreen);
        imie->setObjectName(QString::fromUtf8("imie"));
        imie->setGeometry(QRect(359, 2, 508, 90));
        imie->setMinimumSize(QSize(508, 90));
        imie->setMaximumSize(QSize(508, 90));
        imie->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"font: 75 30pt \"Tahoma\";\n"
"\n"
"border-style: solid;\n"
"border-width:4px;\n"
"border-radius:30px;\n"
""));
        hasloLabel = new QLabel(RegistrationScreen);
        hasloLabel->setObjectName(QString::fromUtf8("hasloLabel"));
        hasloLabel->setGeometry(QRect(153, 272, 200, 90));
        hasloLabel->setMinimumSize(QSize(200, 90));
        hasloLabel->setMaximumSize(QSize(200, 90));
        hasloLabel->setStyleSheet(QString::fromUtf8("font: 75 30pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));
        hasloLabel->setAlignment(Qt::AlignCenter);
        haslo = new QLineEdit(RegistrationScreen);
        haslo->setObjectName(QString::fromUtf8("haslo"));
        haslo->setGeometry(QRect(359, 272, 508, 90));
        haslo->setMinimumSize(QSize(508, 90));
        haslo->setMaximumSize(QSize(508, 90));
        haslo->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"font: 75 30pt \"Tahoma\";\n"
"\n"
"border-style: solid;\n"
"border-width:4px;\n"
"border-radius:30px;"));
        haslo->setEchoMode(QLineEdit::Password);
        nazwiskoLabel = new QLabel(RegistrationScreen);
        nazwiskoLabel->setObjectName(QString::fromUtf8("nazwiskoLabel"));
        nazwiskoLabel->setGeometry(QRect(153, 92, 200, 90));
        nazwiskoLabel->setMinimumSize(QSize(200, 90));
        nazwiskoLabel->setMaximumSize(QSize(200, 90));
        nazwiskoLabel->setStyleSheet(QString::fromUtf8("font: 75 30pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));
        nazwiskoLabel->setAlignment(Qt::AlignCenter);
        nazwisko = new QLineEdit(RegistrationScreen);
        nazwisko->setObjectName(QString::fromUtf8("nazwisko"));
        nazwisko->setGeometry(QRect(359, 92, 508, 90));
        nazwisko->setMinimumSize(QSize(508, 90));
        nazwisko->setMaximumSize(QSize(508, 90));
        nazwisko->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"font: 75 30pt \"Tahoma\";\n"
"\n"
"border-style: solid;\n"
"border-width:4px;\n"
"border-radius:30px;"));
        nazwisko->setEchoMode(QLineEdit::Normal);
        emailLabel = new QLabel(RegistrationScreen);
        emailLabel->setObjectName(QString::fromUtf8("emailLabel"));
        emailLabel->setGeometry(QRect(153, 182, 200, 90));
        emailLabel->setMinimumSize(QSize(200, 90));
        emailLabel->setMaximumSize(QSize(200, 90));
        emailLabel->setStyleSheet(QString::fromUtf8("font: 75 30pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));
        emailLabel->setAlignment(Qt::AlignCenter);
        email = new QLineEdit(RegistrationScreen);
        email->setObjectName(QString::fromUtf8("email"));
        email->setGeometry(QRect(359, 182, 508, 90));
        email->setMinimumSize(QSize(508, 90));
        email->setMaximumSize(QSize(508, 90));
        email->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"font: 75 30pt \"Tahoma\";\n"
"\n"
"border-style: solid;\n"
"border-width:4px;\n"
"border-radius:30px;"));
        email->setEchoMode(QLineEdit::Normal);
        powtHasloLabel = new QLabel(RegistrationScreen);
        powtHasloLabel->setObjectName(QString::fromUtf8("powtHasloLabel"));
        powtHasloLabel->setGeometry(QRect(154, 362, 200, 90));
        powtHasloLabel->setMinimumSize(QSize(200, 90));
        powtHasloLabel->setMaximumSize(QSize(200, 90));
        powtHasloLabel->setStyleSheet(QString::fromUtf8("font: 75 18pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));
        powtHasloLabel->setAlignment(Qt::AlignCenter);
        powtHaslo = new QLineEdit(RegistrationScreen);
        powtHaslo->setObjectName(QString::fromUtf8("powtHaslo"));
        powtHaslo->setGeometry(QRect(360, 362, 508, 90));
        powtHaslo->setMinimumSize(QSize(508, 90));
        powtHaslo->setMaximumSize(QSize(508, 90));
        powtHaslo->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"font: 75 30pt \"Tahoma\";\n"
"\n"
"border-style: solid;\n"
"border-width:4px;\n"
"border-radius:30px;"));
        powtHaslo->setEchoMode(QLineEdit::Password);

        retranslateUi(RegistrationScreen);

        QMetaObject::connectSlotsByName(RegistrationScreen);
    } // setupUi

    void retranslateUi(QDialog *RegistrationScreen)
    {
        RegistrationScreen->setWindowTitle(QCoreApplication::translate("RegistrationScreen", "Dialog", nullptr));
        powrot->setText(QCoreApplication::translate("RegistrationScreen", "POWR\303\223T", nullptr));
        pushButton->setText(QCoreApplication::translate("RegistrationScreen", "ZAREJESTRUJ", nullptr));
        dodajZdjecie->setText(QCoreApplication::translate("RegistrationScreen", "DODAJ ZDJ\304\230CIE", nullptr));
        imieLabel->setText(QCoreApplication::translate("RegistrationScreen", "IMI\304\230", nullptr));
        hasloLabel->setText(QCoreApplication::translate("RegistrationScreen", "HAS\305\201O", nullptr));
        nazwiskoLabel->setText(QCoreApplication::translate("RegistrationScreen", "NAZWISKO", nullptr));
        emailLabel->setText(QCoreApplication::translate("RegistrationScreen", "EMAIL", nullptr));
        powtHasloLabel->setText(QCoreApplication::translate("RegistrationScreen", "POWT\303\223RZ HAS\305\201O", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegistrationScreen: public Ui_RegistrationScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATIONSCREEN_H
