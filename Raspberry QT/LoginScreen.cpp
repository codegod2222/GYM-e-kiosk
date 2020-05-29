#include "LoginScreen.h"
#include "ui_LoginScreen.h"

LoginScreen::LoginScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginScreen)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

LoginScreen::~LoginScreen()
{
    delete ui;
}

void LoginScreen::on_pushButton_2_clicked()
{
    this->close();
}

void LoginScreen::on_pushButton_clicked()
{
    QString login = ui->login->text();
    QString password = ui->password->text();
}
