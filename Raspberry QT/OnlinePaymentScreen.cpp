#include "OnlinePaymentScreen.h"
#include "ui_OnlinePaymentScreen.h"
#include "../online_payment/onlinePayment.cpp"

OnlinePaymentScreen::OnlinePaymentScreen(QWidget *parent, UserDAO *loggedUser, std::string desc, float price) :
    QDialog(parent),
    ui(new Ui::OnlinePaymentScreen)
{
    ui->setupUi(this);

    this->url = makeTransaction(price, desc, PKO, loggedUser->email, loggedUser->name);
    this->ui->adres->setText(url.c_str());
}

OnlinePaymentScreen::~OnlinePaymentScreen()
{
    delete ui;
}

void OnlinePaymentScreen::on_anuluj_clicked()
{
    this->close();
}

void OnlinePaymentScreen::on_zaplacono_clicked()
{
    std::string status = getTransactionStatus(this->url.substr(url.rfind("gtitle=") + 7));
    this->ui->status->setText(status.c_str());
}
