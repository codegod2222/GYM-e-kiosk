#include "BuyingPassScreen.h"
#include "ui_BuyingPassScreen.h"
#include "QLineEdit"
#include "ConfirmPurchaseScreen.h"
#include "printer.h"
#include <sstream>
#include <QDebug>
#include <ctime>

#pragma region Printer
#define PrinterStart {

struct ReceiptData {
    std::string nazwaFirmy;
    std::string adres;
    std::string nip;
    std::string data;
    unsigned int nrWyrduku;
    std::list<std::pair<std::string, unsigned int>> listaKarnetow;
    unsigned int suma = 0;
    unsigned int nrDobowy;
    unsigned int nrDoby;
    std::string godzina;
    std::string rodzajPlatnosci;
    unsigned int zaplacono;
    std::string nabywca;
};

std::string makePrice(unsigned int price) {
    std::stringstream ss;
    ss.width(3);
    ss << price/100;
    ss << ',';
    ss.width(2);
    ss.fill('0');
    ss << price%100;
    return ss.str();
}

std::string toInt(unsigned int val, unsigned int width) {
    std::stringstream ss;
    ss.width(width);
    ss.fill('0');
    ss << val;
    return ss.str();
}

int printPair(Printer& printer, const std::string& left, const std::string& right) {
    int lineWidth;
    if (printer.font() == Printer::Font::A)
        lineWidth = Printer::lineWidthA;
    else
        lineWidth = Printer::lineWidthB;
    if (printer.size() == Printer::Size::DOUBLE_WIDTH || printer.size() == Printer::Size::DOUBLE_SIZE)
        lineWidth >>= 1;
    char spaces = lineWidth - left.size() - right.size();
    if (spaces < 0) {
        return -1;
    }
    else if (spaces == 0) {
        int ret = printer.print(left);
        ret += printer.println(right);
        return ret;
    }
    Printer::Align a = printer.align(); //kopia wyrównania
    printer.align(Printer::Align::LEFT); //wyrównanie do lewej
    char* white = new char[spaces+1];
    for (unsigned char i = 0; i < spaces; i++) {
        white[i] = ' ';
        white[static_cast<unsigned char>(spaces)] = '\0';
    }
    int ret = printer.print(left);
    ret += printer.print(white);
    ret += printer.println(right);
    printer.align(a); //przywrócenie wyrównania
    return ret;
}

void printReceipt(Printer& printer, ReceiptData& data) {
    printer.init(); //inicjalizacja wydruku
    printer.codePage852(); //ustaw stronę kodową
    printer.align(Printer::Align::CENTER);
    printer.size(Printer::Size::DOUBLE_SIZE);
    printer.println(data.nazwaFirmy);
    printer.size(Printer::Size::NORMAL);
    printer.println(data.adres);
    printer.println("NIP: " + data.nip);
    printer.print(data.data + "             ");
    printer.font(Printer::Font::B);
    printer.println(" wydr." + toInt(data.nrWyrduku, 6));
    printer.font(Printer::Font::B);
    printer.size(Printer::Size::DOUBLE_SIZE);
    printer.println("POTWIERDZENIE");
    printer.size(Printer::Size::NORMAL);
    printer.font(Printer::Font::A);
    for (auto k : data.listaKarnetow) {
        printPair(printer, std::get<0>(k), makePrice(std::get<1>(k)));
        data.suma += std::get<1>(k);
    }
    printer.font(Printer::Font::B);
    printer.size(Printer::Size::DOUBLE_SIZE);
    printer.print("SUMA PLN: ");
    printer.size(Printer::Size::DOUBLE_HEIGHT);
    printer.font(Printer::Font::A);
    printer.print("        ");
    printer.font(Printer::Font::B);
    printer.size(Printer::Size::DOUBLE_SIZE);
    printer.println(makePrice(data.suma));

    printer.size(Printer::Size::NORMAL);
    printer.font(Printer::Font::A);
    printPair(printer, data.rodzajPlatnosci, makePrice(data.zaplacono));
    if (data.nabywca != "")
        printPair(printer, "Nabywca", data.nabywca);
    printer.font(Printer::Font::B);
    printer.align(Printer::Align::RIGHT);
    printer.println(data.godzina);
    printer.endFeed(90);
}

