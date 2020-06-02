#include "AdministrationScreen.h"
#include "ui_AdministrationScreen.h"

AdministrationScreen::AdministrationScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdministrationScreen)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

AdministrationScreen::~AdministrationScreen()
{
    delete ui;
}

void AdministrationScreen::on_wyjscie_clicked()
{
    this->close();
}
