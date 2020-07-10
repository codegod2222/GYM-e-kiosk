#include "PaymentThread.h"
#include "QDebug"
#include "mainwindow.h"

void PaymentThread::run()
{
        qDebug() << "Z paymentThread ";

        wiringPiSetupGpio();
        int result = pay(price);

        emit zaplacono(result);
}

