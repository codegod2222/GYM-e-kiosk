#include "LoggedScreen.h"
#include "ui_LoggedScreen.h"

LoggedScreen::LoggedScreen(QWidget *parent, QString loggedUser, LoginScreen *loginScreen) :
    QDialog(parent),
    ui(new Ui::LoggedScreen)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    this->loggedUser = loggedUser;
    this->loginScreen = loginScreen;
    ui->zalogowanyJako->setText(loggedUser);
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
