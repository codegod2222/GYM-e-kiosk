#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "LoginScreen.h"

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
    void on_pushButton_clicked();

    void on_kupKarnetButton_clicked();

    void on_zalogujSieButton_clicked();

    void on_zalozKontoButton_clicked(bool checked);

    void on_kupKarnetButton_clicked(bool checked);

    void on_zalozKontoButton_clicked();

    void openNewWindow();

private:
    Ui::MainWindow *ui;
    LoginScreen *loginScreen;
};
#endif // MAINWINDOW_H
