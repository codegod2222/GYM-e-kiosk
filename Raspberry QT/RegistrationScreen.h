#ifndef REGISTRATIONSCREEN_H
#define REGISTRATIONSCREEN_H

#include <QDialog>
#include "RegistrationInfoScreen.h"
#include <Keyboard.h>

namespace Ui {
class RegistrationScreen;
}

class RegistrationScreen : public QDialog
{
    Q_OBJECT

public:
    explicit RegistrationScreen(QWidget *parent = nullptr);
    ~RegistrationScreen();

    void loop();

private slots:

    void on_powrot_clicked();

    void on_pushButton_clicked();

    void mousePressEvent(QMouseEvent*);

private:
    Ui::RegistrationScreen *ui;
    RegistrationInfoScreen *registrationInfoScreen;
    Keyboard *keyboard;
    bool closed = false;
};

#endif // REGISTRATIONSCREEN_H
