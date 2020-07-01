#ifndef ADMINISTRATIONSCREEN_H
#define ADMINISTRATIONSCREEN_H

#include <QDialog>
//#include "dao.h"
#include "CompanyInfoScreen.h"
#include "PassesScreen.h"

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

    void on_dane_firmy_clicked();

    void on_karnety_clicked();

private:
    Ui::AdministrationScreen *ui;
    //KodokanDAO *kodokanDAO;
    CompanyInfoScreen *companyInfoScreen = nullptr;
    PassesScreen *passesScreen = nullptr;
};

#endif // ADMINISTRATIONSCREEN_H
