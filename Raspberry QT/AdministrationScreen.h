#ifndef ADMINISTRATIONSCREEN_H
#define ADMINISTRATIONSCREEN_H

#include <QDialog>
//#include "dao.h"
#include "CompanyInfoScreen.h"
#include "PassesScreen.h"
#include "ClubMembersScreen.h"

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

    void on_czlonkowie_clicked();

private:
    Ui::AdministrationScreen *ui;
    CompanyInfoScreen *companyInfoScreen = nullptr;
    PassesScreen *passesScreen = nullptr;
    ClubMembersScreen *clubMembersScreen = nullptr;
};

#endif // ADMINISTRATIONSCREEN_H
