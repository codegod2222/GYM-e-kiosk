/********************************************************************************
** Form generated from reading UI file 'LoggedScreen.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGGEDSCREEN_H
#define UI_LOGGEDSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LoggedScreen
{
public:
    QLabel *komunikat;
    QLabel *zalogowanyJako;
    QPushButton *kupKarnet;
    QPushButton *wyloguj;
    QPushButton *zmienDane;

    void setupUi(QDialog *LoggedScreen)
    {
        if (LoggedScreen->objectName().isEmpty())
            LoggedScreen->setObjectName(QString::fromUtf8("LoggedScreen"));
        LoggedScreen->resize(1024, 768);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LoggedScreen->sizePolicy().hasHeightForWidth());
        LoggedScreen->setSizePolicy(sizePolicy);
        LoggedScreen->setMinimumSize(QSize(1024, 768));
        LoggedScreen->setMaximumSize(QSize(1024, 768));
        LoggedScreen->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 13, 13);"));
        komunikat = new QLabel(LoggedScreen);
        komunikat->setObjectName(QString::fromUtf8("komunikat"));
        komunikat->setGeometry(QRect(157, 80, 718, 81));
        komunikat->setStyleSheet(QString::fromUtf8("font: 75 30pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));
        komunikat->setAlignment(Qt::AlignCenter);
        zalogowanyJako = new QLabel(LoggedScreen);
        zalogowanyJako->setObjectName(QString::fromUtf8("zalogowanyJako"));
        zalogowanyJako->setGeometry(QRect(157, 170, 718, 81));
        zalogowanyJako->setStyleSheet(QString::fromUtf8("font: 75 30pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));
        zalogowanyJako->setAlignment(Qt::AlignCenter);
        kupKarnet = new QPushButton(LoggedScreen);
        kupKarnet->setObjectName(QString::fromUtf8("kupKarnet"));
        kupKarnet->setGeometry(QRect(31, 300, 300, 300));
        kupKarnet->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 13, 13);\n"
"border-style: solid;\n"
"border-width:4px;\n"
"border-radius:150px;\n"
"border-color: white;\n"
"\n"
"font: 75 30pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));
        kupKarnet->setIconSize(QSize(16, 16));
        wyloguj = new QPushButton(LoggedScreen);
        wyloguj->setObjectName(QString::fromUtf8("wyloguj"));
        wyloguj->setGeometry(QRect(693, 300, 300, 300));
        wyloguj->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 13, 13);\n"
"border-style: solid;\n"
"border-width:4px;\n"
"border-radius:150px;\n"
"border-color: white;\n"
"\n"
"font: 75 30pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));
        wyloguj->setIconSize(QSize(16, 16));
        zmienDane = new QPushButton(LoggedScreen);
        zmienDane->setObjectName(QString::fromUtf8("zmienDane"));
        zmienDane->setGeometry(QRect(362, 300, 300, 300));
        zmienDane->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 13, 13);\n"
"border-style: solid;\n"
"border-width:4px;\n"
"border-radius:150px;\n"
"border-color: white;\n"
"\n"
"font: 75 30pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));
        zmienDane->setIconSize(QSize(16, 16));

        retranslateUi(LoggedScreen);

        QMetaObject::connectSlotsByName(LoggedScreen);
    } // setupUi

    void retranslateUi(QDialog *LoggedScreen)
    {
        LoggedScreen->setWindowTitle(QCoreApplication::translate("LoggedScreen", "Dialog", nullptr));
        komunikat->setText(QCoreApplication::translate("LoggedScreen", "JESTE\305\232 ZALOGOWANY JAKO:", nullptr));
        zalogowanyJako->setText(QString());
        kupKarnet->setText(QCoreApplication::translate("LoggedScreen", "KUP KARNET", nullptr));
        wyloguj->setText(QCoreApplication::translate("LoggedScreen", "WYLOGUJ", nullptr));
        zmienDane->setText(QCoreApplication::translate("LoggedScreen", "ZMIE\305\203 DANE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoggedScreen: public Ui_LoggedScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGGEDSCREEN_H
