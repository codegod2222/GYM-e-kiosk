#include "AddOrEditClubMember.h"
#include "ui_AddOrEditClubMember.h"
#include "RegistrationInfoScreen.h"

AddOrEditClubMember::AddOrEditClubMember(QWidget *parent, ClubMember *toEdit, std::vector<ClubMember> *czlonkowie) :
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

    this->czlonkowie = czlonkowie;
    this->toEdit = toEdit;
    if(toEdit !=nullptr)
    {
        this->ui->imie->setText(QString(toEdit->imie.c_str()));
        this->ui->nazwisko->setText(QString(toEdit->nazwisko.c_str()));
        this->ui->email->setText(QString(toEdit->email.c_str()));
        this->ui->haslo->setText(QString(toEdit->haslo.c_str()));
    }
    //kodokanDAO = kodokanDAO->getInstance();
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
        keyboard->setType(1);
        keyboard->activate(0, ui->haslo, ui->zatwierdz);
        keyboard->show();
        keyboard->activateWindow();
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
        /*
        UserDAO *toEdit = kodokanDAO->authorize_user(toEdit->email, toEdit->hashed_pswd);

        if(toEdit->name.compare(this->ui->imie->text().toStdString()) != 0)
            toEdit->update_user_name(this->ui->imie->text().toStdString());

        if(toEdit->surname.compare(this->ui->imie->text().toStdString()) != 0)
            toEdit->update_user_surname(this->ui->nazwisko->text().toStdString());

        if(toEdit->email.compare(this->ui->imie->text().toStdString()) != 0)
            toEdit->update_user_email(this->ui->email->text().toStdString());

        if(toEdit->hashed_pswd.compare(this->ui->imie->text().toStdString()) != 0)
            toEdit->update_user_hashed_pswd(this->ui->haslo->text().toStdString());
        */
        toEdit->imie = this->ui->imie->text().toStdString();
        toEdit->nazwisko = this->ui->nazwisko->text().toStdString();
        toEdit->email = this->ui->email->text().toStdString();
        toEdit->haslo = this->ui->haslo->text().toStdString();
    }
    else
    {
        /*
        kodokanDAO.add_user(this->ui->email->text().toStdString(),
                            this->ui->email->text().toStdString(),
                            this->ui->imie->text().toStdString(),
                            this->ui->nazwisko->text().toStdString(),
                            this->ui->haslo->text().toStdString());

        */
        ClubMember newMember(this->ui->imie->text().toStdString(),
                             this->ui->nazwisko->text().toStdString(),
                             this->ui->email->text().toStdString(),
                             this->ui->haslo->text().toStdString());
        czlonkowie->push_back(newMember);
    }

    on_powrot_clicked();
}
