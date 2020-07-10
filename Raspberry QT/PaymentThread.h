#ifndef PAYMENTTHREAD_H
#define PAYMENTTHREAD_H
#include <QtCore>
#include "../banknote_acceptor/acceptor_test.h"

class PaymentThread : public QThread
{
    Q_OBJECT
public:
    void run();
    PaymentThread(bool& _runn, int price) : runn(_runn), price(price) {}

private:
    bool& runn;
    int price;

signals:
    void zaplacono(int);

};

#endif // PAYMENTTHREAD_H


