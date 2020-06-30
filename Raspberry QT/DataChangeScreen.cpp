#include "DataChangeScreen.h"
#include "ui_DataChangeScreen.h"

DataChangeScreen::DataChangeScreen(QWidget *parent, UserDAO *loggedUser, LoggedScreen *loggedScreen) :
    QDialog(parent),
    ui(new Ui::DataChangeScreen)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    ui->imie->setText(loggedUser->name.c_str());
    ui->nazwisko->setText(loggedUser->surname.c_str());
    ui->email->setText(loggedUser->email.c_str());

    //W celu ukazania ekranu bez klawiatury i skupionego na jakimkolwiek QLineEdit
    this->ui->nazwiskoLabel->setFocus();

    this->loggedUser = loggedUser;
    this->loggedScreen = loggedScreen;

    keyboard = keyboard->getKeyboard();
    keyboard->move(0,388); //418

    this->ui->imie->installEventFilter(this);
    this->ui->nazwisko->installEventFilter(this);
    this->ui->email->installEventFilter(this);
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
    /*loggedUser->name = ui->imie->text();
    loggedUser->surname = ui->nazwisko->text();
    loggedUser->email = ui->email->text();*/

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
    }
    else
    {
        passwordChangeScreen->show();
    }
}

bool DataChangeScreen::eventFilter(QObject *obj, QEvent *event)
{
    if( obj == ui->imie && event->type() == QEvent::FocusIn)
    {
        ui->imie->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(200, 200, 200);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
        ui->nazwisko->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
        ui->email->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
        keyboard->activate(ui->imie, ui->zatwierdzZmiany);
        keyboard->show();
        keyboard->activateWindow();
    }
    else if( obj == ui->nazwisko && event->type() == QEvent::FocusIn)
    {
        ui->nazwisko->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(200, 200, 200);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
        ui->imie->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
        ui->email->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
        keyboard->activate(ui->nazwisko, ui->zatwierdzZmiany);
        keyboard->show();
        keyboard->activateWindow();
    }
    else if( obj == ui->email && event->type() == QEvent::FocusIn)
    {
        ui->email->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(200, 200, 200);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
        ui->nazwisko->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
        ui->imie->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
        keyboard->activate(ui->email, ui->zatwierdzZmiany);
        keyboard->show();
        keyboard->activateWindow();
    }
    return false;
}

void DataChangeScreen::mousePressEvent(QMouseEvent *event)
{
    ui->imie->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
    ui->nazwisko->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
    ui->email->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
    ui->imieLabel->setFocus();
    keyboard->hide();
}
