QT       += core gui

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
    AdministrationScreen.cpp \
    BuyingPassScreen.cpp \
    CompanyInfoScreen.cpp \
    ConfirmPurchaseScreen.cpp \
    DataChangeScreen.cpp \
    Keyboard.cpp \
    LoggedScreen.cpp \
    LoggedUser.cpp \
    LoginScreen.cpp \
    LoopThread.cpp \
    PassesScreen.cpp \
    PasswordChangeScreen.cpp \
    RegistrationInfoScreen.cpp \
    RegistrationScreen.cpp \
    TakePictureScreen.cpp \
    dao.cpp \
    main.cpp \
    mainwindow.cpp \
    CameraWorker.cpp \
    printer.cpp \
    rfid.cpp

HEADERS += \
    AdministrationScreen.h \
    BuyingPassScreen.h \
    CompanyInfoScreen.h \
    ConfirmPurchaseScreen.h \
    DataChangeScreen.h \
    Keyboard.h \
    LoggedScreen.h \
    LoggedUser.h \
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
    dao.h

FORMS += \
    AdministrationScreen.ui \
    BuyingPassScreen.ui \
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
    mainwindow.ui

TRANSLATIONS += \
    Raspberry_pl_PL.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# Requirements for raspicam
LIBS += -L/opt/vc/lib -lmmal -lmmal_core -lmmal_util
LIBS += -L/usr/local/lib -I/usr/local/include -lraspicam
#LIBS += -E/usr/include/cppconn    -
LIBS += -L/usr/lib -lmysqlcppconn

DISTFILES +=

RESOURCES += \
    resources.qrc
