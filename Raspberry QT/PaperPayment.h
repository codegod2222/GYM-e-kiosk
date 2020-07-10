#ifndef PAPERPAYMENT_H
#define PAPERPAYMENT_H

#include <QDialog>
#include "RegistrationInfoScreen.h"
#include "../banknote_acceptor/acceptor_test.h"
#include "PaymentThread.h"

namespace Ui {
class PaperPayment;
}

class PaperPayment : public QDialog
{
    Q_OBJECT

public:
    explicit PaperPayment(QWidget *parent = nullptr, int price = 0);
    ~PaperPayment();

    void payment();

private slots:
    void on_anuluj_clicked();
    void zaplacono(int);

signals:
    void drukuj();

private:
    Ui::PaperPayment *ui;
    RegistrationInfoScreen * registrationInfoScreen = nullptr;
    PaymentThread *paymentThread = nullptr;
    bool threadRun;
};

#endif // PAPERPAYMENT_H
