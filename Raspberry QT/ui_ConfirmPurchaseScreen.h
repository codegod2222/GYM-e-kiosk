/********************************************************************************
** Form generated from reading UI file 'ConfirmPurchaseScreen.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIRMPURCHASESCREEN_H
#define UI_CONFIRMPURCHASESCREEN_H

#include <QtCore/QVariant>
#include <QApplication>
#include <QDialog>
#include <QLabel>
#include <QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ConfirmPurchaseScreen
{
public:
    QLabel *kupujesz;
    QLabel *typKarnetu;
    QLabel *forma;
    QLabel *typFormy;
    QPushButton *potwierdz;
    QPushButton *close;

    void setupUi(QDialog *ConfirmPurchaseScreen)
    {
        if (ConfirmPurchaseScreen->objectName().isEmpty())
            ConfirmPurchaseScreen->setObjectName(QString::fromUtf8("ConfirmPurchaseScreen"));
        ConfirmPurchaseScreen->setWindowModality(Qt::ApplicationModal);
        ConfirmPurchaseScreen->resize(520, 600);
        ConfirmPurchaseScreen->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 13, 13);\n"
"border-style: solid;\n"
"border-width:4px;\n"
"border-radius:30px;\n"
"border-color:  rgb(218, 0, 0);;"));
        kupujesz = new QLabel(ConfirmPurchaseScreen);
        kupujesz->setObjectName(QString::fromUtf8("kupujesz"));
        kupujesz->setGeometry(QRect(160, 10, 200, 90));
        kupujesz->setMinimumSize(QSize(200, 90));
        kupujesz->setMaximumSize(QSize(200, 90));
        kupujesz->setLayoutDirection(Qt::RightToLeft);
        kupujesz->setStyleSheet(QString::fromUtf8("font: 75 30pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);\n"
"border-style: none;"));
        kupujesz->setAlignment(Qt::AlignCenter);
        typKarnetu = new QLabel(ConfirmPurchaseScreen);
        typKarnetu->setObjectName(QString::fromUtf8("typKarnetu"));
        typKarnetu->setGeometry(QRect(10, 100, 500, 90));
        typKarnetu->setMinimumSize(QSize(200, 90));
        typKarnetu->setMaximumSize(QSize(500, 90));
        typKarnetu->setLayoutDirection(Qt::RightToLeft);
        typKarnetu->setStyleSheet(QString::fromUtf8("font: 75 30pt \"Tahoma\";\n"
"color: rgb(218, 0, 0);\n"
"border-style: none;"));
        typKarnetu->setAlignment(Qt::AlignCenter);
        forma = new QLabel(ConfirmPurchaseScreen);
        forma->setObjectName(QString::fromUtf8("forma"));
        forma->setGeometry(QRect(60, 190, 400, 90));
        forma->setMinimumSize(QSize(400, 90));
        forma->setMaximumSize(QSize(200, 90));
        forma->setLayoutDirection(Qt::RightToLeft);
        forma->setStyleSheet(QString::fromUtf8("border-style: none;\n"
"font: 75 30pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));
        forma->setAlignment(Qt::AlignCenter);
        typFormy = new QLabel(ConfirmPurchaseScreen);
        typFormy->setObjectName(QString::fromUtf8("typFormy"));
        typFormy->setGeometry(QRect(10, 280, 500, 90));
        typFormy->setMinimumSize(QSize(200, 90));
        typFormy->setMaximumSize(QSize(500, 90));
        typFormy->setLayoutDirection(Qt::RightToLeft);
        typFormy->setStyleSheet(QString::fromUtf8("border-style: none;\n"
"font: 75 30pt \"Tahoma\";\n"
"color: rgb(218, 0, 0);"));
        typFormy->setAlignment(Qt::AlignCenter);
        potwierdz = new QPushButton(ConfirmPurchaseScreen);
        potwierdz->setObjectName(QString::fromUtf8("potwierdz"));
        potwierdz->setGeometry(QRect(60, 380, 400, 90));
        potwierdz->setMinimumSize(QSize(0, 0));
        potwierdz->setMaximumSize(QSize(16777215, 16777215));
        potwierdz->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 13, 13);\n"
"border-style: solid;\n"
"border-width:4px;\n"
"border-radius:30px;\n"
"border-color: white;\n"
"\n"
"font: 75 30pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));
        close = new QPushButton(ConfirmPurchaseScreen);
        close->setObjectName(QString::fromUtf8("close"));
        close->setGeometry(QRect(60, 480, 400, 90));
        close->setMinimumSize(QSize(0, 0));
        close->setMaximumSize(QSize(16777215, 16777215));
        close->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 13, 13);\n"
"border-style: solid;\n"
"border-width:4px;\n"
"border-radius:30px;\n"
"border-color: white;\n"
"\n"
"font: 75 30pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));

        retranslateUi(ConfirmPurchaseScreen);

        QMetaObject::connectSlotsByName(ConfirmPurchaseScreen);
    } // setupUi

    void retranslateUi(QDialog *ConfirmPurchaseScreen)
    {
        ConfirmPurchaseScreen->setWindowTitle(QCoreApplication::translate("ConfirmPurchaseScreen", "Dialog", nullptr));
        kupujesz->setText(QCoreApplication::translate("ConfirmPurchaseScreen", "KUPUJESZ:", nullptr));
        typKarnetu->setText(QCoreApplication::translate("ConfirmPurchaseScreen", "KUPUJESZ", nullptr));
        forma->setText(QCoreApplication::translate("ConfirmPurchaseScreen", "P\305\201AC\304\204C FORM\304\204:", nullptr));
        typFormy->setText(QCoreApplication::translate("ConfirmPurchaseScreen", "KUPUJESZ", nullptr));
        potwierdz->setText(QCoreApplication::translate("ConfirmPurchaseScreen", "POTWIERD\305\271", nullptr));
        close->setText(QCoreApplication::translate("ConfirmPurchaseScreen", "ANULUJ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConfirmPurchaseScreen: public Ui_ConfirmPurchaseScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIRMPURCHASESCREEN_H
