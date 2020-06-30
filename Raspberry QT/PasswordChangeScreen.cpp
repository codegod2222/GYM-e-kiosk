#include "PasswordChangeScreen.h"
#include "ui_PasswordChangeScreen.h"

PasswordChangeScreen::PasswordChangeScreen(QWidget *parent, UserDAO *loggedUser) :
    QDialog(parent),
    ui(new Ui::PasswordChangeScreen)
{
    this->loggedUser = loggedUser;
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    keyboard = keyboard->getKeyboard();
    keyboard->move(0,388); //418

    this->ui->oldPassword->installEventFilter(this);
    this->ui->newPassword->installEventFilter(this);
    this->ui->newPassword2->installEventFilter(this);
}

PasswordChangeScreen::~PasswordChangeScreen()
{
    delete ui;
}

void PasswordChangeScreen::on_close_clicked()
{
    this->close();
}

bool PasswordChangeScreen::eventFilter(QObject *obj, QEvent *event)
{
    if( obj == ui->oldPassword && event->type() == QEvent::FocusIn)
    {
        ui->oldPassword->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(200, 200, 200);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
        ui->newPassword->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
        ui->newPassword2->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
        keyboard->activate(ui->oldPassword, ui->potwierdz);
        keyboard->show();
        keyboard->activateWindow();
    }
    else if( obj == ui->newPassword && event->type() == QEvent::FocusIn)
    {
        ui->newPassword->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(200, 200, 200);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
        ui->oldPassword->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
        ui->newPassword2->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
        keyboard->activate(ui->newPassword, ui->potwierdz);
        keyboard->show();
        keyboard->activateWindow();
    }
    else if( obj == ui->newPassword2 && event->type() == QEvent::FocusIn)
    {
        ui->newPassword2->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(200, 200, 200);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
        ui->oldPassword->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
        ui->newPassword->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
        keyboard->activate(ui->newPassword2, ui->potwierdz);
        keyboard->show();
        keyboard->activateWindow();
    }
    return false;
}

void PasswordChangeScreen::mousePressEvent(QMouseEvent *event)
{
    ui->oldPassword->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
    ui->newPassword->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
    ui->newPassword2->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
    ui->forma->setFocus();
    keyboard->hide();
}

void PasswordChangeScreen::on_potwierdz_clicked()
{
    QString oldPassword = this->ui->oldPassword->text();
    int temp = oldPassword.compare(loggedUser->getPassword());
    if(temp==0)
    {
        QString newPassword = this->ui->newPassword->text();
        QString newPassword2 = this->ui->newPassword2->text();
        if(newPassword.isEmpty())
        {
            infoScreen = new RegistrationInfoScreen(nullptr, "NOWE HASŁO NIE MOŻE BYĆ PUSTE");
            infoScreen->move(162,234);
            infoScreen->show();
            return;
        }
        else if(newPassword.compare(newPassword2)!=0)
        {
            infoScreen = new RegistrationInfoScreen(nullptr, "HASŁA NIE SĄ IDENTYCZNE");
            infoScreen->move(162,234);
            infoScreen->show();
            return;
        }
        else
        {
            //loggedUser->setPassword(newPassword);
            infoScreen = new RegistrationInfoScreen(nullptr, "HASŁO POMYŚLNIE ZMIENIONE");
            infoScreen->move(162,234);
            infoScreen->show();
            return;
        }
    }
    else
    {
        infoScreen = new RegistrationInfoScreen(nullptr, "NIEPOPRAWNE STARE HASŁO");
        infoScreen->move(162,234);
        infoScreen->show();
        return;
    }
}
