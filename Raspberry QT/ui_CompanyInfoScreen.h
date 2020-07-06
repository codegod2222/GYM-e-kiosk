/********************************************************************************
** Form generated from reading UI file 'CompanyInfoScreen.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMPANYINFOSCREEN_H
#define UI_COMPANYINFOSCREEN_H

#include <QtCore/QVariant>
#include <QApplication>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

QT_BEGIN_NAMESPACE

class Ui_CompanyInfoScreen
{
public:
    QLineEdit *nip;
    QPushButton *zatwierdzZmiany;
    QLabel *adresLabel;
    QPushButton *powrot;
    QLineEdit *adres;
    QLineEdit *nazwa;
    QLabel *nazwaLabel;
    QLabel *nipLabel;

    void setupUi(QDialog *CompanyInfoScreen)
    {
        if (CompanyInfoScreen->objectName().isEmpty())
            CompanyInfoScreen->setObjectName(QString::fromUtf8("CompanyInfoScreen"));
        CompanyInfoScreen->setWindowModality(Qt::NonModal);
        CompanyInfoScreen->resize(1024, 768);
        CompanyInfoScreen->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 13, 13);"));
        CompanyInfoScreen->setModal(false);
        nip = new QLineEdit(CompanyInfoScreen);
        nip->setObjectName(QString::fromUtf8("nip"));
        nip->setGeometry(QRect(369, 170, 508, 90));
        nip->setMinimumSize(QSize(508, 90));
        nip->setMaximumSize(QSize(508, 90));
        nip->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"font: 75 30pt \"Tahoma\";\n"
"\n"
"border-style: solid;\n"
"border-width:4px;\n"
"border-radius:30px;\n"
"\n"
"max-width:500px;\n"
"max-height:82px;\n"
"min-width:500px;\n"
"min-height:82px;"));
        nip->setEchoMode(QLineEdit::Normal);
        zatwierdzZmiany = new QPushButton(CompanyInfoScreen);
        zatwierdzZmiany->setObjectName(QString::fromUtf8("zatwierdzZmiany"));
        zatwierdzZmiany->setGeometry(QRect(153, 360, 718, 90));
        zatwierdzZmiany->setMinimumSize(QSize(718, 90));
        zatwierdzZmiany->setMaximumSize(QSize(718, 90));
        zatwierdzZmiany->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 13, 13);\n"
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
        adresLabel = new QLabel(CompanyInfoScreen);
        adresLabel->setObjectName(QString::fromUtf8("adresLabel"));
        adresLabel->setGeometry(QRect(153, 260, 200, 90));
        adresLabel->setMinimumSize(QSize(200, 90));
        adresLabel->setMaximumSize(QSize(200, 90));
        adresLabel->setStyleSheet(QString::fromUtf8("font: 75 30pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));
        adresLabel->setAlignment(Qt::AlignCenter);
        powrot = new QPushButton(CompanyInfoScreen);
        powrot->setObjectName(QString::fromUtf8("powrot"));
        powrot->setGeometry(QRect(153, 460, 718, 90));
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
        adres = new QLineEdit(CompanyInfoScreen);
        adres->setObjectName(QString::fromUtf8("adres"));
        adres->setGeometry(QRect(369, 260, 508, 90));
        adres->setMinimumSize(QSize(508, 90));
        adres->setMaximumSize(QSize(508, 90));
        adres->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"font: 75 30pt \"Tahoma\";\n"
"\n"
"border-style: solid;\n"
"border-width:4px;\n"
"border-radius:30px;\n"
"\n"
"max-width:500px;\n"
"max-height:82px;\n"
"min-width:500px;\n"
"min-height:82px;"));
        adres->setEchoMode(QLineEdit::Normal);
        nazwa = new QLineEdit(CompanyInfoScreen);
        nazwa->setObjectName(QString::fromUtf8("nazwa"));
        nazwa->setGeometry(QRect(369, 80, 508, 90));
        nazwa->setMinimumSize(QSize(508, 90));
        nazwa->setMaximumSize(QSize(508, 90));
        nazwa->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"font: 75 30pt \"Tahoma\";\n"
"\n"
"border-style: solid;\n"
"border-width:4px;\n"
"border-radius:30px;\n"
"\n"
"max-width:500px;\n"
"max-height:82px;\n"
"min-width:500px;\n"
"min-height:82px;"));
        nazwaLabel = new QLabel(CompanyInfoScreen);
        nazwaLabel->setObjectName(QString::fromUtf8("nazwaLabel"));
        nazwaLabel->setGeometry(QRect(153, 80, 200, 90));
        nazwaLabel->setMinimumSize(QSize(200, 90));
        nazwaLabel->setMaximumSize(QSize(200, 90));
        nazwaLabel->setLayoutDirection(Qt::RightToLeft);
        nazwaLabel->setStyleSheet(QString::fromUtf8("font: 75 30pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));
        nazwaLabel->setAlignment(Qt::AlignCenter);
        nipLabel = new QLabel(CompanyInfoScreen);
        nipLabel->setObjectName(QString::fromUtf8("nipLabel"));
        nipLabel->setGeometry(QRect(153, 170, 200, 90));
        nipLabel->setMinimumSize(QSize(200, 90));
        nipLabel->setMaximumSize(QSize(200, 90));
        nipLabel->setStyleSheet(QString::fromUtf8("font: 75 30pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));
        nipLabel->setAlignment(Qt::AlignCenter);

        retranslateUi(CompanyInfoScreen);

        QMetaObject::connectSlotsByName(CompanyInfoScreen);
    } // setupUi

    void retranslateUi(QDialog *CompanyInfoScreen)
    {
        CompanyInfoScreen->setWindowTitle(QCoreApplication::translate("CompanyInfoScreen", "Dialog", nullptr));
        zatwierdzZmiany->setText(QCoreApplication::translate("CompanyInfoScreen", "ZATWIERD\305\271 ZMIANY", nullptr));
        adresLabel->setText(QCoreApplication::translate("CompanyInfoScreen", "ADRES", nullptr));
        powrot->setText(QCoreApplication::translate("CompanyInfoScreen", "POWR\303\223T", nullptr));
        nazwaLabel->setText(QCoreApplication::translate("CompanyInfoScreen", "NAZWA", nullptr));
        nipLabel->setText(QCoreApplication::translate("CompanyInfoScreen", "NIP", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CompanyInfoScreen: public Ui_CompanyInfoScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPANYINFOSCREEN_H
