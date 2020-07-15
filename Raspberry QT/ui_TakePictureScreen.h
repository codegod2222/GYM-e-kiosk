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
    QPushButton *robZdj;
    QPushButton *wyjdz;
    QPushButton *ponow;

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
        robZdj = new QPushButton(TakePictureScreen);
        robZdj->setObjectName(QString::fromUtf8("robZdj"));
        robZdj->setGeometry(QRect(74, 645, 400, 100));
        robZdj->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 13, 13);\n"
"border-style: solid;\n"
"border-width:4px;\n"
"border-radius:30px;\n"
"border-color: white;\n"
"\n"
"font: 75 30pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));
        wyjdz = new QPushButton(TakePictureScreen);
        wyjdz->setObjectName(QString::fromUtf8("wyjdz"));
        wyjdz->setGeometry(QRect(550, 645, 400, 100));
        wyjdz->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 13, 13);\n"
"border-style: solid;\n"
"border-width:4px;\n"
"border-radius:30px;\n"
"border-color: white;\n"
"\n"
"font: 75 30pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));
        ponow = new QPushButton(TakePictureScreen);
        ponow->setObjectName(QString::fromUtf8("ponow"));
        ponow->setGeometry(QRect(74, 645, 400, 100));
        ponow->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 13, 13);\n"
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
        robZdj->setText(QCoreApplication::translate("TakePictureScreen", "ZR\303\223B ZDJ\304\230CIE", nullptr));
        wyjdz->setText(QCoreApplication::translate("TakePictureScreen", "WYJSCIE", nullptr));
        ponow->setText(QCoreApplication::translate("TakePictureScreen", "PONOW", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TakePictureScreen: public Ui_TakePictureScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAKEPICTURESCREEN_H
