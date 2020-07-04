/********************************************************************************
** Form generated from reading UI file 'DataChangeScreen.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATACHANGESCREEN_H
#define UI_DATACHANGESCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DataChangeScreen
{
public:
    QLabel *nazwiskoLabel;
    QLineEdit *nazwisko;
    QLineEdit *imie;
    QLabel *emailLabel;
    QLabel *imieLabel;
    QLineEdit *email;
    QPushButton *zatwierdzZmiany;
    QPushButton *zmienHaslo;
    QPushButton *powrot;

    void setupUi(QDialog *DataChangeScreen)
    {
        if (DataChangeScreen->objectName().isEmpty())
            DataChangeScreen->setObjectName(QString::fromUtf8("DataChangeScreen"));
        DataChangeScreen->resize(1024, 768);
        DataChangeScreen->setMinimumSize(QSize(1024, 768));
        DataChangeScreen->setMaximumSize(QSize(1024, 768));
        DataChangeScreen->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 13, 13);"));
        nazwiskoLabel = new QLabel(DataChangeScreen);
        nazwiskoLabel->setObjectName(QString::fromUtf8("nazwiskoLabel"));
        nazwiskoLabel->setGeometry(QRect(153, 180, 200, 90));
        nazwiskoLabel->setMinimumSize(QSize(200, 90));
        nazwiskoLabel->setMaximumSize(QSize(200, 90));
        nazwiskoLabel->setStyleSheet(QString::fromUtf8("font: 75 30pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));
        nazwiskoLabel->setAlignment(Qt::AlignCenter);
        nazwisko = new QLineEdit(DataChangeScreen);
        nazwisko->setObjectName(QString::fromUtf8("nazwisko"));
        nazwisko->setGeometry(QRect(359, 180, 508, 90));
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
        imie = new QLineEdit(DataChangeScreen);
        imie->setObjectName(QString::fromUtf8("imie"));
        imie->setGeometry(QRect(359, 90, 508, 90));
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
        emailLabel = new QLabel(DataChangeScreen);
        emailLabel->setObjectName(QString::fromUtf8("emailLabel"));
        emailLabel->setGeometry(QRect(153, 270, 200, 90));
        emailLabel->setMinimumSize(QSize(200, 90));
        emailLabel->setMaximumSize(QSize(200, 90));
        emailLabel->setStyleSheet(QString::fromUtf8("font: 75 30pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));
        emailLabel->setAlignment(Qt::AlignCenter);
        imieLabel = new QLabel(DataChangeScreen);
        imieLabel->setObjectName(QString::fromUtf8("imieLabel"));
        imieLabel->setGeometry(QRect(153, 90, 200, 90));
        imieLabel->setMinimumSize(QSize(200, 90));
        imieLabel->setMaximumSize(QSize(200, 90));
        imieLabel->setLayoutDirection(Qt::RightToLeft);
        imieLabel->setStyleSheet(QString::fromUtf8("font: 75 30pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));
        imieLabel->setAlignment(Qt::AlignCenter);
        email = new QLineEdit(DataChangeScreen);
        email->setObjectName(QString::fromUtf8("email"));
        email->setGeometry(QRect(359, 270, 508, 90));
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
        zatwierdzZmiany = new QPushButton(DataChangeScreen);
        zatwierdzZmiany->setObjectName(QString::fromUtf8("zatwierdzZmiany"));
        zatwierdzZmiany->setGeometry(QRect(153, 465, 718, 90));
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
        zmienHaslo = new QPushButton(DataChangeScreen);
        zmienHaslo->setObjectName(QString::fromUtf8("zmienHaslo"));
        zmienHaslo->setGeometry(QRect(153, 370, 718, 90));
        zmienHaslo->setMinimumSize(QSize(718, 90));
        zmienHaslo->setMaximumSize(QSize(718, 90));
        zmienHaslo->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 13, 13);\n"
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
        powrot = new QPushButton(DataChangeScreen);
        powrot->setObjectName(QString::fromUtf8("powrot"));
        powrot->setGeometry(QRect(153, 560, 718, 90));
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

        retranslateUi(DataChangeScreen);

        QMetaObject::connectSlotsByName(DataChangeScreen);
    } // setupUi

    void retranslateUi(QDialog *DataChangeScreen)
    {
        DataChangeScreen->setWindowTitle(QCoreApplication::translate("DataChangeScreen", "Dialog", nullptr));
        nazwiskoLabel->setText(QCoreApplication::translate("DataChangeScreen", "NAZWISKO", nullptr));
        emailLabel->setText(QCoreApplication::translate("DataChangeScreen", "EMAIL", nullptr));
        imieLabel->setText(QCoreApplication::translate("DataChangeScreen", "IMI\304\230", nullptr));
        zatwierdzZmiany->setText(QCoreApplication::translate("DataChangeScreen", "ZATWIERD\305\271 ZMIANY", nullptr));
        zmienHaslo->setText(QCoreApplication::translate("DataChangeScreen", "ZMIE\305\203 HAS\305\201O", nullptr));
        powrot->setText(QCoreApplication::translate("DataChangeScreen", "POWR\303\223T", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DataChangeScreen: public Ui_DataChangeScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATACHANGESCREEN_H
