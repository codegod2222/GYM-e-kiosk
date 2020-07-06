#ifndef PAPERPAYMENT_H
#define PAPERPAYMENT_H

#include <QDialog>
#include "RegistrationInfoScreen.h"

namespace Ui {
class PaperPayment;
}

class PaperPayment : public QDialog
{
    Q_OBJECT

public:
    explicit PaperPayment(QWidget *parent = nullptr, int price = 0);
    ~PaperPayment();

private:
    Ui::PaperPayment *ui;
    RegistrationInfoScreen * registrationInfoScreen = nullptr;
};

#endif // PAPERPAYMENT_H
