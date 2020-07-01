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
    keyboard = keyboard->getKeyboard();
    keyboard->move(0,388); //418
    ui->komunikat->hide();
    ile++;

    ui->login->installEventFilter(this);
    ui->password->installEventFilter(this);

    ui->login->setFocus();

    kodokanDAO = kodokanDAO->getInstance();
}

LoginScreen::~LoginScreen()
{
    delete ui;
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
    this->close();
}

void LoginScreen::on_zaloguj_clicked()
{
    QString login = ui->login->text();
    QString password = ui->password->text();

    UserDAO *loggedUser = kodokanDAO->authorize_user(login.toStdString(), password.toStdString());

    if(loggedUser != nullptr)
    {
        ui->komunikat->show();
        ui->komunikat->setText("ZALOGOWANO POMYŚLNIE");
        LoggedScreen *loggedScreen = new LoggedScreen(this,loggedUser);
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

void LoginScreen::mousePressEvent(QMouseEvent *event)
{
    ui->login->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
    ui->password->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
    ui->label->setFocus();
    keyboard->hide();
}

bool LoginScreen::eventFilter(QObject *obj, QEvent *event)
{
    if( obj == ui->login && event->type() == QEvent::FocusIn)
    {
        ui->login->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(200, 200, 200);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
        ui->password->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
        keyboard->activate(ui->login, ui->zaloguj);
        keyboard->show();
        keyboard->activateWindow();
    }
    else if( obj == ui->password && event->type() == QEvent::FocusIn)
    {
        ui->password->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(200, 200, 200);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
        ui->login->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
        keyboard->activate(ui->password, ui->zaloguj);
        keyboard->show();
        keyboard->activateWindow();
    }
    return false;
}
