#ifndef LOGINSCREEN_H
#define LOGINSCREEN_H

#include <QDialog>

namespace Ui {
class LoginScreen;
}

class LoginScreen : public QDialog
{
    Q_OBJECT

public:
    explicit LoginScreen(QWidget *parent = nullptr);
    ~LoginScreen();

private slots:
    void on_powrot_clicked();

    void on_zaloguj_clicked();

private:
    Ui::LoginScreen *ui;
};

#endif // LOGINSCREEN_H
