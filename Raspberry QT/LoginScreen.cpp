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
