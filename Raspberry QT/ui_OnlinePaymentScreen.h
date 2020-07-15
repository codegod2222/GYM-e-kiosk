/********************************************************************************
** Form generated from reading UI file 'OnlinePaymentScreen.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ONLINEPAYMENTSCREEN_H
#define UI_ONLINEPAYMENTSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_OnlinePaymentScreen
{
public:
    QPushButton *zaplacono;
    QPushButton *anuluj;
    QLabel *komunikat;
    QLabel *adres;
    QLabel *status;

    void setupUi(QDialog *OnlinePaymentScreen)
    {
        if (OnlinePaymentScreen->objectName().isEmpty())
            OnlinePaymentScreen->setObjectName(QString::fromUtf8("OnlinePaymentScreen"));
        OnlinePaymentScreen->resize(1024, 768);
        OnlinePaymentScreen->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 13, 13);"));
        zaplacono = new QPushButton(OnlinePaymentScreen);
        zaplacono->setObjectName(QString::fromUtf8("zaplacono"));
        zaplacono->setGeometry(QRect(157, 420, 718, 108));
        zaplacono->setMinimumSize(QSize(718, 108));
        zaplacono->setMaximumSize(QSize(718, 108));
        zaplacono->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 13, 13);\n"
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
        anuluj = new QPushButton(OnlinePaymentScreen);
        anuluj->setObjectName(QString::fromUtf8("anuluj"));
        anuluj->setGeometry(QRect(157, 540, 718, 108));
        anuluj->setMinimumSize(QSize(718, 108));
        anuluj->setMaximumSize(QSize(718, 108));
        anuluj->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 13, 13);\n"
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
        komunikat = new QLabel(OnlinePaymentScreen);
        komunikat->setObjectName(QString::fromUtf8("komunikat"));
        komunikat->setGeometry(QRect(12, 230, 1000, 81));
        komunikat->setStyleSheet(QString::fromUtf8("font: 75 26pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));
        komunikat->setAlignment(Qt::AlignCenter);
        adres = new QLabel(OnlinePaymentScreen);
        adres->setObjectName(QString::fromUtf8("adres"));
        adres->setGeometry(QRect(12, 320, 1000, 81));
        adres->setStyleSheet(QString::fromUtf8("font: 75 30pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));
        adres->setAlignment(Qt::AlignCenter);
        status = new QLabel(OnlinePaymentScreen);
        status->setObjectName(QString::fromUtf8("status"));
        status->setGeometry(QRect(20, 650, 1000, 81));
        status->setStyleSheet(QString::fromUtf8("font: 75 30pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));
        status->setAlignment(Qt::AlignCenter);

        retranslateUi(OnlinePaymentScreen);

        QMetaObject::connectSlotsByName(OnlinePaymentScreen);
    } // setupUi

    void retranslateUi(QDialog *OnlinePaymentScreen)
    {
        OnlinePaymentScreen->setWindowTitle(QCoreApplication::translate("OnlinePaymentScreen", "Dialog", nullptr));
        zaplacono->setText(QCoreApplication::translate("OnlinePaymentScreen", "ZAPLACONO", nullptr));
        anuluj->setText(QCoreApplication::translate("OnlinePaymentScreen", "ANULUJ", nullptr));
        komunikat->setText(QCoreApplication::translate("OnlinePaymentScreen", "PRZEJDZ POD TEN ADRES ABY DOKONCZYC PLATNOSC:", nullptr));
        adres->setText(QString());
        status->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class OnlinePaymentScreen: public Ui_OnlinePaymentScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ONLINEPAYMENTSCREEN_H
