#ifndef PASSWORDCHANGESCREEN_H
#define PASSWORDCHANGESCREEN_H

#include <QDialog>
#include <LoggedUser.h>
#include <RegistrationInfoScreen.h>
#include <Keyboard.h>
#include "dao.h"

namespace Ui {
class PasswordChangeScreen;
}

class PasswordChangeScreen : public QDialog
{
    Q_OBJECT

public:
    explicit PasswordChangeScreen(QWidget *parent = nullptr, UserDAO *loggedUser = nullptr);
    ~PasswordChangeScreen();

    bool eventFilter(QObject*, QEvent*);


private slots:
    void on_close_clicked();

    void on_potwierdz_clicked();   

    void mousePressEvent(QMouseEvent*);

private:
    Ui::PasswordChangeScreen *ui;
    LoggedUser *loggedUser;
    RegistrationInfoScreen *infoScreen;
    Keyboard *keyboard;
};

#endif // PASSWORDCHANGESCREEN_H
