#ifndef CONFIRMPURCHASESCREEN_H
#define CONFIRMPURCHASESCREEN_H

#include <QDialog>
#include <../databse_access/KodokanDAO.h>

namespace Ui {
class ConfirmPurchaseScreen;
}

class ConfirmPurchaseScreen : public QDialog
{
    Q_OBJECT

public:
    explicit ConfirmPurchaseScreen(QWidget *parent = nullptr);
    ~ConfirmPurchaseScreen();

private slots:
    void on_potwierdz_clicked();

    void odbierzDane(SubscriptionType karnet, QString rodzajPlatnosci);

    void on_close_clicked();

signals:
    void wyslijPotwierdzenie();

private:
    Ui::ConfirmPurchaseScreen *ui;
};

#endif // CONFIRMPURCHASESCREEN_H
