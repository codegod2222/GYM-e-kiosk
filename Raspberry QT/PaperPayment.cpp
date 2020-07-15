#include "PaperPayment.h"
#include "ui_PaperPayment.h"
#include <stdio.h>


PaperPayment::PaperPayment(QWidget *parent, int price) :
    QDialog(parent),
    ui(new Ui::PaperPayment)
{
    ui->setupUi(this);
    this->ui->kwota->setText(QString::number(price));
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    this->threadRun=true;

    switch(price){
    case 10:
        price = TEN;
        break;
    case 20:
        price = TWENTY;
        break;
    case 50:
        price = FIFTY;
        break;
    case 100:
        price = HUNDRET;
        break;

    }

    paymentThread = new PaymentThread(threadRun, price);
    connect( paymentThread, SIGNAL(zaplacono(int)), this, SLOT(zaplacono(int)));
    qDebug() << "Start watek";
    paymentThread->start();
}

PaperPayment::~PaperPayment()
{
    delete ui;
}

void PaperPayment::zaplacono(int result)
{
    if(result)
    {
        this->ui->info->setText(QString::fromUtf8("PŁATNOŚĆ PRAWDIŁOWA"));
        this->ui->anuluj->setText("OK");
        emit drukuj();
        //#15
        this->close();
    }
    else
    {
        this->ui->info->setText(QString::fromUtf8("PŁATNOŚĆ NIEPRAWDIŁOWA"));
    }
}

void PaperPayment::on_anuluj_clicked()
{
    this->threadRun = false;
    this->close();
}
