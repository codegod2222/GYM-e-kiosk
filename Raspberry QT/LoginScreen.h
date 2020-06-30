#ifndef LOGINSCREEN_H
#define LOGINSCREEN_H

#include <QDialog>
#include <Keyboard.h>
#include "dao.h"

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

    void mousePressEvent(QMouseEvent *event);

    bool eventFilter(QObject*, QEvent*);

private:
    Ui::LoginScreen *ui;
    Keyboard *keyboard;
    KodokanDAO *kodokanDAO;
public:
    static int ile;
};

#endif // LOGINSCREEN_H
