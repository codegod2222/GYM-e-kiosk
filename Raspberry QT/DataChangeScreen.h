#ifndef DATACHANGESCREEN_H
#define DATACHANGESCREEN_H

#include <QDialog>
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
    explicit DataChangeScreen(QWidget *parent = nullptr, UserDAO *loggedUser = nullptr, LoggedScreen* = nullptr);
    ~DataChangeScreen();

    bool eventFilter(QObject*, QEvent*);

private slots:
    void on_powrot_clicked();

    void on_zatwierdzZmiany_clicked();

    void on_zmienHaslo_clicked();

    void mousePressEvent(QMouseEvent*);

signals:
    void wyslijZmianeDanych();

private:
    Ui::DataChangeScreen *ui;
    UserDAO *loggedUser;
    LoggedScreen *loggedScreen;
    PasswordChangeScreen *passwordChangeScreen = nullptr;
    Keyboard *keyboard;
};

#endif // DATACHANGESCREEN_H
