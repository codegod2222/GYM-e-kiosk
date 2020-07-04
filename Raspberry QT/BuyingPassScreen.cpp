#include "BuyingPassScreen.h"
#include "ui_BuyingPassScreen.h"
#include "QLineEdit"
#include "ConfirmPurchaseScreen.h"
#include "printer.h"
#include <sstream>

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
    if (data.rodzajPlatnosci == "Gotówka") {
        printPair(printer, "Reszta gotówka", makePrice(data.zaplacono-data.suma));
    }
    printPair(printer, "Nabywca", data.nabywca);
    printer.font(Printer::Font::B);
    printer.print(toInt(data.nrDobowy, 5) + '/' + toInt(data.nrDoby, 4) + ' ');
    printer.font(Printer::Font::A);
    printer.print("                    ");
    printer.font(Printer::Font::B);
    printer.println(data.godzina);
    printer.endFeed(90);
}

BuyingPassScreen::BuyingPassScreen(QWidget *parent, bool logged) :
    QDialog(parent),
    ui(new Ui::BuyingPassScreen)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    ui->typyKarnetow->setEditable(true);
    ui->typyKarnetow->lineEdit()->setReadOnly(true);
    ui->typyKarnetow->lineEdit()->setAlignment(Qt::AlignCenter);
    this->ui->typyKarnetow->installEventFilter(this);

    if(logged)
    {
        ui->typyKarnetow->addItem("TYGODNIOWY");
        ui->typyKarnetow->addItem("DWUTYGODNIOWY");
        ui->typyKarnetow->addItem("MIESIECZNY");
    }
    ui->typyKarnetow->addItem("JEDNORAZOWE WEJSCIE");

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
    if( obj == ui->typyKarnetow && event->type() == QEvent::FocusIn)
    {
        ui->typyKarnetow->showPopup();
        ui->label->setFocus();
    }
    else if (obj != ui->typyKarnetow)
    {
        ui->typyKarnetow->hidePopup();
        ui->label->setFocus();
    }
    return false;
}

void BuyingPassScreen::mousePressEvent(QMouseEvent *event)
{
    ui->typyKarnetow->hidePopup();
    ui->label->setFocus();
}


void BuyingPassScreen::on_powrot_clicked()
{
    this->close();
}

void BuyingPassScreen::on_gotowka_clicked()
{
    wybranyKarnet = ui->typyKarnetow->currentText();
    wybranaPlatnosc = "GOTOWKA";
    potwierdzZakup(wybranyKarnet, wybranaPlatnosc);
}

void BuyingPassScreen::on_karta_clicked()
{
    wybranyKarnet = ui->typyKarnetow->currentText();
    wybranaPlatnosc = "KARTA";
    potwierdzZakup(wybranyKarnet, wybranaPlatnosc);
}

void BuyingPassScreen::on_online_clicked()
{

    wybranyKarnet = ui->typyKarnetow->currentText();
    wybranaPlatnosc = "ONLINE";
    potwierdzZakup(wybranyKarnet, wybranaPlatnosc);

}

void BuyingPassScreen::potwierdzZakup(QString wybranyKarnet, QString formaPlatnosci)
{
    ConfirmPurchaseScreen *confirmPurchaseScreen = new ConfirmPurchaseScreen;
    connect( this, SIGNAL(wyslijDaneDoPotwierdzenia(QString,QString,BuyingPassScreen*)), confirmPurchaseScreen, SLOT(odbierzDane(QString,QString,BuyingPassScreen*)));
    emit wyslijDaneDoPotwierdzenia(wybranyKarnet,formaPlatnosci,this);
    confirmPurchaseScreen->show();
    confirmPurchaseScreen->move(252,84);
}

void BuyingPassScreen::odbierzPotwierdzenie()
{
    /*
    std::vector<std::string> kodokanInfo = kodokanDAO.get_kodokan_info();
    data.nazwaFirmy = kodokanInfo.at(0);
    data.adres = kodokanInfo.at(1);
    data.nip = kodokanInfo.at(2);
    */
    //Tutaj jakieś rzeczy związane z zakupem, płatność, baza danych itd
    ReceiptData data;
    data.nazwaFirmy = "Nazwa firmy";
    data.adres = "ul. Ulica 00\nMiasto 00-000";
    data.nip = "000-000-00-00";
    data.data = "0000-00-00";
    data.nrWyrduku = 0;
    data.listaKarnetow.push_back({ wybranyKarnet.toStdString() , 1234 });
    data.listaKarnetow.push_back({ "Nazwa karnetu2", 3456 });
    data.nrDobowy = 0;
    data.nrDoby = 0;
    data.godzina = "00:00";
    data.rodzajPlatnosci = "Gotówka";
    data.zaplacono = 5000;
    //data.rodzajPlatnosci = "Karta";
    //data.zaplacono = 4690;
    data.nabywca = "Imię Nazwisko";

    Printer printer;
    printer.open(); //otwarcie połączenia

    printReceipt(printer, data);

    printer.close(); //zamknięcie połączenia
    this->close();
}

