QT       += core gui

#Wylacza warningi o niewykorzystanych parametrach
QMAKE_CXXFLAGS_WARN_OFF -= -Wunused-parameter
QMAKE_CFLAGS = -Wno-unused-parameter

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

CONFIG += disable-desktop

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AddOrEditClubMember.cpp \
    AddOrEditPassScreen.cpp \
    AdministrationScreen.cpp \
    BuyingPassScreen.cpp \
    ClubMembersScreen.cpp \
    CompanyInfoScreen.cpp \
    ConfirmPurchaseScreen.cpp \
    DataChangeScreen.cpp \
    Keyboard.cpp \
    LoggedScreen.cpp \
    LoginScreen.cpp \
    LoopThread.cpp \
    PassesScreen.cpp \
    PasswordChangeScreen.cpp \
    RegistrationInfoScreen.cpp \
    RegistrationScreen.cpp \
    TakePictureScreen.cpp \
    main.cpp \
    mainwindow.cpp \
    CameraWorker.cpp \
    printer.cpp \
    rfid.cpp \
    OnlinePaymentScreen.cpp \
    ../online_payment/onlinePayment.cpp \
    ../databse_access/KodokanDAO.cpp \
    ../databse_access/UserDAO.cpp \
    ../online_payment/md5.cpp \
    PaperPayment.cpp \
    ../banknote_acceptor/acceptor_test.cpp \
    PaymentThread.cpp

HEADERS += \
    AddOrEditClubMember.h \
    AddOrEditPassScreen.h \
    AdministrationScreen.h \
    BuyingPassScreen.h \
    ClubMembersScreen.h \
    CompanyInfoScreen.h \
    ConfirmPurchaseScreen.h \
    DataChangeScreen.h \
    Keyboard.h \
    LoggedScreen.h \
    LoginScreen.h \
    LoopThread.h \
    PassesScreen.h \
    PasswordChangeScreen.h \
    RegistrationInfoScreen.h \
    RegistrationScreen.h \
    TakePictureScreen.h \
    mainwindow.h \
    CameraWorker.h \
    printer.h \
    rfid.h \
    OnlinePaymentScreen.h \
    ../online_payment/json.hpp \
    ../online_payment/md5.h \
    ../online_payment/onlinePayment.h \
    ../databse_access/KodokanDAO.h \
    ../databse_access/UserDAO.h \
    PaperPayment.h \
    ../banknote_acceptor/acceptor_test.h \
    PaymentThread.h

FORMS += \
    AddOrEditClubMember.ui \
    AddOrEditPassScreen.ui \
    AdministrationScreen.ui \
    BuyingPassScreen.ui \
    ClubMembersScreen.ui \
    CompanyInfoScreen.ui \
    ConfirmPurchaseScreen.ui \
    DataChangeScreen.ui \
    Keyboard.ui \
    LoggedScreen.ui \
    LoginScreen.ui \
    PassesScreen.ui \
    PasswordChangeScreen.ui \
    RegistrationInfoScreen.ui \
    RegistrationScreen.ui \
    TakePictureScreen.ui \
    mainwindow.ui \
    OnlinePaymentScreen.ui \
    PaperPayment.ui

TRANSLATIONS += \
    Raspberry_pl_PL.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# Requirements for raspicam
LIBS += -L/opt/vc/lib -lmmal -lmmal_core -lmmal_util
LIBS += -L/usr/local/lib -I/usr/local/include -lraspicam
LIBS += -L/usr/lib -lmysqlcppconn

LIBS += -L/usr/lib -lwiringPi

#LIBS += -E/usr/include/cppconn

LIBS += -lcurl

LIBS += -L/usr/local/lib
LIBS += -L/usr/local/lib -lwiringPi

DISTFILES += \
    AdministrationScreen.o \
    BuyingPassScreen.o \
    CameraWorker.o \
    ConfirmPurchaseScreen.o \
    DataChangeScreen.o \
    Keyboard.o \
    LoggedScreen.o \
    LoginScreen.o \
    LoopThread.o \
    Makefile \
    PasswordChangeScreen.o \
    Raspberry \
    Raspberry.pro.user \
    Raspberry.pro.user.ccf6f4f.4.9-pre1 \
    Raspberry.pro.user.d0ebc03 \
    RegistrationInfoScreen.o \
    RegistrationScreen.o \
    TakePictureScreen.o \
    dao.o \
    logo 370.png \
    main.o \
    mainwindow.o \
    moc_AdministrationScreen.o \
    moc_BuyingPassScreen.o \
    moc_CameraWorker.o \
    moc_ConfirmPurchaseScreen.o \
    moc_DataChangeScreen.o \
    moc_Keyboard.o \
    moc_LoggedScreen.o \
    moc_LoginScreen.o \
    moc_LoopThread.o \
    moc_PasswordChangeScreen.o \
    moc_RegistrationInfoScreen.o \
    moc_RegistrationScreen.o \
    moc_TakePictureScreen.o \
    moc_mainwindow.o \
    printer.o \
    qrc_resources.o \
    rfid.o \
    ../online_payment/curl/Makefile.am \
    ../online_payment/curl/Makefile.in \
    ../online_payment/libcurld.lib \
    ../online_payment/libcurl-d.dll

RESOURCES += \
    resources.qrc \
    resources.qrc
