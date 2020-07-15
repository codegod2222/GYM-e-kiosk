/********************************************************************************
** Form generated from reading UI file 'RegistrationInfoScreen.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRATIONINFOSCREEN_H
#define UI_REGISTRATIONINFOSCREEN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

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
        RegistrationInfoScreen->setWindowTitle(QApplication::translate("RegistrationInfoScreen", "Dialog", 0, QApplication::UnicodeUTF8));
        information->setText(QApplication::translate("RegistrationInfoScreen", "NAZWISKO NIE MO\305\273E BY\304\206 PUSTE!", 0, QApplication::UnicodeUTF8));
        OK->setText(QApplication::translate("RegistrationInfoScreen", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RegistrationInfoScreen: public Ui_RegistrationInfoScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATIONINFOSCREEN_H
