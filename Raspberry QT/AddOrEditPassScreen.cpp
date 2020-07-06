#include "AddOrEditPassScreen.h"
#include "ui_AddOrEditPassScreen.h"
#include "RegistrationInfoScreen.h"
#include "QDebug"

AddOrEditPassScreen::AddOrEditPassScreen(QWidget *parent, SubscriptionType *toEdit) :
    QDialog(parent),
    ui(new Ui::AddOrEditPassScreen)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    keyboard = keyboard->getKeyboard();
    keyboard->move(0,388); //418

    this->ui->ileDni->installEventFilter(this);
    this->ui->cena->installEventFilter(this);
    this->ui->nazwa->installEventFilter(this);
    this->ui->cenaLabel->setFocus();

    this->toEdit = toEdit;
    if(toEdit !=nullptr)
    {
        this->ui->nazwa->setText(toEdit->name.c_str());
        this->ui->cena->setText(QString::number(toEdit->price));
        this->ui->ileDni->setText(QString::number(toEdit->length));
    }
    kodokanDAO = kodokanDAO->getInstance();
}

AddOrEditPassScreen::~AddOrEditPassScreen()
{
    delete ui;
}

bool AddOrEditPassScreen::eventFilter(QObject *obj, QEvent *event)
{
    if( obj == ui->cena && event->type() == QEvent::FocusIn)
    {
        ui->cena->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(200, 200, 200);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
        ui->ileDni->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
        ui->nazwa->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
        keyboard->activate(1, ui->cena, ui->zatwierdz);
        keyboard->show();
        keyboard->activateWindow();
    }
    else if( obj == ui->ileDni && event->type() == QEvent::FocusIn)
    {
        ui->ileDni->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(200, 200, 200);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
        ui->cena->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
        ui->nazwa->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
        keyboard->activate(1, ui->ileDni, ui->zatwierdz);
        keyboard->show();
        keyboard->activateWindow();
    }
    else if( obj == ui->nazwa && event->type() == QEvent::FocusIn)
    {
        ui->nazwa->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(200, 200, 200);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
        ui->ileDni->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
        ui->cena->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
        keyboard->setType(1);
        keyboard->activate(2, ui->nazwa, ui->zatwierdz);
        keyboard->show();
        keyboard->activateWindow();
    }
    return false;
}

void AddOrEditPassScreen::mousePressEvent(QMouseEvent *event)
{
    ui->cena->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
    ui->ileDni->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
    ui->nazwa->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
    ui->cenaLabel->setFocus();
    keyboard->hide();
}

void AddOrEditPassScreen::on_powrot_clicked()
{
    this->close();
}

void AddOrEditPassScreen::on_zatwierdz_clicked()
{
    if(this->ui->nazwa->text().isEmpty() || this->ui->cena->text().isEmpty() ||  this->ui->ileDni->text().isEmpty() )
    {
        RegistrationInfoScreen *registrationInfoScreen = new RegistrationInfoScreen(nullptr, "PUSTE POLE!");
        registrationInfoScreen->move(162,234);
        registrationInfoScreen->show();
        return;
    }
    if(this->toEdit !=nullptr)
    {
        std::vector<SubscriptionType> subs = kodokanDAO->get_subscription_types();

        for(auto sub : subs)
        {
            qDebug() << toEdit->name.c_str() << " " << sub.name.c_str();
            if (toEdit->name.compare(sub.name) == 0)
            {
                kodokanDAO->edit_subscription_type_name(sub.id, this->ui->nazwa->text().toStdString());
                kodokanDAO->edit_subscription_type_price(sub.id, this->ui->cena->text().toInt());
                kodokanDAO->edit_subscription_type_length(sub.id, this->ui->ileDni->text().toInt());
            }
        }
    }
    else
    {
        SubscriptionType newPass{0 , this->ui->nazwa->text().toStdString() , this->ui->ileDni->text().toInt() , this->ui->cena->text().toInt()};
        kodokanDAO->add_subscription_type(newPass);
    }
    delete toEdit;
    on_powrot_clicked();
}
