#include "AdministrationScreen.h"
#include "ui_AdministrationScreen.h"

AdministrationScreen::AdministrationScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdministrationScreen)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

AdministrationScreen::~AdministrationScreen()
{
    delete ui;
}

void AdministrationScreen::on_wyjscie_clicked()
{
    this->close();
}

void AdministrationScreen::on_dane_firmy_clicked()
{
    if(companyInfoScreen == nullptr)
    {
        companyInfoScreen = new CompanyInfoScreen();
        companyInfoScreen->move(0,0);
        companyInfoScreen->show();
    }
    else
    {
        companyInfoScreen->move(0,0);
        companyInfoScreen->show();
    }
}

void AdministrationScreen::on_karnety_clicked()
{
    if(passesScreen == nullptr)
    {
        passesScreen = new PassesScreen();
        passesScreen->move(0,0);
        passesScreen->show();
    }
    else
    {
        passesScreen->move(0,0);
        passesScreen->show();
    }
}

void AdministrationScreen::on_czlonkowie_clicked()
{
    if(clubMembersScreen == nullptr)
    {
        clubMembersScreen = new ClubMembersScreen();
        clubMembersScreen->move(0,0);
        clubMembersScreen->show();
    }
    else
    {
        clubMembersScreen->move(0,0);
        clubMembersScreen->show();
    }
}
