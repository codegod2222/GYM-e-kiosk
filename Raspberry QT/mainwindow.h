#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "LoginScreen.h"
#include "LoggedScreen.h"
#include "RegistrationScreen.h"
#include "BuyingPassScreen.h"
#include "AdministrationScreen.h"
#include "LoopThread.h"

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

    void on_administracja_clicked();

    bool eventFilter(QObject*, QEvent*);

    void przylozonoKarte(QString);

private:
    Ui::MainWindow *ui;
    LoginScreen *loginScreen = nullptr;
    RegistrationScreen *registrationScreen = nullptr;
    BuyingPassScreen *buyingPassScreen = nullptr;
    AdministrationScreen *administrationScreen = nullptr;
    LoopThread *loopThread;
    bool threadRun;
    //KodokanDAO *kodokanDAO;
};
#endif // MAINWINDOW_H
