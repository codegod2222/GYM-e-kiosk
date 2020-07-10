/********************************************************************************
** Form generated from reading UI file 'BuyingPassScreen.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUYINGPASSSCREEN_H
#define UI_BUYINGPASSSCREEN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_BuyingPassScreen
{
public:
    QLabel *label;
    QComboBox *typyKarnetow;
    QLabel *label_2;
    QPushButton *gotowka;
    QPushButton *karta;
    QPushButton *online;
    QPushButton *powrot;

    void setupUi(QDialog *BuyingPassScreen)
    {
        if (BuyingPassScreen->objectName().isEmpty())
            BuyingPassScreen->setObjectName(QString::fromUtf8("BuyingPassScreen"));
        BuyingPassScreen->resize(1024, 768);
        BuyingPassScreen->setMinimumSize(QSize(1024, 768));
        BuyingPassScreen->setMaximumSize(QSize(1024, 768));
        BuyingPassScreen->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 13, 13);"));
        label = new QLabel(BuyingPassScreen);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(232, 20, 560, 100));
        label->setMinimumSize(QSize(130, 100));
        label->setMaximumSize(QSize(1000, 100));
        label->setLayoutDirection(Qt::RightToLeft);
        label->setStyleSheet(QString::fromUtf8("font: 75 28pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);\n"
"aligment: alignVcenter;\n"
"aligment: alignHcenter;"));
        label->setAlignment(Qt::AlignCenter);
        typyKarnetow = new QComboBox(BuyingPassScreen);
        typyKarnetow->setObjectName(QString::fromUtf8("typyKarnetow"));
        typyKarnetow->setGeometry(QRect(12, 130, 1000, 100));
        typyKarnetow->setLayoutDirection(Qt::LeftToRight);
        typyKarnetow->setAutoFillBackground(false);
        typyKarnetow->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"font: 75 30pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(13, 13, 13);\n"
"selection-background-color: rgb(13, 13, 13);\n"
"border: 1px solid gray;\n"
"}\n"
"QComboBox::drop-down {\n"
"width: 100px;\n"
"}\n"
""));
        typyKarnetow->setIconSize(QSize(100, 100));
        typyKarnetow->setFrame(false);
        label_2 = new QLabel(BuyingPassScreen);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(232, 240, 560, 100));
        label_2->setMinimumSize(QSize(130, 100));
        label_2->setMaximumSize(QSize(1000, 100));
        label_2->setLayoutDirection(Qt::RightToLeft);
        label_2->setStyleSheet(QString::fromUtf8("font: 75 28pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);\n"
"aligment: alignVcenter;\n"
"aligment: alignHcenter;"));
        label_2->setAlignment(Qt::AlignCenter);
        gotowka = new QPushButton(BuyingPassScreen);
        gotowka->setObjectName(QString::fromUtf8("gotowka"));
        gotowka->setGeometry(QRect(31, 350, 300, 300));
        gotowka->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 13, 13);\n"
"border-style: solid;\n"
"border-width:4px;\n"
"border-radius:150px;\n"
"border-color: white;\n"
"\n"
"font: 75 30pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));
        gotowka->setIconSize(QSize(16, 16));
        karta = new QPushButton(BuyingPassScreen);
        karta->setObjectName(QString::fromUtf8("karta"));
        karta->setGeometry(QRect(362, 350, 300, 300));
        karta->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 13, 13);\n"
"border-style: solid;\n"
"border-width:4px;\n"
"border-radius:150px;\n"
"border-color: white;\n"
"\n"
"font: 75 30pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));
        karta->setIconSize(QSize(16, 16));
        online = new QPushButton(BuyingPassScreen);
        online->setObjectName(QString::fromUtf8("online"));
        online->setGeometry(QRect(693, 350, 300, 300));
        online->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 13, 13);\n"
"border-style: solid;\n"
"border-width:4px;\n"
"border-radius:150px;\n"
"border-color: white;\n"
"\n"
"font: 75 30pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));
        online->setIconSize(QSize(16, 16));
        powrot = new QPushButton(BuyingPassScreen);
        powrot->setObjectName(QString::fromUtf8("powrot"));
        powrot->setGeometry(QRect(153, 660, 718, 90));
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

        retranslateUi(BuyingPassScreen);

        QMetaObject::connectSlotsByName(BuyingPassScreen);
    } // setupUi

    void retranslateUi(QDialog *BuyingPassScreen)
    {
        BuyingPassScreen->setWindowTitle(QApplication::translate("BuyingPassScreen", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BuyingPassScreen", "WYBIERZ RODZAJ KARNETU:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("BuyingPassScreen", "WYBIERZ RODZAJ P\305\201ATNO\305\232CI:", 0, QApplication::UnicodeUTF8));
        gotowka->setText(QApplication::translate("BuyingPassScreen", "GOT\303\223WKA", 0, QApplication::UnicodeUTF8));
        karta->setText(QApplication::translate("BuyingPassScreen", "KARTA", 0, QApplication::UnicodeUTF8));
        online->setText(QApplication::translate("BuyingPassScreen", "ONLINE", 0, QApplication::UnicodeUTF8));
        powrot->setText(QApplication::translate("BuyingPassScreen", "POWR\303\223T", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BuyingPassScreen: public Ui_BuyingPassScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUYINGPASSSCREEN_H
