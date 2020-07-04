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


private slots:

    void on_powrot_clicked();

    void on_pushButton_clicked();

    void mousePressEvent(QMouseEvent*);

    bool eventFilter(QObject*, QEvent*);

    void on_dodajZdjecie_clicked();

private:
    Ui::RegistrationScreen *ui;
    RegistrationInfoScreen *registrationInfoScreen;
    Keyboard *keyboard;
    //KodokanDAO *kodokanDAO;
};

#endif // REGISTRATIONSCREEN_H
