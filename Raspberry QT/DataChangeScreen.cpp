#include "DataChangeScreen.h"
#include "ui_DataChangeScreen.h"

DataChangeScreen::DataChangeScreen(QWidget *parent, LoggedUser *loggedUser, LoggedScreen *loggedScreen) :
    QDialog(parent),
    ui(new Ui::DataChangeScreen)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    ui->imie->setText(loggedUser->getFirstName());
    ui->nazwisko->setText(loggedUser->getLastName());
    ui->email->setText(loggedUser->getEmail());
    ui->imieLabel->setFocus();

    this->loggedUser = loggedUser;
    this->loggedScreen = loggedScreen;

    keyboard = keyboard->getKeyboard();
    keyboard->move(0,388); //418
}

DataChangeScreen::~DataChangeScreen()
{
    delete ui;
}

void DataChangeScreen::on_powrot_clicked()
{
    ui->imie->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
    ui->nazwisko->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
    ui->email->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
    keyboard->hide();
    this->close();
}

void DataChangeScreen::on_zatwierdzZmiany_clicked()
{
    loggedUser->setFirstName(ui->imie->text());
    loggedUser->setLastName((ui->nazwisko->text()));
    loggedUser->setEmail(ui->email->text());

    connect( this, SIGNAL(wyslijZmianeDanych()), loggedScreen, SLOT(odbierzZmianeDanych()));
    emit wyslijZmianeDanych();

    this->close();
}

void DataChangeScreen::on_zmienHaslo_clicked()
{
    if(passwordChangeScreen == nullptr)
    {
        passwordChangeScreen = new PasswordChangeScreen(nullptr, loggedUser);
        passwordChangeScreen->move(0,0);
        passwordChangeScreen->show();
        passwordChangeScreen->loop();
    }
    else
    {
        passwordChangeScreen->show();
        passwordChangeScreen->loop();
    }
}

void DataChangeScreen::loop()
{
    while(this->isVisible())
    {
        //Jezeli nadejdzie pora wpisywania loginu lub hasla wywoluje klawiature
        if(ui->imie->hasFocus())
        {
            ui->imie->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(200, 200, 200);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
            ui->nazwisko->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
            ui->email->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
            keyboard->activate(ui->imie, ui->zatwierdzZmiany);
            keyboard->show();
            keyboard->activateWindow();
        }
        else if(ui->nazwisko->hasFocus())
        {
            ui->nazwisko->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(200, 200, 200);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
            ui->imie->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
            ui->email->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
            keyboard->activate(ui->nazwisko, ui->zatwierdzZmiany);
            keyboard->show();
            keyboard->activateWindow();
        }
        else if(ui->email->hasFocus())
        {
            ui->email->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(200, 200, 200);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
            ui->nazwisko->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
            ui->imie->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
            keyboard->activate(ui->email, ui->zatwierdzZmiany);
            keyboard->show();
            keyboard->activateWindow();
        }
        qApp->processEvents();
    }
}

void DataChangeScreen::mousePressEvent(QMouseEvent *event)
{
    ui->imie->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
    ui->nazwisko->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
    ui->email->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
    ui->imieLabel->setFocus();
    keyboard->hide();
}
