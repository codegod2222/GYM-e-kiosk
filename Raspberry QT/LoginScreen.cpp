#include "LoginScreen.h"
#include "ui_LoginScreen.h"
#include "LoggedScreen.h"

LoginScreen::LoginScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginScreen)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

LoginScreen::~LoginScreen()
{
    delete ui;
}

void LoginScreen::on_powrot_clicked()
{
    this->close();
}

void LoginScreen::on_zaloguj_clicked()
{
    QString login = ui->login->text();
    QString password = ui->password->text();

    if(login == "U" && password == "u")
    {
        ui->komunikat->setText("ZALOGOWANO POMYŚLNIE");
        LoggedScreen *loggedScreen = new LoggedScreen(nullptr,login,this);
        loggedScreen->show();
        loggedScreen->move(0,0);
    }
    else
    {
        ui->komunikat->setText("DANE LOGOWANIA NIEPOPRAWNE!");
    }
}
