#ifndef ONLINEPAYMENTSCREEN_H
#define ONLINEPAYMENTSCREEN_H

#include <QDialog>
#include "../databse_access/UserDAO.h"


namespace Ui {
class OnlinePaymentScreen;
}

class OnlinePaymentScreen : public QDialog
{
    Q_OBJECT

public:
    explicit OnlinePaymentScreen(QWidget *parent = nullptr, UserDAO *loggedUser = nullptr, std::string desc = "", float price = 0.0);
    ~OnlinePaymentScreen();

private slots:

    void on_anuluj_clicked();

    void on_zaplacono_clicked();

signals:
    void drukuj();

private:
    Ui::OnlinePaymentScreen *ui;
    std::string url;


};

#endif // ONLINEPAYMENTSCREEN_H
