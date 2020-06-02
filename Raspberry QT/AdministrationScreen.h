#ifndef ADMINISTRATIONSCREEN_H
#define ADMINISTRATIONSCREEN_H

#include <QDialog>

namespace Ui {
class AdministrationScreen;
}

class AdministrationScreen : public QDialog
{
    Q_OBJECT

public:
    explicit AdministrationScreen(QWidget *parent = nullptr);
    ~AdministrationScreen();

private slots:
    void on_wyjscie_clicked();

private:
    Ui::AdministrationScreen *ui;
};

#endif // ADMINISTRATIONSCREEN_H
