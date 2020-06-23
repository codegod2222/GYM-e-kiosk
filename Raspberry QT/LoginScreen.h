#ifndef LOGINSCREEN_H
#define LOGINSCREEN_H

#include <QDialog>
#include <Keyboard.h>

namespace Ui {
class LoginScreen;
}

class LoginScreen : public QDialog
{
    Q_OBJECT

public:
    explicit LoginScreen(QWidget *parent = nullptr);
    ~LoginScreen();

    void loop();

private slots:
    void on_powrot_clicked();

    void on_zaloguj_clicked();

    void mousePressEvent(QMouseEvent *event);

private:
    Ui::LoginScreen *ui;
    Keyboard *keyboard;
    bool closed = false;
public:
    static int ile;
};

#endif // LOGINSCREEN_H
