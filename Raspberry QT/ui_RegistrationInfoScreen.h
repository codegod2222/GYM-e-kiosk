/********************************************************************************
** Form generated from reading UI file 'RegistrationInfoScreen.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRATIONINFOSCREEN_H
#define UI_REGISTRATIONINFOSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_RegistrationInfoScreen
{
public:
    QLabel *information;
    QPushButton *OK;

    void setupUi(QDialog *RegistrationInfoScreen)
    {
        if (RegistrationInfoScreen->objectName().isEmpty())
            RegistrationInfoScreen->setObjectName(QString::fromUtf8("RegistrationInfoScreen"));
        RegistrationInfoScreen->setWindowModality(Qt::ApplicationModal);
        RegistrationInfoScreen->resize(700, 300);
        RegistrationInfoScreen->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 13, 13);\n"
"border-style: solid;\n"
"border-width:4px;\n"
"border-radius:30px;\n"
"border-color:  rgb(218, 0, 0);;"));
        information = new QLabel(RegistrationInfoScreen);
        information->setObjectName(QString::fromUtf8("information"));
        information->setGeometry(QRect(25, 50, 650, 81));
        information->setStyleSheet(QString::fromUtf8("border-style: none;\n"
"font: 75 30pt \"Tahoma\";\n"
"color: rgb(218, 0, 0);"));
        information->setAlignment(Qt::AlignCenter);
        OK = new QPushButton(RegistrationInfoScreen);
        OK->setObjectName(QString::fromUtf8("OK"));
        OK->setGeometry(QRect(225, 170, 250, 81));
        OK->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 13, 13);\n"
"border-style: solid;\n"
"border-width:4px;\n"
"border-radius:30px;\n"
"border-color: white;\n"
"\n"
"font: 75 30pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));

        retranslateUi(RegistrationInfoScreen);

        QMetaObject::connectSlotsByName(RegistrationInfoScreen);
    } // setupUi

    void retranslateUi(QDialog *RegistrationInfoScreen)
    {
        RegistrationInfoScreen->setWindowTitle(QCoreApplication::translate("RegistrationInfoScreen", "Dialog", nullptr));
        information->setText(QCoreApplication::translate("RegistrationInfoScreen", "NAZWISKO NIE MO\305\273E BY\304\206 PUSTE!", nullptr));
        OK->setText(QCoreApplication::translate("RegistrationInfoScreen", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegistrationInfoScreen: public Ui_RegistrationInfoScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATIONINFOSCREEN_H
