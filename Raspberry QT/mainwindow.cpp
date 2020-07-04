#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "LoginScreen.h"
#include "LoopThread.h"
#include <string>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    this->threadRun=true;
    loopThread = new LoopThread(threadRun);
    connect( loopThread, SIGNAL(przylozonoKarte(QString)), this, SLOT(przylozonoKarte(QString)));
    this->installEventFilter(this);
    //kodokanDAO = kodokanDAO->getInstance();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_kupKarnetButton_clicked()
{
    qDebug() << "Stop watek";
    threadRun = false;
    if(buyingPassScreen == nullptr)
    {
        buyingPassScreen = new BuyingPassScreen(nullptr,false);
        buyingPassScreen->move(0,0);
        buyingPassScreen->show();
    }
    else
    {
        buyingPassScreen->show();
    }
}

void MainWindow::on_zalogujSieButton_clicked()
{
    qDebug() << "Stop watek";
    threadRun = false;
    if(loginScreen == nullptr)
    {
        loginScreen = new LoginScreen();
        loginScreen->move(0,0);
        loginScreen->show();
    }
    else
    {
        loginScreen->show();
    }
}

void MainWindow::on_zalozKontoButton_clicked()
{
    qDebug() << "Stop watek";
    threadRun = false;
    if(registrationScreen == nullptr)
    {
        registrationScreen = new RegistrationScreen();
        registrationScreen->move(0,0);
        registrationScreen->show();
    }
    else
    {
        registrationScreen->show();
    }
}

void MainWindow::on_administracja_clicked()
{
    if(administrationScreen == nullptr)
    {
        administrationScreen = new AdministrationScreen();
        administrationScreen->move(0,0);
        administrationScreen->show();
    }
    else
    {
        administrationScreen->show();
    }
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if(event->type() == QEvent::WindowActivate)
    {
        if(!loopThread->isRunning())
        {
            qDebug() << "Start watek";
            this->threadRun = true;
            loopThread->start();

        }
    }
    return false;
}

void MainWindow::przylozonoKarte(QString rfid)
{
    /*qDebug() << rfid;
    UserDAO loggedUser = kodokanDAO->authorize_user(rfid.toStdString());
    LoggedScreen *loggedScreen = new LoggedScreen(nullptr,loggedUser);
    loggedScreen->move(0,0);
    loggedScreen->show();*/
}
