/********************************************************************************
** Form generated from reading UI file 'AddOrEditPassScreen.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDOREDITPASSSCREEN_H
#define UI_ADDOREDITPASSSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AddOrEditPassScreen
{
public:
    QLabel *ileDniLabel;
    QLabel *cenaLabel;
    QLabel *nazwaLabel;
    QLineEdit *nazwa;
    QPushButton *zatwierdz;
    QPushButton *powrot;
    QLineEdit *cena;
    QLineEdit *ileDni;

    void setupUi(QDialog *AddOrEditPassScreen)
    {
        if (AddOrEditPassScreen->objectName().isEmpty())
            AddOrEditPassScreen->setObjectName(QString::fromUtf8("AddOrEditPassScreen"));
        AddOrEditPassScreen->resize(1024, 768);
        AddOrEditPassScreen->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 13, 13);"));
        ileDniLabel = new QLabel(AddOrEditPassScreen);
        ileDniLabel->setObjectName(QString::fromUtf8("ileDniLabel"));
        ileDniLabel->setGeometry(QRect(153, 180, 200, 90));
        ileDniLabel->setMinimumSize(QSize(200, 90));
        ileDniLabel->setMaximumSize(QSize(200, 90));
        ileDniLabel->setStyleSheet(QString::fromUtf8("font: 75 30pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));
        ileDniLabel->setAlignment(Qt::AlignCenter);
        cenaLabel = new QLabel(AddOrEditPassScreen);
        cenaLabel->setObjectName(QString::fromUtf8("cenaLabel"));
        cenaLabel->setGeometry(QRect(153, 270, 200, 90));
        cenaLabel->setMinimumSize(QSize(200, 90));
        cenaLabel->setMaximumSize(QSize(200, 90));
        cenaLabel->setStyleSheet(QString::fromUtf8("font: 75 30pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));
        cenaLabel->setAlignment(Qt::AlignCenter);
        nazwaLabel = new QLabel(AddOrEditPassScreen);
        nazwaLabel->setObjectName(QString::fromUtf8("nazwaLabel"));
        nazwaLabel->setGeometry(QRect(153, 90, 200, 90));
        nazwaLabel->setMinimumSize(QSize(200, 90));
        nazwaLabel->setMaximumSize(QSize(200, 90));
        nazwaLabel->setLayoutDirection(Qt::RightToLeft);
        nazwaLabel->setStyleSheet(QString::fromUtf8("font: 75 30pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));
        nazwaLabel->setAlignment(Qt::AlignCenter);
        nazwa = new QLineEdit(AddOrEditPassScreen);
        nazwa->setObjectName(QString::fromUtf8("nazwa"));
        nazwa->setGeometry(QRect(369, 90, 508, 90));
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
        zatwierdz = new QPushButton(AddOrEditPassScreen);
        zatwierdz->setObjectName(QString::fromUtf8("zatwierdz"));
        zatwierdz->setGeometry(QRect(153, 370, 718, 90));
        zatwierdz->setMinimumSize(QSize(718, 90));
        zatwierdz->setMaximumSize(QSize(718, 90));
        zatwierdz->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 13, 13);\n"
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
        powrot = new QPushButton(AddOrEditPassScreen);
        powrot->setObjectName(QString::fromUtf8("powrot"));
        powrot->setGeometry(QRect(153, 470, 718, 90));
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
        cena = new QLineEdit(AddOrEditPassScreen);
        cena->setObjectName(QString::fromUtf8("cena"));
        cena->setGeometry(QRect(369, 270, 508, 90));
        cena->setMinimumSize(QSize(508, 90));
        cena->setMaximumSize(QSize(508, 90));
        cena->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
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
        cena->setEchoMode(QLineEdit::Normal);
        ileDni = new QLineEdit(AddOrEditPassScreen);
        ileDni->setObjectName(QString::fromUtf8("ileDni"));
        ileDni->setGeometry(QRect(369, 180, 508, 90));
        ileDni->setMinimumSize(QSize(508, 90));
        ileDni->setMaximumSize(QSize(508, 90));
        ileDni->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
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
        ileDni->setEchoMode(QLineEdit::Normal);

        retranslateUi(AddOrEditPassScreen);

        QMetaObject::connectSlotsByName(AddOrEditPassScreen);
    } // setupUi

    void retranslateUi(QDialog *AddOrEditPassScreen)
    {
        AddOrEditPassScreen->setWindowTitle(QCoreApplication::translate("AddOrEditPassScreen", "Dialog", nullptr));
        ileDniLabel->setText(QCoreApplication::translate("AddOrEditPassScreen", "ILE DNI", nullptr));
        cenaLabel->setText(QCoreApplication::translate("AddOrEditPassScreen", "CENA", nullptr));
        nazwaLabel->setText(QCoreApplication::translate("AddOrEditPassScreen", "NAZWA", nullptr));
        zatwierdz->setText(QCoreApplication::translate("AddOrEditPassScreen", "ZATWIERD\305\271", nullptr));
        powrot->setText(QCoreApplication::translate("AddOrEditPassScreen", "POWR\303\223T", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddOrEditPassScreen: public Ui_AddOrEditPassScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDOREDITPASSSCREEN_H
