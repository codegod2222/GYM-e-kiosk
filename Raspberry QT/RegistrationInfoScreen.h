#ifndef REGISTRATIONINFOSCREEN_H
#define REGISTRATIONINFOSCREEN_H

#include <QDialog>

namespace Ui {
class RegistrationInfoScreen;
}

class RegistrationInfoScreen : public QDialog
{
    Q_OBJECT

public:
    explicit RegistrationInfoScreen(QWidget *parent = nullptr, QString information="");
    ~RegistrationInfoScreen();

private slots:
    void on_OK_clicked();

private:
    Ui::RegistrationInfoScreen *ui;
    //#8
    QWidget *parent = nullptr;
};

#endif // REGISTRATIONINFOSCREEN_H
