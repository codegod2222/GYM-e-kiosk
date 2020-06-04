#include "LoggedScreen.h"
#include "ui_LoggedScreen.h"
#include "DataChangeScreen.h"

LoggedScreen::LoggedScreen(QWidget *parent, LoggedUser *loggedUser, LoginScreen *loginScreen) :
    QDialog(parent),
    ui(new Ui::LoggedScreen)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    this->loggedUser = loggedUser;
    this->loginScreen = loginScreen;
    ui->zalogowanyJako->setText(loggedUser->getFirstName()+" "+loggedUser->getLastName());
}

LoggedScreen::~LoggedScreen()
{
    delete ui;
}

void LoggedScreen::on_wyloguj_clicked()
{
    loginScreen->close();
    this->close();
}

void LoggedScreen::on_kupKarnet_clicked()
{
    buyingPassScreen = new BuyingPassScreen(nullptr,true);
    buyingPassScreen->move(0,0);
    buyingPassScreen->show();
    buyingPassScreen->loop();
}

void LoggedScreen::on_zmienDane_clicked()
{
    DataChangeScreen *dataChangeScreen = new DataChangeScreen(nullptr, loggedUser, this);
    dataChangeScreen->move(0,0);
    dataChangeScreen->show();
}

void LoggedScreen::odbierzZmianeDanych()
{
    ui->zalogowanyJako->setText(loggedUser->getFirstName()+" "+loggedUser->getLastName());
}
