#include "ConfirmPurchaseScreen.h"
#include "ui_ConfirmPurchaseScreen.h"
#include "BuyingPassScreen.h"

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

void ConfirmPurchaseScreen::odbierzDane(SubscriptionType karnet, QString platnosc, BuyingPassScreen* ekranKupowania)
{
    ui->typKarnetu->setText(karnet.name.c_str());
    ui->typFormy->setText(platnosc);
    buyingPassScreen = ekranKupowania;
}

void ConfirmPurchaseScreen::on_potwierdz_clicked()
{
    connect( this, SIGNAL(wyslijPotwierdzenie()), buyingPassScreen, SLOT(odbierzPotwierdzenie()));
    emit wyslijPotwierdzenie();
    this->close();
}

void ConfirmPurchaseScreen::on_close_clicked()
{
    this->close();
}
