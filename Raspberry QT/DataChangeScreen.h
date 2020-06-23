#ifndef DATACHANGESCREEN_H
#define DATACHANGESCREEN_H

#include <QDialog>
#include "LoggedUser.h"
#include "LoggedScreen.h"
#include "PasswordChangeScreen.h"
#include <Keyboard.h>

namespace Ui {
class DataChangeScreen;
}

class DataChangeScreen : public QDialog
{
    Q_OBJECT

public:
    explicit DataChangeScreen(QWidget *parent = nullptr, LoggedUser* = nullptr, LoggedScreen* = nullptr);
    ~DataChangeScreen();

    void loop();

private slots:
    void on_powrot_clicked();

    void on_zatwierdzZmiany_clicked();

    void on_zmienHaslo_clicked();

    void mousePressEvent(QMouseEvent*);

signals:
    void wyslijZmianeDanych();

private:
    Ui::DataChangeScreen *ui;
    LoggedUser *loggedUser;
    LoggedScreen *loggedScreen;
    PasswordChangeScreen *passwordChangeScreen;
    Keyboard *keyboard;
};

#endif // DATACHANGESCREEN_H
