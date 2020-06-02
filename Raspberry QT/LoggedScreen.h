#ifndef LOGGEDSCREEN_H
#define LOGGEDSCREEN_H

#include <QDialog>
#include "LoginScreen.h"
#include "BuyingPassScreen.h"

namespace Ui {
class LoggedScreen;
}

class LoggedScreen : public QDialog
{
    Q_OBJECT

public:
    explicit LoggedScreen(QWidget *parent = nullptr, QString = "NULL", LoginScreen* = nullptr);
    ~LoggedScreen();

private slots:
    void on_wyloguj_clicked();

    void on_kupKarnet_clicked();

private:
    Ui::LoggedScreen *ui;
    QString loggedUser;
    LoginScreen *loginScreen;
    BuyingPassScreen *buyingPassScreen;
};

#endif // LOGGEDSCREEN_H
