#include "ClubMembersScreen.h"
#include "ui_ClubMembersScreen.h"

ClubMembersScreen::ClubMembersScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClubMembersScreen)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    czlonkowie = new std::vector<ClubMember>;
    ClubMember new1("Daniel", "Kaleta", "danielkalelta@gmail.com", "tajne");
    ClubMember new2("Piotr", "Uhl", "piotruhl@gmail.com", "rownieztajne");
    ClubMember new3("Piotr", "Bosowski", "piotrbosowski@gmail.com", "nieznane");
    czlonkowie->push_back(new1);
    czlonkowie->push_back(new2);
    czlonkowie->push_back(new3);

    this->ui->listaCzlonkow->setColumnCount(3);
    this->ui->listaCzlonkow->setColumnWidth(0,250);
    this->ui->listaCzlonkow->setColumnWidth(1,250);
    this->ui->listaCzlonkow->setColumnWidth(2,500);
    QStringList listaKarnetowHeader;
    listaKarnetowHeader<<"Imie"<<"Nazwisko"<<"Email";
    this->ui->listaCzlonkow->setHorizontalHeaderLabels(listaKarnetowHeader);
    this->ui->listaCzlonkow->horizontalHeader()->setHighlightSections(false);
    this->ui->listaCzlonkow->verticalHeader()->setHighlightSections(false);
    //Wyłączam edytowanie tablicy
    this->ui->listaCzlonkow->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->ui->listaCzlonkow->setSelectionBehavior(QAbstractItemView::SelectRows);
    this->ui->listaCzlonkow->setShowGrid(false);

    this->installEventFilter(this);
}

ClubMembersScreen::~ClubMembersScreen()
{
    delete ui;
}

void ClubMembersScreen::on_dodajCzlonka_clicked()
{
    if(addOrEditClubMember == nullptr)
    {
        addOrEditClubMember = new AddOrEditClubMember(this,nullptr,czlonkowie);
    }
    else
    {
        delete addOrEditClubMember;
        addOrEditClubMember = new AddOrEditClubMember(this,nullptr,czlonkowie);
    }
    addOrEditClubMember->move(0,0);
    addOrEditClubMember->show();
}

void ClubMembersScreen::on_usunCzlonka_clicked()
{
    int toDeleteIndex = this->ui->listaCzlonkow->currentRow();
    QString email = this->ui->listaCzlonkow->takeItem(toDeleteIndex, 2)->text();
    //tutaj jakies pobranie z bazy na podstawie emaila bym widzial,
    //lub pobiorę hasło na zasadzie vector.at(toDeleteIndex)
    czlonkowie->erase(czlonkowie->begin()+toDeleteIndex);
    refreshTable();
}

void ClubMembersScreen::on_edytujCzlonka_clicked()
{
    int toEditIndex = this->ui->listaCzlonkow->currentRow();
    QString email = this->ui->listaCzlonkow->takeItem(toEditIndex, 2)->text();
    //tutaj jakies pobranie z bazy na podstawie emaila bym widzial,
    //lub pobiorę hasło na zasadzie vector.at(toDeleteIndex)
    if(addOrEditClubMember == nullptr)
    {
        addOrEditClubMember = new AddOrEditClubMember(this, &czlonkowie->at(toEditIndex) , czlonkowie);
    }
    else
    {
        delete addOrEditClubMember;
        addOrEditClubMember = new AddOrEditClubMember(this , &czlonkowie->at(toEditIndex) , czlonkowie);
    }
    addOrEditClubMember->move(0,0);
    addOrEditClubMember->show();
}

void ClubMembersScreen::on_powrot_clicked()
{
    this->close();
}

void ClubMembersScreen::refreshTable()
{
    this->ui->listaCzlonkow->setRowCount(czlonkowie->size());
    int i = 0;
    for (auto czlonek : *czlonkowie)
    {
        this->ui->listaCzlonkow->setItem(i , 0 , new QTableWidgetItem(QString(czlonek.imie.c_str())));
        this->ui->listaCzlonkow->setItem(i , 1 , new QTableWidgetItem(QString(czlonek.nazwisko.c_str())));
        this->ui->listaCzlonkow->setItem(i , 2 , new QTableWidgetItem(QString(czlonek.email.c_str())));
        i++;
    }
}

bool ClubMembersScreen::eventFilter(QObject *obj, QEvent *event)
{
    if(event->type() == QEvent::WindowActivate)
    {
        refreshTable();
    }
    return false;
}
