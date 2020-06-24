#ifndef PASSWORDCHANGESCREEN_H
#define PASSWORDCHANGESCREEN_H

#include <QDialog>
#include <LoggedUser.h>
#include <RegistrationInfoScreen.h>
#include <Keyboard.h>

namespace Ui {
class PasswordChangeScreen;
}

class PasswordChangeScreen : public QDialog
{
    Q_OBJECT

public:
    explicit PasswordChangeScreen(QWidget *parent = nullptr, LoggedUser *loggedUser = nullptr);
    ~PasswordChangeScreen();

    void loop();


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
