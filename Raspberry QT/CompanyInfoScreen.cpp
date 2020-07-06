#include "CompanyInfoScreen.h"
#include "ui_CompanyInfoScreen.h"

CompanyInfoScreen::CompanyInfoScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CompanyInfoScreen)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    keyboard = keyboard->getKeyboard();
    keyboard->move(0,388); //418

    ui->nazwa->installEventFilter(this);
    ui->nip->installEventFilter(this);
    ui->adres->installEventFilter(this);

    this->ui->nazwaLabel->setFocus();


    kodokanDAO = kodokanDAO->getInstance();
    std::vector<std::string> kodokanInfo = kodokanDAO->get_kodokan_info();
    this->ui->nazwa->setText(kodokanInfo.at(0).c_str());
    this->ui->adres->setText(kodokanInfo.at(1).c_str());
    this->ui->nip->setText(kodokanInfo.at(2).c_str());

}

CompanyInfoScreen::~CompanyInfoScreen()
{
    delete ui;
}

bool CompanyInfoScreen::eventFilter(QObject *obj, QEvent *event)
{
    if( obj == ui->nazwa && event->type() == QEvent::FocusIn)
    {
        ui->nazwa->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(200, 200, 200);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
        ui->nip->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
        ui->adres->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
        keyboard->activate(2, ui->nazwa, ui->zatwierdzZmiany);
        keyboard->show();
        keyboard->activateWindow();
    }
    else if( obj == ui->nip && event->type() == QEvent::FocusIn)
    {
        ui->nip->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(200, 200, 200);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
        ui->nazwa->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
        ui->adres->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
        keyboard->activate(1, ui->nip, ui->zatwierdzZmiany);
        keyboard->show();
        keyboard->activateWindow();
    }
    else if( obj == ui->adres && event->type() == QEvent::FocusIn)
    {
        ui->adres->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(200, 200, 200);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
        ui->nazwa->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
        ui->nip->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
        keyboard->activate(2, ui->adres, ui->zatwierdzZmiany);
        keyboard->show();
        keyboard->activateWindow();
    }
    return false;
}

void CompanyInfoScreen::mousePressEvent(QMouseEvent *event)
{
    ui->nazwa->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
    ui->adres->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
    ui->nip->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 30pt \"Tahoma\";border-style: solid;border-width:4px;border-radius:30px;");
    ui->nazwaLabel->setFocus();
    keyboard->hide();
}

void CompanyInfoScreen::on_powrot_clicked()
{
    this->close();
}

void CompanyInfoScreen::on_zatwierdzZmiany_clicked()
{
    kodokanDAO->update_kodokan_info(this->ui->nazwa->text().toStdString(),
                                    this->ui->adres->text().toStdString(),
                                    this->ui->nip->text().toStdString());
    this->close();

}
