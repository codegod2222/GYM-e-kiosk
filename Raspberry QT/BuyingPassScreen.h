#ifndef BUYINGPASSSCREEN_H
#define BUYINGPASSSCREEN_H

#include <QDialog>
#include "OnlinePaymentScreen.h"
#include "PaperPayment.h"
#include "../databse_access/UserDAO.h"
#include "../databse_access/KodokanDAO.h"

namespace Ui {
class BuyingPassScreen;
}

class BuyingPassScreen : public QDialog
{
    Q_OBJECT

public:
    explicit BuyingPassScreen(QWidget *parent = nullptr, UserDAO *loggedUser = nullptr);
    ~BuyingPassScreen();

    bool eventFilter(QObject*, QEvent*);

    void mousePressEvent(QMouseEvent*);

private slots:
    void on_powrot_clicked();

    void on_gotowka_clicked();

    void on_karta_clicked();

    void on_online_clicked();

    void potwierdzZakup(SubscriptionType, QString);

    void odbierzPotwierdzenie();

    void drukuj2();
signals:
    void wyslijDaneDoPotwierdzenia(SubscriptionType karnet, QString rodzajPlatnosci, BuyingPassScreen*);

private:
    Ui::BuyingPassScreen *ui;
    OnlinePaymentScreen *onlinePaymentScreen = nullptr;
    PaperPayment *paperPaymentScreen = nullptr;
    UserDAO *loggedUser = nullptr;
    KodokanDAO *kodokanDAO;
    bool popupHidden = true;
    SubscriptionType wybranyKarnet;
    QString wybranaPlatnosc;
};

#endif // BUYINGPASSSCREEN_H
