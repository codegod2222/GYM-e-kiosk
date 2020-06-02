#include "BuyingPassScreen.h"
#include "ui_BuyingPassScreen.h"
#include "QLineEdit"
#include "ConfirmPurchaseScreen.h"

BuyingPassScreen::BuyingPassScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BuyingPassScreen)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    ui->typyKarnetow->setEditable(true);
    ui->typyKarnetow->lineEdit()->setReadOnly(true);
    ui->typyKarnetow->lineEdit()->setAlignment(Qt::AlignCenter);

    ui->typyKarnetow->addItem("JEDNORAZOWE WEJŚCIE");
    ui->typyKarnetow->addItem("TYGODNIOWY");
    ui->typyKarnetow->addItem("DWUTYGODNIOWY");
    ui->typyKarnetow->addItem("MIESIĘCZNY");
    for (int i = 0 ; i <  ui->typyKarnetow->count() ; ++i)
    {
        ui->typyKarnetow->setItemData(i, Qt::AlignCenter, Qt::TextAlignmentRole);
    }
     ui->label->setFocus();
}

BuyingPassScreen::~BuyingPassScreen()
{
    delete ui;
}

void BuyingPassScreen::loop()
{
    while(1)
    {
        if(ui->typyKarnetow->hasFocus())
        {
            ui->typyKarnetow->showPopup();
            ui->label->setFocus();
        }
        qApp->processEvents();
    }
}

void BuyingPassScreen::on_powrot_clicked()
{
    this->close();
}

void BuyingPassScreen::on_gotowka_clicked()
{
    QString wybranyKarnet = ui->typyKarnetow->currentText();
    potwierdzZakup(wybranyKarnet, "GOTÓWKA");
}

void BuyingPassScreen::on_karta_clicked()
{
    QString wybranyKarnet = ui->typyKarnetow->currentText();
    potwierdzZakup(wybranyKarnet, "KARTA");
}

void BuyingPassScreen::on_online_clicked()
{

    QString wybranyKarnet = ui->typyKarnetow->currentText();
    potwierdzZakup(wybranyKarnet, "ONLINE");

}

void BuyingPassScreen::potwierdzZakup(QString wybranyKarnet, QString formaPlatnosci)
{
    ConfirmPurchaseScreen *confirmPurchaseScreen = new ConfirmPurchaseScreen;
    connect( this, SIGNAL(wyslijDaneDoPotwierdzenia(QString,QString,BuyingPassScreen*)), confirmPurchaseScreen, SLOT(odbierzDane(QString,QString,BuyingPassScreen*)));
    emit wyslijDaneDoPotwierdzenia(wybranyKarnet,formaPlatnosci,this);
    confirmPurchaseScreen->show();
    confirmPurchaseScreen->move(252,84);
}

void BuyingPassScreen::odbierzPotwierdzenie()
{
    //Tutaj jakieś rzeczy związane z zakupem, płatność, baza danych itd
    this->close();
}
