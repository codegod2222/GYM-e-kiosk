#ifndef DATACHANGESCREEN_H
#define DATACHANGESCREEN_H

#include <QDialog>
#include "LoggedUser.h"
#include "LoggedScreen.h"

namespace Ui {
class DataChangeScreen;
}

class DataChangeScreen : public QDialog
{
    Q_OBJECT

public:
    explicit DataChangeScreen(QWidget *parent = nullptr, LoggedUser* = nullptr, LoggedScreen* = nullptr);
    ~DataChangeScreen();

private slots:
    void on_powrot_clicked();

    void on_zatwierdzZmiany_clicked();

signals:
    void wyslijZmianeDanych();

private:
    Ui::DataChangeScreen *ui;
    LoggedUser *loggedUser;
    LoggedScreen *loggedScreen;
};

#endif // DATACHANGESCREEN_H
