#include "ConfirmPurchaseScreen.h"
#include "ui_ConfirmPurchaseScreen.h"

ConfirmPurchaseScreen::ConfirmPurchaseScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfirmPurchaseScreen)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    activateWindow();
}

ConfirmPurchaseScreen::~ConfirmPurchaseScreen()
{
    delete ui;
}

void ConfirmPurchaseScreen::odbierzDane(SubscriptionType karnet, QString platnosc)
{
    ui->typKarnetu->setText(karnet.name.c_str());
    ui->typFormy->setText(platnosc);
}

void ConfirmPurchaseScreen::on_potwierdz_clicked()
{
    emit wyslijPotwierdzenie();
    this->close();
}

void ConfirmPurchaseScreen::on_close_clicked()
{
    this->close();
}
