#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "LoginScreen.h"
#include "RegistrationScreen.h"
#include "BuyingPassScreen.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_kupKarnetButton_clicked();

    void on_zalogujSieButton_clicked();

    void on_zalozKontoButton_clicked();

private:
    Ui::MainWindow *ui;
    LoginScreen *loginScreen;
    RegistrationScreen *registrationScreen;
    BuyingPassScreen *buyingPassScreen;
};
#endif // MAINWINDOW_H
