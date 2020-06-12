#include "PasswordChangeScreen.h"
#include "ui_PasswordChangeScreen.h"

PasswordChangeScreen::PasswordChangeScreen(QWidget *parent, LoggedUser *loggedUser) :
    QDialog(parent),
    ui(new Ui::PasswordChangeScreen)
{
    this->loggedUser = loggedUser;
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

PasswordChangeScreen::~PasswordChangeScreen()
{
    delete ui;
}

void PasswordChangeScreen::on_close_clicked()
{
    this->close();
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
