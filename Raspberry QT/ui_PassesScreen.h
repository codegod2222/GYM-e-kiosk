/********************************************************************************
** Form generated from reading UI file 'PassesScreen.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSESSCREEN_H
#define UI_PASSESSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_PassesScreen
{
public:
    QPushButton *powrot;
    QPushButton *edytujKarnet;
    QPushButton *dodajKarnet;
    QPushButton *usunKarnet;
    QTableWidget *listaKarnetow;

    void setupUi(QDialog *PassesScreen)
    {
        if (PassesScreen->objectName().isEmpty())
            PassesScreen->setObjectName(QString::fromUtf8("PassesScreen"));
        PassesScreen->resize(1024, 768);
        PassesScreen->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 13, 13);"));
        powrot = new QPushButton(PassesScreen);
        powrot->setObjectName(QString::fromUtf8("powrot"));
        powrot->setGeometry(QRect(5, 660, 250, 90));
        powrot->setMinimumSize(QSize(0, 0));
        powrot->setMaximumSize(QSize(16777215, 16777215));
        powrot->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 13, 13);\n"
"border-style: solid;\n"
"border-width:4px;\n"
"border-radius:30px;\n"
"border-color: white;\n"
"\n"
"font: 75 30pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));
        edytujKarnet = new QPushButton(PassesScreen);
        edytujKarnet->setObjectName(QString::fromUtf8("edytujKarnet"));
        edytujKarnet->setGeometry(QRect(260, 660, 250, 90));
        edytujKarnet->setMinimumSize(QSize(0, 0));
        edytujKarnet->setMaximumSize(QSize(16777215, 16777215));
        edytujKarnet->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 13, 13);\n"
"border-style: solid;\n"
"border-width:4px;\n"
"border-radius:30px;\n"
"border-color: white;\n"
"\n"
"font: 75 30pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));
        dodajKarnet = new QPushButton(PassesScreen);
        dodajKarnet->setObjectName(QString::fromUtf8("dodajKarnet"));
        dodajKarnet->setGeometry(QRect(770, 660, 250, 90));
        dodajKarnet->setMinimumSize(QSize(0, 0));
        dodajKarnet->setMaximumSize(QSize(16777215, 16777215));
        dodajKarnet->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 13, 13);\n"
"border-style: solid;\n"
"border-width:4px;\n"
"border-radius:30px;\n"
"border-color: white;\n"
"\n"
"font: 75 30pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));
        usunKarnet = new QPushButton(PassesScreen);
        usunKarnet->setObjectName(QString::fromUtf8("usunKarnet"));
        usunKarnet->setGeometry(QRect(510, 660, 250, 90));
        usunKarnet->setMinimumSize(QSize(0, 0));
        usunKarnet->setMaximumSize(QSize(16777215, 16777215));
        usunKarnet->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 13, 13);\n"
"border-style: solid;\n"
"border-width:4px;\n"
"border-radius:30px;\n"
"border-color: white;\n"
"\n"
"font: 75 30pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));
        listaKarnetow = new QTableWidget(PassesScreen);
        listaKarnetow->setObjectName(QString::fromUtf8("listaKarnetow"));
        listaKarnetow->setGeometry(QRect(20, 10, 981, 611));
        listaKarnetow->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"\n"
"font: 75 30pt \"Tahoma\";\n"
"color: rgb(0, 0, 0);"));

        retranslateUi(PassesScreen);

        QMetaObject::connectSlotsByName(PassesScreen);
    } // setupUi

    void retranslateUi(QDialog *PassesScreen)
    {
        PassesScreen->setWindowTitle(QCoreApplication::translate("PassesScreen", "Dialog", nullptr));
        powrot->setText(QCoreApplication::translate("PassesScreen", "POWR\303\223T", nullptr));
        edytujKarnet->setText(QCoreApplication::translate("PassesScreen", "EDYTUJ", nullptr));
        dodajKarnet->setText(QCoreApplication::translate("PassesScreen", "DODAJ", nullptr));
        usunKarnet->setText(QCoreApplication::translate("PassesScreen", "USU\305\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PassesScreen: public Ui_PassesScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSESSCREEN_H
