#include "BuyingPassScreen.h"
#include "ui_BuyingPassScreen.h"
#include "QLineEdit"

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
