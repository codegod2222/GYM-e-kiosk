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
    case 1000:
        price = TEN;
        break;
    case 2000:
        price = TWENTY;
        break;
    case 5000:
        price = FIFTY;
        break;
    case 10000:
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
        this->ui->info->setText("PATNO— PRAWDIOWA");
        this->ui->anuluj->setText("OK");
        emit drukuj();
        //#15
        this->close();
    }
    else
    {
        this->ui->info->setText("PATNO— NIEPRAWDIOWA");
    }
}

void PaperPayment::on_anuluj_clicked()
{
    this->threadRun = false;
    this->close();
}
