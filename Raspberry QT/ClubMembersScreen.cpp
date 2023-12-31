#include "ClubMembersScreen.h"
#include "ui_ClubMembersScreen.h"

ClubMembersScreen::ClubMembersScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClubMembersScreen)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

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

    kodokanDAO = kodokanDAO->getInstance();
}

ClubMembersScreen::~ClubMembersScreen()
{
    delete ui;
}

void ClubMembersScreen::on_dodajCzlonka_clicked()
{
    if(addOrEditClubMember == nullptr)
    {
        addOrEditClubMember = new AddOrEditClubMember(this,nullptr);
    }
    else
    {
        delete addOrEditClubMember;
        addOrEditClubMember = new AddOrEditClubMember(this,nullptr);
    }
    addOrEditClubMember->move(0,0);
    addOrEditClubMember->show();
}

void ClubMembersScreen::on_usunCzlonka_clicked()
{
    int toDeleteIndex = this->ui->listaCzlonkow->currentRow();
    std::string temp = ui->listaCzlonkow->takeItem(toDeleteIndex,2)->text().toStdString();

    UserDAO *toEdit = nullptr;

    std::vector<UserDAO> users = kodokanDAO->get_users();
    for (auto user : users)
    {
        if(user.email.compare(temp) == 0)
        {
            user.delete_user();
        }
    }

    refreshTable();
}

void ClubMembersScreen::on_edytujCzlonka_clicked()
{

    int toEditIndex = this->ui->listaCzlonkow->currentRow();

    std::string temp = ui->listaCzlonkow->takeItem(toEditIndex,2)->text().toStdString();

    UserDAO *toEdit = nullptr;

    std::vector<UserDAO> users = kodokanDAO->get_users();
    for (auto user : users)
    {
        if(user.email.compare(temp) == 0)
        {
            toEdit = new UserDAO(user);
            break;
        }
    }


    //tutaj jakies pobranie z bazy na podstawie emaila bym widzial,
    //lub pobiorę hasło na zasadzie vector.at(toDeleteIndex)
    if(addOrEditClubMember == nullptr)
    {
        addOrEditClubMember = new AddOrEditClubMember(this, toEdit);
    }
    else
    {
        delete addOrEditClubMember;
        addOrEditClubMember = new AddOrEditClubMember(this , toEdit);
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
    std::vector<UserDAO> users = kodokanDAO->get_users();
    this->ui->listaCzlonkow->setRowCount(users.size());
    int i = 0;
    for (auto czlonek : users)
    {
        this->ui->listaCzlonkow->setItem(i , 0 , new QTableWidgetItem(QString(czlonek.name.c_str())));
        this->ui->listaCzlonkow->setItem(i , 1 , new QTableWidgetItem(QString(czlonek.surname.c_str())));
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
