#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "LoginScreen.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //QMainWindow::showFullScreen();
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
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
        buyingPassScreen->loop();
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
        loginScreen->loop();
    }
    else
    {
        loginScreen->show();
        loginScreen->loop();
    }
}

void MainWindow::on_zalozKontoButton_clicked()
{
    if(registrationScreen == nullptr)
    {
        registrationScreen = new RegistrationScreen();
        registrationScreen->move(0,0);
        registrationScreen->show();
        registrationScreen->loop();
    }
    else
    {
        registrationScreen->show();
        registrationScreen->loop();
    }
}

void MainWindow::on_administracja_clicked()
{
    administrationScreen = new AdministrationScreen();
    administrationScreen->move(0,0);
    administrationScreen->show();
}
