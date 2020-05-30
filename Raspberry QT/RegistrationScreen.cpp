#include "RegistrationScreen.h"
#include "ui_RegistrationScreen.h"
#include "QMouseEvent"

RegistrationScreen::RegistrationScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegistrationScreen)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    this->setMouseTracking(true);

}

RegistrationScreen::~RegistrationScreen()
{
    delete ui;
}

void RegistrationScreen::loop()
{
    while(1)
    {
        if(ui->email->hasFocus())
        {
            ui->nazwisko->hide();
            ui->nazwiskoLabel->hide();
            ui->imie->hide();
            ui->imie->hide();

            ui->email->setGeometry(359,62,508,100);
            ui->emailLabel->setGeometry(153,62,200,100);

            ui->haslo->setGeometry(359,159,508,100);
            ui->hasloLabel->setGeometry(153,159,200,100);
        }
        else if(ui->haslo->hasFocus())
        {
            ui->nazwisko->hide();
            ui->nazwiskoLabel->hide();
            ui->imie->hide();
            ui->imieLabel->hide();

            ui->email->setGeometry(359,62,508,100);
            ui->emailLabel->setGeometry(153,62,200,100);

            ui->haslo->setGeometry(359,159,508,100);
            ui->hasloLabel->setGeometry(153,159,200,100);
            QMouseEvent event1(QEvent::MouseButtonPress, QPoint(1,1),
            Qt::LeftButton,
            Qt::LeftButton,
            Qt::NoModifier );
            QApplication::sendEvent(ui->powrot, &event1);
            QApplication::sendEvent(this, &event1);
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

            ui->email->setGeometry(359,256,508,100);
            ui->emailLabel->setGeometry(153,256,200,100);

            ui->haslo->setGeometry(359,353,508,100);
            ui->hasloLabel->setGeometry(153,353,200,100);
        }
        qApp->processEvents();
    }
}

void RegistrationScreen::on_nazwisko_editingFinished()
{
    ui->email->setFocus();
}

void RegistrationScreen::on_haslo_editingFinished()
{
    ui->emailLabel->setFocus();
}

void RegistrationScreen::on_powrot_clicked()
{
        this->close();
}
