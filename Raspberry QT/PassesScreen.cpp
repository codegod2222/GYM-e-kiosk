#include "PassesScreen.h"
#include "ui_PassesScreen.h"
#include <QHeaderView>

PassesScreen::PassesScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PassesScreen)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    karnety = new std::vector<Pass>;
    Pass new1("tygodniowy", 50, 7);
    Pass new2("miesieczny", 100, 30);
    Pass new3("dwumiesieczny", 150, 60);
    karnety->push_back(new1);
    karnety->push_back(new2);
    karnety->push_back(new3);

    this->ui->listaKarnetow->setColumnCount(3);
    this->ui->listaKarnetow->setColumnWidth(0,400);
    this->ui->listaKarnetow->setColumnWidth(1,300);
    this->ui->listaKarnetow->setColumnWidth(2,200);
    QStringList listaKarnetowHeader;
    listaKarnetowHeader<<"Nazwa"<<"Waznosc (dni)"<<"Cena";
    this->ui->listaKarnetow->setHorizontalHeaderLabels(listaKarnetowHeader);
    this->ui->listaKarnetow->horizontalHeader()->setHighlightSections(false);
    this->ui->listaKarnetow->verticalHeader()->setHighlightSections(false);
    //Wyłączam edytowanie tablicy
    this->ui->listaKarnetow->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->ui->listaKarnetow->setSelectionBehavior(QAbstractItemView::SelectRows);
    this->ui->listaKarnetow->setShowGrid(false);

    this->installEventFilter(this);
}

PassesScreen::~PassesScreen()
{
    delete ui;
}

void PassesScreen::on_powrot_clicked()
{
    this->close();
}

void PassesScreen::on_dodajKarnet_clicked()
{
    if(addOrEditPassScreen == nullptr)
    {
        addOrEditPassScreen = new AddOrEditPassScreen(this,nullptr,karnety);
    }
    else
    {
        delete addOrEditPassScreen;
        addOrEditPassScreen = new AddOrEditPassScreen(this,nullptr,karnety);
    }
    addOrEditPassScreen->move(0,0);
    addOrEditPassScreen->show();
}

void PassesScreen::refreshTable()
{
    this->ui->listaKarnetow->setRowCount(karnety->size());
    int i = 0;
    for (auto karnet : *karnety)
    {
        this->ui->listaKarnetow->setItem(i , 0 , new QTableWidgetItem(QString(karnet.nazwa.c_str())));
        this->ui->listaKarnetow->setItem(i , 1 , new QTableWidgetItem(QString::number(karnet.ileDni)));
        this->ui->listaKarnetow->setItem(i , 2 , new QTableWidgetItem(QString::number(karnet.cena)));
        i++;
    }
}

bool PassesScreen::eventFilter(QObject *obj, QEvent *event)
{
    if(event->type() == QEvent::WindowActivate)
    {
        refreshTable();
    }
    return false;
}

void PassesScreen::on_usunKarnet_clicked()
{
    int toDeleteIndex = this->ui->listaKarnetow->currentRow();
    karnety->erase(karnety->begin()+toDeleteIndex);
    refreshTable();
}

void PassesScreen::on_edytujKarnet_clicked()
{
    int toEditIndex = this->ui->listaKarnetow->currentRow();
    if(addOrEditPassScreen == nullptr)
    {
        addOrEditPassScreen = new AddOrEditPassScreen(this, &karnety->at(toEditIndex) , karnety);
    }
    else
    {
        delete addOrEditPassScreen;
        addOrEditPassScreen = new AddOrEditPassScreen(this , &karnety->at(toEditIndex) , karnety);
    }
    addOrEditPassScreen->move(0,0);
    addOrEditPassScreen->show();
}
