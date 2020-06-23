#include "LoginScreen.h"
#include "ui_LoginScreen.h"
#include "LoggedScreen.h"
#include "LoggedUser.h"
#include "Keyboard.h"

int LoginScreen::ile = 0;

LoginScreen::LoginScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginScreen)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    keyboard = new Keyboard(nullptr, this->ui->zaloguj);
    keyboard->move(0,388); //418
    ui->komunikat->hide();
    ile++;
}

LoginScreen::~LoginScreen()
{
    closed=true;
    delete ui;
    delete keyboard;
    ile--;
}

void LoginScreen::on_powrot_clicked()
{
    ui->login->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
    ui->password->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
    ui->komunikat->setText("");
    ui->login->setText("");
    ui->password->setText("");
    keyboard->hide();
    closed=true;
    this->close();
}

void LoginScreen::on_zaloguj_clicked()
{
    QString login = ui->login->text();
    QString password = ui->password->text();

    if(login == "U" && password == "u")
    {
        LoggedUser *loggedUser = new LoggedUser("Daniel","Kaleta","danikal410@student.polsl.pl","tajne");
        ui->komunikat->show();
        ui->komunikat->setText("ZALOGOWANO POMYŚLNIE");
        LoggedScreen *loggedScreen = new LoggedScreen(nullptr,loggedUser,this);
        loggedScreen->move(0,0);
        loggedScreen->show();

        on_powrot_clicked();
    }
    else
    {
        ui->komunikat->show();
        ui->komunikat->setText("DANE LOGOWANIA NIEPOPRAWNE!");
    }
}

void LoginScreen::loop()
{
    while(this->isVisible())
    {
        //Jezeli nadejdzie pora wpisywania loginu lub hasla wywoluje klawiature
        if(ui->login->hasFocus())
        {
            ui->login->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(200, 200, 200);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
            ui->password->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
            keyboard->activate(ui->login);
            keyboard->show();
            keyboard->activateWindow();
        }
        else if(ui->password->hasFocus())
        {
            ui->password->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(200, 200, 200);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
            ui->login->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
            keyboard->activate(ui->password);
            keyboard->show();
            keyboard->activateWindow();
        }
        qApp->processEvents();
    }
}

void LoginScreen::mousePressEvent(QMouseEvent *event)
{
    ui->login->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
    ui->password->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
    ui->label->setFocus();
    keyboard->hide();
}
