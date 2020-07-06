#ifndef PASSWORDCHANGESCREEN_H
#define PASSWORDCHANGESCREEN_H

#include <QDialog>
#include <RegistrationInfoScreen.h>
#include <Keyboard.h>
#include "../databse_access/UserDAO.h"

namespace Ui {
class PasswordChangeScreen;
}

//zeby dzialalo na windzie
class UserDAO;

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
    UserDAO *loggedUser;
    RegistrationInfoScreen *infoScreen;
    Keyboard *keyboard;
};

#endif // PASSWORDCHANGESCREEN_H
