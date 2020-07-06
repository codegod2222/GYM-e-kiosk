/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *kupKarnetButton;
    QPushButton *zalozKontoButton;
    QPushButton *zalogujSieButton;
    QFrame *frame;
    QPushButton *administracja;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(1024, 768);
        MainWindow->setMinimumSize(QSize(1024, 768));
        MainWindow->setMaximumSize(QSize(1024, 768));
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 13, 13);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        kupKarnetButton = new QPushButton(centralwidget);
        kupKarnetButton->setObjectName(QString::fromUtf8("kupKarnetButton"));
        kupKarnetButton->setGeometry(QRect(515, 2, 370, 370));
        kupKarnetButton->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 13, 13);\n"
"border-style: solid;\n"
"border-width:4px;\n"
"border-radius:185px;\n"
"border-color: white;\n"
"max-width:362px;\n"
"max-height:362px;\n"
"min-width:362px;\n"
"min-height:362px;\n"
"\n"
"font: 75 30pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));
        kupKarnetButton->setIconSize(QSize(16, 16));
        zalozKontoButton = new QPushButton(centralwidget);
        zalozKontoButton->setObjectName(QString::fromUtf8("zalozKontoButton"));
        zalozKontoButton->setGeometry(QRect(515, 376, 370, 370));
        zalozKontoButton->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 13, 13);\n"
"border-style: solid;\n"
"border-width:4px;\n"
"border-radius:185px;\n"
"border-color: white;\n"
"max-width:362px;\n"
"max-height:362px;\n"
"min-width:362px;\n"
"min-height:362px;\n"
"\n"
"font: 75 30pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));
        zalogujSieButton = new QPushButton(centralwidget);
        zalogujSieButton->setObjectName(QString::fromUtf8("zalogujSieButton"));
        zalogujSieButton->setGeometry(QRect(138, 376, 370, 370));
        zalogujSieButton->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 13, 13);\n"
"border-style: solid;\n"
"border-width:4px;\n"
"border-radius:185px;\n"
"border-color: white;\n"
"max-width:362px;\n"
"max-height:362px;\n"
"min-width:362px;\n"
"min-height:362px;\n"
"\n"
"font: 75 30pt \"Tahoma\";\n"
"color: rgb(255, 255, 255);"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(138, 2, 370, 370));
        frame->setAutoFillBackground(false);
        frame->setStyleSheet(QString::fromUtf8("background-image: url(:/logo 370.png);\n"
"background-color: rgb(0, 0, 0);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        administracja = new QPushButton(centralwidget);
        administracja->setObjectName(QString::fromUtf8("administracja"));
        administracja->setGeometry(QRect(0, 0, 131, 111));
        administracja->setStyleSheet(QString::fromUtf8("background-color: rgb(13, 13, 13);"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1024, 28));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Kodokan", 0, QApplication::UnicodeUTF8));
        kupKarnetButton->setText(QApplication::translate("MainWindow", "KUP KARNET", 0, QApplication::UnicodeUTF8));
        zalozKontoButton->setText(QApplication::translate("MainWindow", "ZA\305\201\303\223\305\273 KONTO", 0, QApplication::UnicodeUTF8));
        zalogujSieButton->setText(QApplication::translate("MainWindow", "ZALOGUJ SI\304\230", 0, QApplication::UnicodeUTF8));
        administracja->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
