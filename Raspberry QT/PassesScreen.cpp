#include "PassesScreen.h"
#include "ui_PassesScreen.h"
#include <QHeaderView>

PassesScreen::PassesScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PassesScreen)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

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

    kodokanDAO = kodokanDAO->getInstance();
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
        addOrEditPassScreen = new AddOrEditPassScreen(this,nullptr);
    }
    else
    {
        delete addOrEditPassScreen;
        addOrEditPassScreen = new AddOrEditPassScreen(this,nullptr);
    }
    addOrEditPassScreen->move(0,0);
    addOrEditPassScreen->show();
}

void PassesScreen::refreshTable()
{
    std::vector<SubscriptionType> karnety = kodokanDAO->get_subscription_types();
    this->ui->listaKarnetow->setRowCount(karnety.size());
    int i = 0;
    for (auto karnet : karnety)
    {
        this->ui->listaKarnetow->setItem(i , 0 , new QTableWidgetItem(QString(karnet.name.c_str())));
        this->ui->listaKarnetow->setItem(i , 1 , new QTableWidgetItem(QString::number(karnet.length)));
        this->ui->listaKarnetow->setItem(i , 2 , new QTableWidgetItem(QString::number(karnet.price)));
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
    std::string temp = ui->listaKarnetow->takeItem(toDeleteIndex,0)->text().toStdString();

    std::vector<SubscriptionType> karnety = kodokanDAO->get_subscription_types();
    for (auto karnet : karnety)
    {
        if(karnet.name.compare(temp) == 0)
        {
            kodokanDAO->delete_subscription_type(karnet.id);
        }
    }

    refreshTable();
}

void PassesScreen::on_edytujKarnet_clicked()
{
    int toEditIndex = this->ui->listaKarnetow->currentRow();
    std::string temp = ui->listaKarnetow->takeItem(toEditIndex,0)->text().toStdString();

    SubscriptionType toEdit;

    std::vector<SubscriptionType> karnety = kodokanDAO->get_subscription_types();
    for (auto karnet : karnety)
    {
        if(karnet.name.compare(temp) == 0)
        {
            toEdit = karnet;
        }
    }


    if(addOrEditPassScreen == nullptr)
    {
        addOrEditPassScreen = new AddOrEditPassScreen(this, &toEdit);
    }
    else
    {
        delete addOrEditPassScreen;
        addOrEditPassScreen = new AddOrEditPassScreen(this , &toEdit);
    }
    addOrEditPassScreen->move(0,0);
    addOrEditPassScreen->show();
}
