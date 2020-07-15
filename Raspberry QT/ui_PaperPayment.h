/********************************************************************************
** Form generated from reading UI file 'PaperPayment.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAPERPAYMENT_H
#define UI_PAPERPAYMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_PaperPayment
{
public:
    QLabel *wprowadz;
    QLabel *kwota;
    QPushButton *anuluj;
    QLabel *info;

    void setupUi(QDialog *PaperPayment)
    {
        if (PaperPayment->objectName().isEmpty())
            PaperPayment->setObjectName(QString::fromUtf8("PaperPayment"));
        PaperPayment->resize(1024, 768);
        PaperPayment->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 13, 13);"));
        wprowadz = new QLabel(PaperPayment);
        wprowadz->setObjectName(QString::fromUtf8("wprowadz"));
        wprowadz->setGeometry(QRect(12, 130, 1000, 81));
        wprowadz->setStyleSheet(QString::fromUtf8("font: 75 26pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));
        wprowadz->setAlignment(Qt::AlignCenter);
        kwota = new QLabel(PaperPayment);
        kwota->setObjectName(QString::fromUtf8("kwota"));
        kwota->setGeometry(QRect(12, 250, 1000, 81));
        kwota->setStyleSheet(QString::fromUtf8("font: 75 30pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));
        kwota->setAlignment(Qt::AlignCenter);
        anuluj = new QPushButton(PaperPayment);
        anuluj->setObjectName(QString::fromUtf8("anuluj"));
        anuluj->setGeometry(QRect(153, 440, 718, 108));
        anuluj->setMinimumSize(QSize(718, 108));
        anuluj->setMaximumSize(QSize(718, 108));
        anuluj->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 13, 13);\n"
"border-style: solid;\n"
"border-width:4px;\n"
"border-radius:30px;\n"
"border-color: white;\n"
"max-width:710px;\n"
"max-height:100px;\n"
"min-width:710px;\n"
"min-height:100px;\n"
"\n"
"font: 75 30pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));
        info = new QLabel(PaperPayment);
        info->setObjectName(QString::fromUtf8("info"));
        info->setGeometry(QRect(12, 600, 1000, 81));
        info->setStyleSheet(QString::fromUtf8("font: 75 30pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));
        info->setAlignment(Qt::AlignCenter);

        retranslateUi(PaperPayment);

        QMetaObject::connectSlotsByName(PaperPayment);
    } // setupUi

    void retranslateUi(QDialog *PaperPayment)
    {
        PaperPayment->setWindowTitle(QCoreApplication::translate("PaperPayment", "Dialog", nullptr));
        wprowadz->setText(QCoreApplication::translate("PaperPayment", "WPROWADZ KWOTE:", nullptr));
        kwota->setText(QString());
        anuluj->setText(QCoreApplication::translate("PaperPayment", "ANULUJ", nullptr));
        info->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PaperPayment: public Ui_PaperPayment {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAPERPAYMENT_H
