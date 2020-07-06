#include "AddOrEditClubMember.h"
#include "ui_AddOrEditClubMember.h"
#include "RegistrationInfoScreen.h"

AddOrEditClubMember::AddOrEditClubMember(QWidget *parent, UserDAO *toEdit) :
    QDialog(parent),
    ui(new Ui::AddOrEditClubMember)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    keyboard = keyboard->getKeyboard();
    keyboard->move(0,388); //418

    this->ui->imie->installEventFilter(this);
    this->ui->nazwisko->installEventFilter(this);
    this->ui->haslo->installEventFilter(this);
    this->ui->email->installEventFilter(this);
    this->ui->imieLabel->setFocus();

    this->toEdit = toEdit;
    if(toEdit !=nullptr)
    {
        this->ui->imie->setText(QString(toEdit->name.c_str()));
        this->ui->nazwisko->setText(QString(toEdit->surname.c_str()));
        this->ui->email->setText(QString(toEdit->email.c_str()));
        this->ui->haslo->setText(QString(toEdit->hashed_pswd.c_str()));
        this->ui->rfid->setText(QString(toEdit->rfid.c_str()));
    }
    kodokanDAO = kodokanDAO->getInstance();

    this->threadRun=true;
    loopThread = new LoopThread(threadRun);

     connect( loopThread, SIGNAL(przylozonoKarte(QString)), this, SLOT(przylozonoKarte(QString)));
}

AddOrEditClubMember::~AddOrEditClubMember()
{
    delete ui;
}

bool AddOrEditClubMember::eventFilter(QObject *obj, QEvent *event)
{
    if( obj == ui->imie && event->type() == QEvent::FocusIn)
    {
        ui->imie->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(200, 200, 200);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
        ui->nazwisko->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
        ui->email->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
        ui->haslo->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
        ui->rfid->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
        keyboard->activate(2, ui->imie, ui->zatwierdz);
        keyboard->show();
        keyboard->activateWindow();
    }
    else if( obj == ui->nazwisko && event->type() == QEvent::FocusIn)
    {
        ui->nazwisko->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(200, 200, 200);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
        ui->imie->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
        ui->email->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
        ui->haslo->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
        ui->rfid->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
        keyboard->activate(2, ui->nazwisko, ui->zatwierdz);
        keyboard->show();
        keyboard->activateWindow();
    }
    else if( obj == ui->email && event->type() == QEvent::FocusIn)
    {
        ui->email->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(200, 200, 200);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
        ui->imie->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
        ui->nazwisko->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
        ui->haslo->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
        ui->rfid->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
        keyboard->setType(1);
        keyboard->activate(0, ui->email, ui->zatwierdz);
        keyboard->show();
        keyboard->activateWindow();  
    }
    else if( obj == ui->haslo && event->type() == QEvent::FocusIn)
    {
        ui->haslo->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(200, 200, 200);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
        ui->nazwisko->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
        ui->imie->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
        ui->email->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
        ui->rfid->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
        keyboard->setType(1);
        keyboard->activate(0, ui->haslo, ui->zatwierdz);
        keyboard->show();
        keyboard->activateWindow();
    }
    else if( obj == ui->rfid) // && event->type() == QEvent::FocusIn
    {
        ui->nazwisko->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
        ui->imie->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
        ui->email->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
        ui->haslo->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
    }
    if(!loopThread->isRunning())
    {
        qDebug() << "Start watek";
        this->threadRun = true;
        loopThread->start();
    }
    return false;
}

void AddOrEditClubMember::mousePressEvent(QMouseEvent *event)
{
    ui->imie->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
    ui->nazwisko->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
    ui->email->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
    ui->haslo->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
    ui->imieLabel->setFocus();
    keyboard->hide();
}

void AddOrEditClubMember::on_powrot_clicked()
{
    threadRun = false;
    delete toEdit;
    this->close();
}

void AddOrEditClubMember::on_zatwierdz_clicked()
{
    if(this->ui->imie->text().isEmpty() || this->ui->nazwisko->text().isEmpty() ||  this->ui->email->text().isEmpty()  ||  this->ui->haslo->text().isEmpty())
    {
        RegistrationInfoScreen *registrationInfoScreen = new RegistrationInfoScreen(nullptr, "PUSTE POLE!");
        registrationInfoScreen->move(162,234);
        registrationInfoScreen->show();
        return;
    }
    if(this->toEdit !=nullptr)
    {


        if(toEdit->name.compare(this->ui->imie->text().toStdString()) != 0)
            toEdit->update_user_name(this->ui->imie->text().toStdString());


        if(toEdit->surname.compare(this->ui->nazwisko->text().toStdString()) != 0)
            toEdit->update_user_surname(this->ui->nazwisko->text().toStdString());

        if(toEdit->email.compare(this->ui->email->text().toStdString()) != 0)
            toEdit->update_user_email(this->ui->email->text().toStdString());

        if(toEdit->hashed_pswd.compare(this->ui->haslo->text().toStdString()) != 0)
            toEdit->update_user_hashed_pswd(this->ui->haslo->text().toStdString());

        if(toEdit->rfid.compare(this->ui->rfid->text().toStdString()) != 0)
            toEdit->add_update_rfid(this->ui->rfid->text().toStdString());

    }
    else
    {

        kodokanDAO->add_user(this->ui->email->text().toStdString(),
                            this->ui->email->text().toStdString(),
                            this->ui->imie->text().toStdString(),
                            this->ui->nazwisko->text().toStdString(),
                            this->ui->haslo->text().toStdString());
    }

    on_powrot_clicked();
}

void AddOrEditClubMember::przylozonoKarte(QString karta)
{
    this->ui->rfid->setText(karta);
}
