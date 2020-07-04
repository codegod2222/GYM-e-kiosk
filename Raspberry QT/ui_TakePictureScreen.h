/********************************************************************************
** Form generated from reading UI file 'TakePictureScreen.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAKEPICTURESCREEN_H
#define UI_TAKEPICTURESCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TakePictureScreen
{
public:
    QLabel *imgLabel;
    QPushButton *OK;
    QPushButton *OK_2;
    QPushButton *jeszczeRaz;

    void setupUi(QWidget *TakePictureScreen)
    {
        if (TakePictureScreen->objectName().isEmpty())
            TakePictureScreen->setObjectName(QString::fromUtf8("TakePictureScreen"));
        TakePictureScreen->resize(1024, 768);
        TakePictureScreen->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 13, 13);"));
        imgLabel = new QLabel(TakePictureScreen);
        imgLabel->setObjectName(QString::fromUtf8("imgLabel"));
        imgLabel->setGeometry(QRect(10, 10, 1001, 611));
        imgLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 13, 13);\n"
"border-style: solid;\n"
"border-width:4px;\n"
"border-radius:30px;\n"
"border-color: white;\n"
"\n"
"font: 75 30pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));
        imgLabel->setAlignment(Qt::AlignCenter);
        OK = new QPushButton(TakePictureScreen);
        OK->setObjectName(QString::fromUtf8("OK"));
        OK->setGeometry(QRect(74, 645, 400, 100));
        OK->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 13, 13);\n"
"border-style: solid;\n"
"border-width:4px;\n"
"border-radius:30px;\n"
"border-color: white;\n"
"\n"
"font: 75 30pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));
        OK_2 = new QPushButton(TakePictureScreen);
        OK_2->setObjectName(QString::fromUtf8("OK_2"));
        OK_2->setGeometry(QRect(550, 645, 400, 100));
        OK_2->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 13, 13);\n"
"border-style: solid;\n"
"border-width:4px;\n"
"border-radius:30px;\n"
"border-color: white;\n"
"\n"
"font: 75 30pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));
        jeszczeRaz = new QPushButton(TakePictureScreen);
        jeszczeRaz->setObjectName(QString::fromUtf8("jeszczeRaz"));
        jeszczeRaz->setGeometry(QRect(74, 645, 400, 100));
        jeszczeRaz->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 13, 13);\n"
"border-style: solid;\n"
"border-width:4px;\n"
"border-radius:30px;\n"
"border-color: white;\n"
"\n"
"font: 75 30pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));

        retranslateUi(TakePictureScreen);

        QMetaObject::connectSlotsByName(TakePictureScreen);
    } // setupUi

    void retranslateUi(QWidget *TakePictureScreen)
    {
        TakePictureScreen->setWindowTitle(QCoreApplication::translate("TakePictureScreen", "Form", nullptr));
        imgLabel->setText(QCoreApplication::translate("TakePictureScreen", "Inicjowanie kamery", nullptr));
        OK->setText(QCoreApplication::translate("TakePictureScreen", "ZR\303\223B ZDJ\304\230CIE", nullptr));
        OK_2->setText(QCoreApplication::translate("TakePictureScreen", "ANULUJ", nullptr));
        jeszczeRaz->setText(QCoreApplication::translate("TakePictureScreen", "JESZCZE RAZ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TakePictureScreen: public Ui_TakePictureScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAKEPICTURESCREEN_H
