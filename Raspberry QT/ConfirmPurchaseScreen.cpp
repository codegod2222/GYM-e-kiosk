#include "ConfirmPurchaseScreen.h"
#include "ui_ConfirmPurchaseScreen.h"
#include "BuyingPassScreen.h"

ConfirmPurchaseScreen::ConfirmPurchaseScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfirmPurchaseScreen)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

ConfirmPurchaseScreen::~ConfirmPurchaseScreen()
{
    delete ui;
}

void ConfirmPurchaseScreen::odbierzDane(QString karnet, QString platnosc, BuyingPassScreen* ekranKupowania)
{
    ui->typKarnetu->setText(karnet);
    ui->typFormy->setText(platnosc);
    buyingPassScreen = ekranKupowania;
}

void ConfirmPurchaseScreen::on_potwierdz_clicked()
{
    /*connect( this, SIGNAL(wyslijDaneDoPotwierdzenia(QString,QString,BuyingPassScreen*)), buyingPassScreen, SLOT(odbierzDane(QString,QString,BuyingPassScreen*)));
    emit wyslijPotwierdzenie(wybranyKarnet,"GOTÓWKA",this);
    confirmPurchaseScreen->show();*/
}

void ConfirmPurchaseScreen::on_anuluj_clicked()
{
    this->close();
}
