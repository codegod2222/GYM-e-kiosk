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
    this->loggedUser = loggedUser;
    this->loggedScreen = loggedScreen;
}

DataChangeScreen::~DataChangeScreen()
{
    delete ui;
}

void DataChangeScreen::on_powrot_clicked()
{
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
    passwordChangeScreen = new PasswordChangeScreen(nullptr, loggedUser);
    passwordChangeScreen->move(0,0);
    passwordChangeScreen->show();
}
