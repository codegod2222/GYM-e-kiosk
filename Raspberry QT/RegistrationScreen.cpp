#include "RegistrationScreen.h"
#include "ui_RegistrationScreen.h"

RegistrationScreen::RegistrationScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegistrationScreen)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

RegistrationScreen::~RegistrationScreen()
{
    delete ui;
}

void RegistrationScreen::on_powrot_clicked()
{
    this->close();
}

void RegistrationScreen::loop()
{
    while(1)
    {

        if(ui->nazwisko->hasFocus())
        {
            ui->email->hide();
            ui->emailLabel->hide();
            ui->haslo->hide();
            ui->hasloLabel->hide();
        }
        else if(ui->imie->hasFocus())
        {
            ui->email->hide();
            ui->emailLabel->hide();
            ui->haslo->hide();
            ui->hasloLabel->hide();
        }
        else if(ui->email->hasFocus())
        {
            ui->nazwisko->hide();
            ui->nazwiskoLabel->hide();
            ui->imie->hide();
            ui->imie->hide();

            ui->email->setGeometry(359,63,508,100);
            ui->emailLabel->setGeometry(153,63,200,100);

            ui->haslo->setGeometry(359,171,508,100);
            ui->hasloLabel->setGeometry(153,171,200,100);
        }
        else if(ui->haslo->hasFocus())
        {
            ui->nazwisko->hide();
            ui->nazwiskoLabel->hide();
            ui->imie->hide();
            ui->imieLabel->hide();

            ui->email->setGeometry(359,63,508,100);
            ui->emailLabel->setGeometry(153,63,200,100);

            ui->haslo->setGeometry(359,171,508,100);
            ui->hasloLabel->setGeometry(153,171,200,100);

        }
        else
        {
            ui->nazwisko->show();
            ui->nazwiskoLabel->show();
            ui->email->show();
            ui->emailLabel->show();
            ui->haslo->show();
            ui->hasloLabel->show();
            ui->imie->show();
            ui->imieLabel->show();

            ui->email->setGeometry(359,279,508,100);
            ui->emailLabel->setGeometry(153,279,200,100);

            ui->haslo->setGeometry(359,387,508,100);
            ui->hasloLabel->setGeometry(153,387,200,100);
        }
        qApp->processEvents();
    }
}

void RegistrationScreen::on_nazwisko_editingFinished()
{
    ui->haslo->setFocus();
}

void RegistrationScreen::on_haslo_editingFinished()
{
    ui->emailLabel->setFocus();
}