#define PrinterEnd }
#pragma endregion Printer

BuyingPassScreen::BuyingPassScreen(QWidget *parent, UserDAO *loggedUser) :
    QDialog(parent),
    ui(new Ui::BuyingPassScreen)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    ui->typyKarnetow->setEditable(true);
    ui->typyKarnetow->lineEdit()->setReadOnly(true);
    ui->typyKarnetow->lineEdit()->setAlignment(Qt::AlignCenter);
    this->ui->typyKarnetow->installEventFilter(this);

    this->loggedUser = loggedUser;

    kodokanDAO = kodokanDAO->getInstance();

    std::vector<SubscriptionType> karnety = kodokanDAO->get_subscription_types();
    for (auto karnet : karnety)
    {
        std::string temp = karnet.name;
        if(loggedUser != nullptr || temp.compare("Jednorazowy") == 0)
        {
            //#10
            int price = karnet.price / 100;
            temp += " " + std::to_string(price);
            ui->typyKarnetow->addItem(temp.c_str());
        }
    }


    for (int i = 0 ; i <  ui->typyKarnetow->count() ; ++i)
    {
        ui->typyKarnetow->setItemData(i, Qt::AlignCenter, Qt::TextAlignmentRole);
    }
    ui->label->setFocus();



}

BuyingPassScreen::~BuyingPassScreen()
{
    delete ui;
}

bool BuyingPassScreen::eventFilter(QObject *obj, QEvent *event)
{
    /*if( obj == ui->typyKarnetow && event->type() == QEvent::FocusIn)
    {
        if(this->popupHidden == true)
        {
            ui->typyKarnetow->showPopup();
            this->popupHidden = false;
        }
        //ui->label->setFocus();

    }
    else if (obj != ui->typyKarnetow)
    {
        ui->typyKarnetow->hidePopup();
        ui->label->setFocus();
    }*/

    //#13
    if(event->type() == QEvent::WindowActivate)
    {
        if(paperPaymentScreen != nullptr)
            delete paperPaymentScreen;
        if(onlinePaymentScreen != nullptr)
            delete onlinePaymentScreen;
    }
    return false;
}

void BuyingPassScreen::mousePressEvent(QMouseEvent *event)
{
    /*if(this->popupHidden == false)
    {
        ui->typyKarnetow->hidePopup();
        ui->label->setFocus();
        this->popupHidden = true;
    }*/
}


void BuyingPassScreen::on_powrot_clicked()
{
    this->close();
}

void BuyingPassScreen::on_gotowka_clicked()
{
    std::string wybranyKarnetString = ui->typyKarnetow->currentText().toStdString();
    wybranyKarnetString = wybranyKarnetString.substr(0, wybranyKarnetString.find(' '));
    std::vector<SubscriptionType> subs = kodokanDAO->get_subscription_types();
    for(auto sub : subs)
    {
        if(sub.name.compare(wybranyKarnetString) == 0)
            wybranyKarnet = sub;
    }
    wybranaPlatnosc = "GOTOWKA";
    potwierdzZakup(wybranyKarnet, wybranaPlatnosc);
}

void BuyingPassScreen::on_karta_clicked()
{
    std::string wybranyKarnetString = ui->typyKarnetow->currentText().toStdString();
    wybranyKarnetString = wybranyKarnetString.substr(0, wybranyKarnetString.find(' '));
    std::vector<SubscriptionType> subs = kodokanDAO->get_subscription_types();
    for(auto sub : subs)
    {
        if(sub.name.compare(wybranyKarnetString) == 0)
            wybranyKarnet = sub;
    }
    wybranaPlatnosc = "KARTA";
    potwierdzZakup(wybranyKarnet, wybranaPlatnosc);
}

