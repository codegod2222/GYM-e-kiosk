#ifndef LOGGEDSCREEN_H
#define LOGGEDSCREEN_H

#include <QDialog>
#include "LoginScreen.h"
#include "BuyingPassScreen.h"
#include "dao.h"

class DataChangeScreen;

namespace Ui {
class LoggedScreen;
}

class LoggedScreen : public QDialog
{
    Q_OBJECT

public:
    explicit LoggedScreen(QWidget *parent = nullptr, UserDAO *loggedUser = nullptr);
    ~LoggedScreen();

private slots:
    void on_wyloguj_clicked();

    void on_kupKarnet_clicked();

    void on_zmienDane_clicked();

     void odbierzZmianeDanych();

private:
    Ui::LoggedScreen *ui;
    BuyingPassScreen *buyingPassScreen;
    UserDAO *loggedUser;
    DataChangeScreen *dataChangeScreen = nullptr;
};

#endif // LOGGEDSCREEN_H
