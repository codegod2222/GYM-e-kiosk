/********************************************************************************
** Form generated from reading UI file 'ClubMembersScreen.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLUBMEMBERSSCREEN_H
#define UI_CLUBMEMBERSSCREEN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_ClubMembersScreen
{
public:
    QTableWidget *listaCzlonkow;
    QPushButton *dodajCzlonka;
    QPushButton *usunCzlonka;
    QPushButton *edytujCzlonka;
    QPushButton *powrot;

    void setupUi(QDialog *ClubMembersScreen)
    {
        if (ClubMembersScreen->objectName().isEmpty())
            ClubMembersScreen->setObjectName(QString::fromUtf8("ClubMembersScreen"));
        ClubMembersScreen->resize(1024, 768);
        ClubMembersScreen->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 13, 13);"));
        listaCzlonkow = new QTableWidget(ClubMembersScreen);
        listaCzlonkow->setObjectName(QString::fromUtf8("listaCzlonkow"));
        listaCzlonkow->setGeometry(QRect(15, 10, 981, 611));
        listaCzlonkow->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"\n"
"font: 75 20pt \"Tahoma\";\n"
"color: rgb(0, 0, 0);"));
        dodajCzlonka = new QPushButton(ClubMembersScreen);
        dodajCzlonka->setObjectName(QString::fromUtf8("dodajCzlonka"));
        dodajCzlonka->setGeometry(QRect(765, 660, 250, 90));
        dodajCzlonka->setMinimumSize(QSize(0, 0));
        dodajCzlonka->setMaximumSize(QSize(16777215, 16777215));
        dodajCzlonka->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 13, 13);\n"
"border-style: solid;\n"
"border-width:4px;\n"
"border-radius:30px;\n"
"border-color: white;\n"
"\n"
"font: 75 30pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));
        usunCzlonka = new QPushButton(ClubMembersScreen);
        usunCzlonka->setObjectName(QString::fromUtf8("usunCzlonka"));
        usunCzlonka->setGeometry(QRect(505, 660, 250, 90));
        usunCzlonka->setMinimumSize(QSize(0, 0));
        usunCzlonka->setMaximumSize(QSize(16777215, 16777215));
        usunCzlonka->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 13, 13);\n"
"border-style: solid;\n"
"border-width:4px;\n"
"border-radius:30px;\n"
"border-color: white;\n"
"\n"
"font: 75 30pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));
        edytujCzlonka = new QPushButton(ClubMembersScreen);
        edytujCzlonka->setObjectName(QString::fromUtf8("edytujCzlonka"));
        edytujCzlonka->setGeometry(QRect(255, 660, 250, 90));
        edytujCzlonka->setMinimumSize(QSize(0, 0));
        edytujCzlonka->setMaximumSize(QSize(16777215, 16777215));
        edytujCzlonka->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 13, 13);\n"
"border-style: solid;\n"
"border-width:4px;\n"
"border-radius:30px;\n"
"border-color: white;\n"
"\n"
"font: 75 30pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));
        powrot = new QPushButton(ClubMembersScreen);
        powrot->setObjectName(QString::fromUtf8("powrot"));
        powrot->setGeometry(QRect(0, 660, 250, 90));
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

        retranslateUi(ClubMembersScreen);

        QMetaObject::connectSlotsByName(ClubMembersScreen);
    } // setupUi

    void retranslateUi(QDialog *ClubMembersScreen)
    {
        ClubMembersScreen->setWindowTitle(QApplication::translate("ClubMembersScreen", "Dialog", 0, QApplication::UnicodeUTF8));
        dodajCzlonka->setText(QApplication::translate("ClubMembersScreen", "DODAJ", 0, QApplication::UnicodeUTF8));
        usunCzlonka->setText(QApplication::translate("ClubMembersScreen", "USU\305\203", 0, QApplication::UnicodeUTF8));
        edytujCzlonka->setText(QApplication::translate("ClubMembersScreen", "EDYTUJ", 0, QApplication::UnicodeUTF8));
        powrot->setText(QApplication::translate("ClubMembersScreen", "POWR\303\223T", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ClubMembersScreen: public Ui_ClubMembersScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLUBMEMBERSSCREEN_H
