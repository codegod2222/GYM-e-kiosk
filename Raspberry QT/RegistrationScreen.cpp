#include "RegistrationScreen.h"
#include "ui_RegistrationScreen.h"
#include "QMouseEvent"
#include "LoggedUser.h"
#include "LoggedScreen.h"
#include "TakePictureScreen.h"

RegistrationScreen::RegistrationScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegistrationScreen)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    keyboard = keyboard->getKeyboard();
    keyboard->move(0,388); //418

    ui->imie->installEventFilter(this);
    ui->nazwisko->installEventFilter(this);
    ui->email->installEventFilter(this);
    ui->haslo->installEventFilter(this);
    ui->powtHaslo->installEventFilter(this);
    ui->nazwiskoLabel->installEventFilter(this);

    //kodokanDAO = kodokanDAO->getInstance();
}

RegistrationScreen::~RegistrationScreen()
{
    delete ui;
}

bool RegistrationScreen::eventFilter(QObject *obj, QEvent *event)
{
    if( (obj == ui->haslo || obj == ui->powtHaslo) && event->type() == QEvent::FocusIn)
    {
        ui->nazwisko->hide();
        ui->nazwiskoLabel->hide();
        ui->imie->hide();
        ui->imieLabel->hide();
        ui->email->hide();
        ui->emailLabel->hide();

        ui->haslo->setGeometry(359,2,508,100);
        ui->hasloLabel->setGeometry(153,2,200,100);
        ui->powtHaslo->setGeometry(359,92,508,100);
        ui->powtHasloLabel->setGeometry(153,92,508,100);

        if(obj == ui->haslo)
        {
            ui->haslo->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(200, 200, 200);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
            ui->powtHaslo->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
            keyboard->activate(0, ui->haslo, ui->pushButton);
        }
        else
        {
            ui->powtHaslo->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(200, 200, 200);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
            ui->haslo->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
            keyboard->activate(0, ui->powtHaslo, ui->pushButton);
        }
        keyboard->show();
        keyboard->activateWindow();
    }
    else if( (obj == ui->nazwisko || obj == ui->email || obj == ui->imie || obj == ui->nazwiskoLabel) && event->type() == QEvent::FocusIn)
    {
        ui->nazwisko->show();
        ui->nazwiskoLabel->show();
        ui->email->show();
        ui->emailLabel->show();
        ui->haslo->show();
        ui->hasloLabel->show();
        ui->imie->show();
        ui->imieLabel->show();

        ui->email->setGeometry(359,182,508,100);
        ui->emailLabel->setGeometry(153,182,200,100);
        ui->haslo->setGeometry(359,272,508,100);
        ui->hasloLabel->setGeometry(153,272,200,100);
        ui->powtHaslo->setGeometry(359,362,508,100);
        ui->powtHasloLabel->setGeometry(153,362,200,100);

        if( obj == ui->imie)
        {
            ui->imie->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(200, 200, 200);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
            ui->nazwisko->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
            ui->email->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
            keyboard->activate(2, ui->imie, ui->pushButton);
            keyboard->show();
            keyboard->activateWindow();
        }
        else if(obj == ui->nazwisko)
        {
            ui->nazwisko->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(200, 200, 200);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
            ui->imie->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
            ui->email->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
            keyboard->activate(2, ui->nazwisko, ui->pushButton);
            keyboard->show();
            keyboard->activateWindow();
        }
        else if(obj == ui->email)
        {
            ui->email->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(200, 200, 200);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
            ui->nazwisko->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
            ui->imie->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
            keyboard->activate(0, ui->email, ui->pushButton);
            keyboard->show();
            keyboard->activateWindow();
        }
    }
    return false;
}

void RegistrationScreen::on_powrot_clicked()
{
    ui->imie->setText("");
    ui->nazwisko->setText("");
    ui->haslo->setText("");
    ui->powtHaslo->setText("");
    ui->email->setText("");
    keyboard->hide();
    this->close();
}

void RegistrationScreen::mousePressEvent(QMouseEvent *event)
{
    ui->imie->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
    ui->nazwisko->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
    ui->email->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
    ui->haslo->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
    ui->powtHaslo->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
    ui->nazwiskoLabel->show();
    ui->nazwiskoLabel->setFocus();
    keyboard->hide();
}

void RegistrationScreen::on_pushButton_clicked()
{
    QString imie = ui->imie->text();
    QString nazwisko = ui->nazwisko->text();
    QString email = ui->email->text();
    QString haslo = ui->haslo->text();
    QString powtHaslo = ui->powtHaslo->text();

    //Sprawdzanie czy jakies pole jest puste
    if(imie.isEmpty())
    {
        registrationInfoScreen = new RegistrationInfoScreen(nullptr, "IMIĘ NIE MOŻE BYĆ PUSTE");
        registrationInfoScreen->move(162,234);
        registrationInfoScreen->show();
        return;
    }
    if(nazwisko.isEmpty())
    {
        registrationInfoScreen = new RegistrationInfoScreen(nullptr, "NAZWISKO NIE MOŻE BYĆ PUSTE");
        registrationInfoScreen->move(162,234);
        registrationInfoScreen->show();
        return;
    }
    if(email.isEmpty())
    {
        registrationInfoScreen = new RegistrationInfoScreen(nullptr, "EMAIL NIE MOŻE BYĆ PUSTY");
        registrationInfoScreen->move(162,234);
        registrationInfoScreen->show();
        return;
    }
    if(haslo.isEmpty())
    {
        registrationInfoScreen = new RegistrationInfoScreen(nullptr, "HASŁO NIE MOŻE BYĆ PUSTE");
        registrationInfoScreen->move(162,234);
        registrationInfoScreen->show();
        return;
    }
    //Sprawdzanie, czy powtorzone haslo jest takie samo
    if(haslo.compare(powtHaslo))
    {
        registrationInfoScreen = new RegistrationInfoScreen(nullptr, "HASŁA NIE SĄ IDENTYCZNE");
        registrationInfoScreen->move(162,234);
        registrationInfoScreen->show();
        return;
    }

    //kodokanDAO->add_user(email.toStdString(), email.toStdString(), imie.toStdString(), nazwisko.toStdString(), haslo.toStdString());

    registrationInfoScreen = new RegistrationInfoScreen(nullptr, "ZAREJESTROWANO POMYŚLNIE");
    registrationInfoScreen->move(162,234);
    registrationInfoScreen->exec();

    while(registrationInfoScreen->isActiveWindow())
    {

    }

    /*UserDAO * loggedUser = kodokanDAO->authorize_user(email.toStdString(), haslo.toStdString());

    LoggedScreen *loggedScreen = new LoggedScreen(this,loggedUser);
    loggedScreen->move(0,0);
    loggedScreen->show();*/
    on_powrot_clicked();
}

void RegistrationScreen::on_dodajZdjecie_clicked()
{
    TakePictureScreen *takePictureScreen = new TakePictureScreen();
    takePictureScreen->move(0,0);
    takePictureScreen->show();
}
