/********************************************************************************
** Form generated from reading UI file 'AdministrationScreen.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINISTRATIONSCREEN_H
#define UI_ADMINISTRATIONSCREEN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AdministrationScreen
{
public:
    QPushButton *karnety;
    QPushButton *czlonkowie;
    QPushButton *dane_firmy;
    QPushButton *wyjscie;

    void setupUi(QDialog *AdministrationScreen)
    {
        if (AdministrationScreen->objectName().isEmpty())
            AdministrationScreen->setObjectName(QString::fromUtf8("AdministrationScreen"));
        AdministrationScreen->resize(1024, 768);
        AdministrationScreen->setMinimumSize(QSize(1024, 768));
        AdministrationScreen->setMaximumSize(QSize(1024, 768));
        AdministrationScreen->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 13, 13);"));
        karnety = new QPushButton(AdministrationScreen);
        karnety->setObjectName(QString::fromUtf8("karnety"));
        karnety->setGeometry(QRect(138, 2, 370, 370));
        karnety->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 13, 13);\n"
"border-style: solid;\n"
"border-width:4px;\n"
"border-radius:185px;\n"
"border-color: white;\n"
"max-width:362px;\n"
"max-height:362px;\n"
"min-width:362px;\n"
"min-height:362px;\n"
"\n"
"font: 75 30pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));
        karnety->setIconSize(QSize(16, 16));
        czlonkowie = new QPushButton(AdministrationScreen);
        czlonkowie->setObjectName(QString::fromUtf8("czlonkowie"));
        czlonkowie->setGeometry(QRect(515, 2, 370, 370));
        czlonkowie->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 13, 13);\n"
"border-style: solid;\n"
"border-width:4px;\n"
"border-radius:185px;\n"
"border-color: white;\n"
"max-width:362px;\n"
"max-height:362px;\n"
"min-width:362px;\n"
"min-height:362px;\n"
"\n"
"font: 75 30pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));
        czlonkowie->setIconSize(QSize(16, 16));
        dane_firmy = new QPushButton(AdministrationScreen);
        dane_firmy->setObjectName(QString::fromUtf8("dane_firmy"));
        dane_firmy->setGeometry(QRect(138, 376, 370, 370));
        dane_firmy->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 13, 13);\n"
"border-style: solid;\n"
"border-width:4px;\n"
"border-radius:185px;\n"
"border-color: white;\n"
"max-width:362px;\n"
"max-height:362px;\n"
"min-width:362px;\n"
"min-height:362px;\n"
"\n"
"font: 75 30pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));
        dane_firmy->setIconSize(QSize(16, 16));
        wyjscie = new QPushButton(AdministrationScreen);
        wyjscie->setObjectName(QString::fromUtf8("wyjscie"));
        wyjscie->setGeometry(QRect(515, 376, 370, 370));
        wyjscie->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 13, 13);\n"
"border-style: solid;\n"
"border-width:4px;\n"
"border-radius:185px;\n"
"border-color: white;\n"
"max-width:362px;\n"
"max-height:362px;\n"
"min-width:362px;\n"
"min-height:362px;\n"
"\n"
"font: 75 30pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));
        wyjscie->setIconSize(QSize(16, 16));

        retranslateUi(AdministrationScreen);

        QMetaObject::connectSlotsByName(AdministrationScreen);
    } // setupUi

    void retranslateUi(QDialog *AdministrationScreen)
    {
        AdministrationScreen->setWindowTitle(QApplication::translate("AdministrationScreen", "Dialog", 0, QApplication::UnicodeUTF8));
        karnety->setText(QApplication::translate("AdministrationScreen", "KARNETY", 0, QApplication::UnicodeUTF8));
        czlonkowie->setText(QApplication::translate("AdministrationScreen", "CZ\305\201ONKOWIE", 0, QApplication::UnicodeUTF8));
        dane_firmy->setText(QApplication::translate("AdministrationScreen", "DANE FIRMY", 0, QApplication::UnicodeUTF8));
        wyjscie->setText(QApplication::translate("AdministrationScreen", "WYJ\305\232CIE", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AdministrationScreen: public Ui_AdministrationScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINISTRATIONSCREEN_H
