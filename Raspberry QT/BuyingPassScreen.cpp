#include "BuyingPassScreen.h"
#include "ui_BuyingPassScreen.h"
#include "QLineEdit"
#include "ConfirmPurchaseScreen.h"

BuyingPassScreen::BuyingPassScreen(QWidget *parent, bool logged) :
    QDialog(parent),
    ui(new Ui::BuyingPassScreen)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    ui->typyKarnetow->setEditable(true);
    ui->typyKarnetow->lineEdit()->setReadOnly(true);
    ui->typyKarnetow->lineEdit()->setAlignment(Qt::AlignCenter);
    this->ui->typyKarnetow->installEventFilter(this);

    if(logged)
    {
        ui->typyKarnetow->addItem("TYGODNIOWY");
        ui->typyKarnetow->addItem("DWUTYGODNIOWY");
        ui->typyKarnetow->addItem("MIESIĘCZNY");
    }
    ui->typyKarnetow->addItem("JEDNORAZOWE WEJŚCIE");

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

bool BuyingPassScreen::eventFilter(QObject *obj, QEvent *event)
{
    if( obj == ui->typyKarnetow && event->type() == QEvent::FocusIn)
    {
        ui->typyKarnetow->showPopup();
        ui->label->setFocus();
    }
    return false;
}

void BuyingPassScreen::on_powrot_clicked()
{
    this->close();
}

void BuyingPassScreen::on_gotowka_clicked()
{
    wybranyKarnet = ui->typyKarnetow->currentText();
    wybranaPlatnosc = "GOTÓWKA";
    potwierdzZakup(wybranyKarnet, wybranaPlatnosc);
}

void BuyingPassScreen::on_karta_clicked()
{
    wybranyKarnet = ui->typyKarnetow->currentText();
    wybranaPlatnosc = "KARTA";
    potwierdzZakup(wybranyKarnet, wybranaPlatnosc);
}

void BuyingPassScreen::on_online_clicked()
{

    wybranyKarnet = ui->typyKarnetow->currentText();
    wybranaPlatnosc = "ONLINE";
    potwierdzZakup(wybranyKarnet, wybranaPlatnosc);

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
