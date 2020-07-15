#include "RegistrationInfoScreen.h"
#include "ui_RegistrationInfoScreen.h"

RegistrationInfoScreen::RegistrationInfoScreen(QWidget *parent, QString information) :
    QDialog(parent),
    ui(new Ui::RegistrationInfoScreen)
{
    ui->setupUi(this);
    ui->information->setText(QString::fromUtf8(information.toStdString().c_str()));
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    //#8
    this->parent = parent;
}

RegistrationInfoScreen::~RegistrationInfoScreen()
{
    delete ui;
}

void RegistrationInfoScreen::on_OK_clicked()
{
    //#8
    if(parent != nullptr)
    {
        parent->close();
    }
    this->close();
}
