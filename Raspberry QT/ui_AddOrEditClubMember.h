/********************************************************************************
** Form generated from reading UI file 'AddOrEditClubMember.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDOREDITCLUBMEMBER_H
#define UI_ADDOREDITCLUBMEMBER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AddOrEditClubMember
{
public:
    QLineEdit *imie;
    QLineEdit *email;
    QLabel *imieLabel;
    QPushButton *powrot;
    QLineEdit *nazwisko;
    QLabel *nazwiskoLabel;
    QLabel *emailLabel;
    QPushButton *zatwierdz;
    QLineEdit *haslo;
    QLabel *hasloLabel;
    QLabel *rfidLabel;
    QLineEdit *rfid;

    void setupUi(QDialog *AddOrEditClubMember)
    {
        if (AddOrEditClubMember->objectName().isEmpty())
            AddOrEditClubMember->setObjectName(QString::fromUtf8("AddOrEditClubMember"));
        AddOrEditClubMember->resize(1024, 768);
        AddOrEditClubMember->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 13, 13);"));
        imie = new QLineEdit(AddOrEditClubMember);
        imie->setObjectName(QString::fromUtf8("imie"));
        imie->setGeometry(QRect(369, 20, 508, 90));
        imie->setMinimumSize(QSize(508, 90));
        imie->setMaximumSize(QSize(508, 90));
        imie->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
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
        email = new QLineEdit(AddOrEditClubMember);
        email->setObjectName(QString::fromUtf8("email"));
        email->setGeometry(QRect(369, 200, 508, 90));
        email->setMinimumSize(QSize(508, 90));
        email->setMaximumSize(QSize(508, 90));
        email->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
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
        email->setEchoMode(QLineEdit::Normal);
        imieLabel = new QLabel(AddOrEditClubMember);
        imieLabel->setObjectName(QString::fromUtf8("imieLabel"));
        imieLabel->setGeometry(QRect(153, 20, 200, 90));
        imieLabel->setMinimumSize(QSize(200, 90));
        imieLabel->setMaximumSize(QSize(200, 90));
        imieLabel->setLayoutDirection(Qt::RightToLeft);
        imieLabel->setStyleSheet(QString::fromUtf8("font: 75 30pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));
        imieLabel->setAlignment(Qt::AlignCenter);
        powrot = new QPushButton(AddOrEditClubMember);
        powrot->setObjectName(QString::fromUtf8("powrot"));
        powrot->setGeometry(QRect(153, 590, 718, 90));
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
        nazwisko = new QLineEdit(AddOrEditClubMember);
        nazwisko->setObjectName(QString::fromUtf8("nazwisko"));
        nazwisko->setGeometry(QRect(369, 110, 508, 90));
        nazwisko->setMinimumSize(QSize(508, 90));
        nazwisko->setMaximumSize(QSize(508, 90));
        nazwisko->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
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
        nazwisko->setEchoMode(QLineEdit::Normal);
        nazwiskoLabel = new QLabel(AddOrEditClubMember);
        nazwiskoLabel->setObjectName(QString::fromUtf8("nazwiskoLabel"));
        nazwiskoLabel->setGeometry(QRect(153, 110, 200, 90));
        nazwiskoLabel->setMinimumSize(QSize(200, 90));
        nazwiskoLabel->setMaximumSize(QSize(200, 90));
        nazwiskoLabel->setStyleSheet(QString::fromUtf8("font: 75 30pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));
        nazwiskoLabel->setAlignment(Qt::AlignCenter);
        emailLabel = new QLabel(AddOrEditClubMember);
        emailLabel->setObjectName(QString::fromUtf8("emailLabel"));
        emailLabel->setGeometry(QRect(153, 200, 200, 90));
        emailLabel->setMinimumSize(QSize(200, 90));
        emailLabel->setMaximumSize(QSize(200, 90));
        emailLabel->setStyleSheet(QString::fromUtf8("font: 75 30pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));
        emailLabel->setAlignment(Qt::AlignCenter);
        zatwierdz = new QPushButton(AddOrEditClubMember);
        zatwierdz->setObjectName(QString::fromUtf8("zatwierdz"));
        zatwierdz->setGeometry(QRect(150, 490, 718, 90));
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
        haslo = new QLineEdit(AddOrEditClubMember);
        haslo->setObjectName(QString::fromUtf8("haslo"));
        haslo->setGeometry(QRect(369, 290, 508, 90));
        haslo->setMinimumSize(QSize(508, 90));
        haslo->setMaximumSize(QSize(508, 90));
        haslo->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
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
        haslo->setEchoMode(QLineEdit::Normal);
        hasloLabel = new QLabel(AddOrEditClubMember);
        hasloLabel->setObjectName(QString::fromUtf8("hasloLabel"));
        hasloLabel->setGeometry(QRect(153, 290, 200, 90));
        hasloLabel->setMinimumSize(QSize(200, 90));
        hasloLabel->setMaximumSize(QSize(200, 90));
        hasloLabel->setStyleSheet(QString::fromUtf8("font: 75 30pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));
        hasloLabel->setAlignment(Qt::AlignCenter);
        rfidLabel = new QLabel(AddOrEditClubMember);
        rfidLabel->setObjectName(QString::fromUtf8("rfidLabel"));
        rfidLabel->setGeometry(QRect(153, 380, 200, 90));
        rfidLabel->setMinimumSize(QSize(200, 90));
        rfidLabel->setMaximumSize(QSize(200, 90));
        rfidLabel->setStyleSheet(QString::fromUtf8("font: 75 30pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));
        rfidLabel->setAlignment(Qt::AlignCenter);
        rfid = new QLineEdit(AddOrEditClubMember);
        rfid->setObjectName(QString::fromUtf8("rfid"));
        rfid->setGeometry(QRect(369, 380, 508, 90));
        rfid->setMinimumSize(QSize(508, 90));
        rfid->setMaximumSize(QSize(508, 90));
        rfid->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
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
        rfid->setEchoMode(QLineEdit::Normal);

        retranslateUi(AddOrEditClubMember);

        QMetaObject::connectSlotsByName(AddOrEditClubMember);
    } // setupUi

    void retranslateUi(QDialog *AddOrEditClubMember)
    {
        AddOrEditClubMember->setWindowTitle(QApplication::translate("AddOrEditClubMember", "Dialog", 0, QApplication::UnicodeUTF8));
        imieLabel->setText(QApplication::translate("AddOrEditClubMember", "IMIE", 0, QApplication::UnicodeUTF8));
        powrot->setText(QApplication::translate("AddOrEditClubMember", "ANULUJ", 0, QApplication::UnicodeUTF8));
        nazwiskoLabel->setText(QApplication::translate("AddOrEditClubMember", "NAZWISKO", 0, QApplication::UnicodeUTF8));
        emailLabel->setText(QApplication::translate("AddOrEditClubMember", "EMAIL", 0, QApplication::UnicodeUTF8));
        zatwierdz->setText(QApplication::translate("AddOrEditClubMember", "ZATWIERD\305\271", 0, QApplication::UnicodeUTF8));
        hasloLabel->setText(QApplication::translate("AddOrEditClubMember", "HASLO", 0, QApplication::UnicodeUTF8));
        rfidLabel->setText(QApplication::translate("AddOrEditClubMember", "RFID", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AddOrEditClubMember: public Ui_AddOrEditClubMember {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDOREDITCLUBMEMBER_H
