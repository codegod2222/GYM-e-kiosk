#include "RegistrationScreen.h"
#include "ui_RegistrationScreen.h"
#include "QMouseEvent"
#include "LoggedUser.h"
#include "LoggedScreen.h"

RegistrationScreen::RegistrationScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegistrationScreen)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    setMouseTracking(true);
}

RegistrationScreen::~RegistrationScreen()
{
    delete ui;
}

void RegistrationScreen::loop()
{
    while(1)
    {
        //Jezeli nadejdzie pora wpisywania hasla wystawiam te pola wyzej,
        //aby klawiatura ekranowa nie zaslaniala
        if(ui->haslo->hasFocus() || ui->powtHaslo->hasFocus())
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

            QMouseEvent *event1 = new QMouseEvent(QEvent::MouseButtonPress, QPoint(370,10),
            Qt::LeftButton,
            Qt::LeftButton,
            Qt::NoModifier );
            QCoreApplication::sendEvent(ui->haslo, event1);

            QMouseEvent *event3 = new QMouseEvent(QEvent::MouseButtonRelease, QPoint(370,10),
            Qt::LeftButton,
            Qt::LeftButton,
            Qt::NoModifier );
            QCoreApplication::sendEvent(ui->haslo, event3);
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

            ui->email->setGeometry(359,182,508,100);
            ui->emailLabel->setGeometry(153,182,200,100);

            ui->haslo->setGeometry(359,272,508,100);
            ui->hasloLabel->setGeometry(153,272,200,100);

            ui->powtHaslo->setGeometry(359,362,508,100);
            ui->powtHasloLabel->setGeometry(153,362,200,100);
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
    //ui->emailLabel->setFocus();
}

void RegistrationScreen::on_powrot_clicked()
{
        this->close();
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
    registrationInfoScreen = new RegistrationInfoScreen(nullptr, "ZAREJESTROWANO POMYŚLNIE");
    registrationInfoScreen->move(162,234);
    registrationInfoScreen->exec();

    while(registrationInfoScreen->isActiveWindow())
    {

    }

    LoggedUser *loggedUser = new LoggedUser(imie,nazwisko,email,haslo);
    LoggedScreen *loggedScreen = new LoggedScreen(nullptr,loggedUser, this);
    loggedScreen->move(0,0);
    loggedScreen->show();
}
