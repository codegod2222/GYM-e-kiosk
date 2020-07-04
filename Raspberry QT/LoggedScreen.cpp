#include "LoggedScreen.h"
#include "ui_LoggedScreen.h"
#include <DataChangeScreen.h>

LoggedScreen::LoggedScreen(QWidget *parent, UserDAO *loggedUser) :
    QDialog(parent),
    ui(new Ui::LoggedScreen)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    this->loggedUser = loggedUser;
    //std::string temp = loggedUser->name + " " + loggedUser->surname;
    //ui->zalogowanyJako->setText(temp.c_str());
    if(parent != nullptr)
    {
        parent->close();
    }
}

LoggedScreen::~LoggedScreen()
{
    delete ui;
}

void LoggedScreen::on_wyloguj_clicked()
{
    this->close();
}

void LoggedScreen::on_kupKarnet_clicked()
{
    buyingPassScreen = new BuyingPassScreen(nullptr,true);
    buyingPassScreen->move(0,0);
    buyingPassScreen->show();
}

void LoggedScreen::on_zmienDane_clicked()
{
    if(dataChangeScreen == nullptr)
    {
        dataChangeScreen = new DataChangeScreen(nullptr, loggedUser, this);
        dataChangeScreen->move(0,0);
        dataChangeScreen->show();
    }
    else
    {
        dataChangeScreen->show();
    }
}

void LoggedScreen::odbierzZmianeDanych()
{
    //std::string temp = loggedUser->name + " " + loggedUser->surname;
    //ui->zalogowanyJako->setText(temp.c_str());
}
