#ifndef REGISTRATIONSCREEN_H
#define REGISTRATIONSCREEN_H

#include <QDialog>
#include "RegistrationInfoScreen.h"

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

    void on_nazwisko_editingFinished();

    void on_haslo_editingFinished();

    void on_pushButton_clicked();

private:
    Ui::RegistrationScreen *ui;
    RegistrationInfoScreen *registrationInfoScreen;

};

#endif // REGISTRATIONSCREEN_H
