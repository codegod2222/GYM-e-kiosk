#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "LoginScreen.h"
#include "LoopThread.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //QMainWindow::showFullScreen();
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    loopThread = new LoopThread();
    connect( loopThread, SIGNAL(przylozonoKarte(QString)), this, SLOT(przylozonoKarte(QString)));
    this->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_kupKarnetButton_clicked()
{
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
    administrationScreen = new AdministrationScreen();
    administrationScreen->move(0,0);
    administrationScreen->show();
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if(this->isActiveWindow())
    {
        loopThread->start();
    }
    else
    {
        loopThread->terminate();
    }
    return false;
}

void MainWindow::przylozonoKarte(QString jakiesDane)
{
    qDebug() << jakiesDane;
    LoggedUser *loggedUser = new LoggedUser("Daniel","ZMainWindow",jakiesDane,"tajne");
    LoggedScreen *loggedScreen = new LoggedScreen(nullptr,loggedUser);
    loggedScreen->move(0,0);
    loggedScreen->show();
}
