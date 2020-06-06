#include "RegistrationInfoScreen.h"
#include "ui_RegistrationInfoScreen.h"

RegistrationInfoScreen::RegistrationInfoScreen(QWidget *parent, QString information) :
    QDialog(parent),
    ui(new Ui::RegistrationInfoScreen)
{
    ui->setupUi(this);
    ui->information->setText(information);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

RegistrationInfoScreen::~RegistrationInfoScreen()
{
    delete ui;
}

void RegistrationInfoScreen::on_OK_clicked()
{
    this->close();
}