void BuyingPassScreen::on_online_clicked()
{
    std::string wybranyKarnetString = ui->typyKarnetow->currentText().toStdString();
    wybranyKarnetString = wybranyKarnetString.substr(0, wybranyKarnetString.find(' '));
    std::vector<SubscriptionType> subs = kodokanDAO->get_subscription_types();
    for(auto sub : subs)
    {
        if(sub.name.compare(wybranyKarnetString) == 0)
            wybranyKarnet = sub;
    }
    wybranaPlatnosc = "ONLINE";
    potwierdzZakup(wybranyKarnet, wybranaPlatnosc);
}

void BuyingPassScreen::potwierdzZakup(SubscriptionType wybranyKarnet, QString formaPlatnosci)
{
    if(confirmPurchaseScreen == nullptr)
        confirmPurchaseScreen = new ConfirmPurchaseScreen();
    connect( confirmPurchaseScreen, SIGNAL(wyslijPotwierdzenie()), this, SLOT(odbierzPotwierdzenie()));
    connect( this, SIGNAL(wyslijDaneDoPotwierdzenia(SubscriptionType,QString)), confirmPurchaseScreen, SLOT(odbierzDane(SubscriptionType,QString)));
    emit wyslijDaneDoPotwierdzenia(wybranyKarnet,formaPlatnosci);
    confirmPurchaseScreen->show();
    confirmPurchaseScreen->move(252,84);
}

void BuyingPassScreen::odbierzPotwierdzenie()
{
    //#13
    if(paperPaymentScreen != nullptr)
        delete paperPaymentScreen;
    if(onlinePaymentScreen != nullptr)
        delete onlinePaymentScreen;

    if(wybranaPlatnosc.compare("ONLINE") == 0)
    {
        if(onlinePaymentScreen == nullptr)
        {
            if(loggedUser == nullptr)
            {
                loggedUser = new UserDAO("email@frytki.pl", "Gosc");
            }
            //#14
            int price = wybranyKarnet.price / 100;
            onlinePaymentScreen = new OnlinePaymentScreen(this, loggedUser, wybranyKarnet.name, price);
            connect(onlinePaymentScreen, SIGNAL(drukuj()), this, SLOT(drukuj2()));
            onlinePaymentScreen->move(0,0);
            onlinePaymentScreen->exec();

        }
    }
    else if(wybranaPlatnosc.compare("GOTOWKA") == 0)
    {
        if(paperPaymentScreen == nullptr)
        {
            //#12
            int price = wybranyKarnet.price / 100;
            paperPaymentScreen = new PaperPayment(this, price);
            connect(paperPaymentScreen, SIGNAL(drukuj()), this, SLOT(drukuj2()));
            paperPaymentScreen->move(0,0);
            paperPaymentScreen->exec();
        }
    }

    if(onlinePaymentScreen != nullptr)
        while(onlinePaymentScreen->isActiveWindow()){}
    else if(paperPaymentScreen != nullptr)
        while(paperPaymentScreen->isActiveWindow()){}
}

void BuyingPassScreen::drukuj2()
{
    std::vector<std::string> kodokanInfo = kodokanDAO->get_kodokan_info();

    ReceiptData data;
    data.nazwaFirmy = kodokanInfo.at(0);
    data.adres = kodokanInfo.at(1);
    data.nip = kodokanInfo.at(2);
    time_t unixtime = time(nullptr);
    tm* date = localtime(&unixtime);
    data.data = std::to_string(date->tm_year + 1900) + '-' + (date->tm_mon < 9 ? ('0' + std::to_string(date->tm_mon + 1)) : std::to_string(date->tm_mon + 1)) + '-' + std::to_string(date->tm_mday);
    data.nrWyrduku = kodokanDAO->get_receipt_number();
    data.listaKarnetow.push_back({ wybranyKarnet.name , wybranyKarnet.price });
    data.godzina = std::to_string(date->tm_hour) + ':' + std::to_string(date->tm_min);
    data.rodzajPlatnosci = wybranaPlatnosc.toStdString();
    data.zaplacono = wybranyKarnet.price;
    if (loggedUser == nullptr)
        data.nabywca = "";
    else
        data.nabywca = loggedUser->name + ' ' + loggedUser->surname;

    Printer printer;
    printer.open(); //otwarcie połączenia

    printReceipt(printer, data);

    printer.close(); //zamknięcie połączenia

    this->close();
}
