#include "printer.h"

#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include <utility>

using std::cout;
using std::endl;

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
    Printer::Align a = printer.align(); //kopia wyr¢wnania
    printer.align(Printer::Align::LEFT); //wyr¢wnanie do lewej
    char* white = new char[spaces+1];
    for (unsigned char i = 0; i < spaces; i++) {
        white[i] = ' ';
        white[static_cast<unsigned char>(spaces)] = '\0';
    }
    int ret = printer.print(left);
    ret += printer.print(white);
    ret += printer.println(right);
    printer.align(a); //przywr¢cenie wyr¢wnania
    return ret;
}

void example1(Printer& printer) {
    int nrRachunku = 0;
    std::string nazwaFirmy = "Nazwa firmy";
    std::string adresFirmy = "Miasto, ul. Ulica 0/0";
    std::string nip = "000-000-00-00";
    std::string imieNazwisko = "Imi© nazwisko";
    std::string dataWystawienia = "00-00-0000";
    std::string dataSprzedazy = "00-00-0000";
    std::string nazwaKarnetu = "karnetowy";
    unsigned int cena = 1234;
    std::string sposobZaplaty = "got¢wka";
    std::string terminZaplaty = "00-00-0000";
    unsigned int doZaplaty = 1234;
    std::string kwotaSlownie = "Dwana˜cie zˆotych i trzydzie˜ci cztery grosze";

    printer.init(); //inicjalizacja wydruku
    printer.codePage852(); //ustaw stron© kodow¥
    printer.align(Printer::Align::CENTER);
    printer.bold(true);
    printer.print("Rachunek nr ");
    printer.println(std::to_string(nrRachunku));
    printer.line(1);
    printer.println("Sprzedawca");
    printer.size(Printer::Size::DOUBLE_SIZE);
    printer.println(nazwaFirmy);
    printer.bold(false);
    printer.size(Printer::Size::NORMAL);
    printer.println(adresFirmy);
    printer.println(nip);
    printer.line(1);
    printer.bold(true);
    printer.println("Nabywca");
    printer.bold(false);
    printer.println(imieNazwisko);
    printer.line(1);
    printer.bold(true);
    printer.font(Printer::Font::B);
    printPair(printer, "Data wystawienia: ", dataWystawienia);
    printPair(printer ,"Data sprzeda¾y: ", dataSprzedazy);
    printer.font(Printer::Font::A);
    /*printer.font(Printer::Font::B);
    printPair(printer, "Data wystawienia", "Data sprzeda¾y");
    printer.font(Printer::Font::A);
    printer.bold(false);
    printPair(printer, dataWystawienia, dataSprzedazy);*/
    printer.line(1);
    printer.bold(true);
    printPair(printer, "Nazwa towaru/usˆugi", "Cena");
    printer.bold(false);
    printPair(printer, "Karnet " + nazwaKarnetu, std::to_string(cena/100)+','+std::to_string(cena%100)+" zˆ");
    printer.line(1);
    //printer.bold(true);
    printPair(printer, "Spos¢b zapˆaty:", sposobZaplaty);
    //printer.bold(false);
    printPair(printer, "Termin zapˆaty: ", terminZaplaty);
    printer.line(1);
    printer.bold(true);
    printPair(printer, "Do zapˆaty:", std::to_string(doZaplaty/100)+','+std::to_string(doZaplaty%100)+" zˆ");
    //printer.println("Do zapˆaty");
    //printer.println(std::to_string(doZaplaty/100)+','+std::to_string(doZaplaty%100)+" zˆ");
    printer.bold(false);
    printer.font(Printer::Font::B);
    printer.println("(sˆownie: " + kwotaSlownie + ")");
    printer.font(Printer::Font::A);
    printer.line(1);
    printer.bold(true);
    printPair(printer, "Zapˆacono", "Pozostaˆo do zapˆaty");
    printer.bold(false);
    printPair(printer, std::to_string(doZaplaty/100)+','+std::to_string(doZaplaty%100)+" zˆ", "0 zˆ");
    printer.endFeed(90);
}

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

void printReceipt(Printer& printer, ReceiptData& data) {
    printer.init(); //inicjalizacja wydruku
    printer.codePage852(); //ustaw stron© kodow¥
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
    if (data.rodzajPlatnosci == "Got¢wka") {
        printPair(printer, "Reszta got¢wka", makePrice(data.zaplacono-data.suma));
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

void example2(Printer& printer) {
    printer.init(); //inicjalizacja wydruku
    printer.codePage852(); //ustaw stron© kodow¥
    printer.println("Font A, Size NORMAL");
    printer.bold(true);
    printer.println("Font A, Size NORMAL, bold");
    printer.bold(false);
    printer.size(Printer::Size::DOUBLE_HEIGHT);
    printer.println("Font A, Size DOUBLE-HEIGHT");
    printer.bold(true);
    printer.println("Font A, Size DOUBLE-HEIGHT, bold");
    printer.bold(false);
    printer.size(Printer::Size::DOUBLE_WIDTH);
    printer.println("Font A, Size DW");
    printer.bold(true);
    printer.println("Font A, DW, bold");
    printer.bold(false);
    printer.size(Printer::Size::DOUBLE_SIZE);
    printer.println("Font A, Size DS");
    printer.bold(true);
    printer.println("Font A, DS, bold");
    printer.bold(false);

    printer.line(1);

    printer.size(Printer::Size::NORMAL);
    printer.font(Printer::Font::B);
    printer.println("Font B, Size NORMAL");
    printer.bold(true);
    printer.println("Font B, Size NORMAL, bold");
    printer.bold(false);
    printer.size(Printer::Size::DOUBLE_HEIGHT);
    printer.println("Font B, Size DOUBLE-HEIGHT");
    printer.bold(true);
    printer.println("Font B, Size DOUBLE-HEIGHT, bold");
    printer.bold(false);
    printer.size(Printer::Size::DOUBLE_WIDTH);
    printer.println("Font B, Size DW");
    printer.bold(true);
    printer.println("Font B, Size DW, bold");
    printer.bold(false);
    printer.size(Printer::Size::DOUBLE_SIZE);
    printer.println("Font B, Size DS");
    printer.bold(true);
    printer.println("Font B, Size DS, bold");
    printer.bold(false);
    printer.endFeed(90);
}

void example3(Printer& printer) {
    printer.init(); //inicjalizacja wydruku
    printer.codePage852(); //ustaw stron© kodow¥
    printer.println("Font A");
    printer.font(Printer::Font::B);
    printer.println("Font B");
    printer.font(Printer::Font::A);
    printer.align(Printer::Align::CENTER);
    printer.bold(true);
    printer.println("Bold");
    printer.bold(false);
    printer.underline(true);
    printer.println("Underline");
    printer.underline(false);
    printer.align(Printer::Align::RIGHT);
    printer.size(Printer::Size::DOUBLE_HEIGHT);
    printer.println("Double-Height");
    printer.size(Printer::Size::DOUBLE_SIZE);
    printer.println("Double-Size");
    printer.size(Printer::Size::DOUBLE_WIDTH);
    printer.println("Double-Width");
    printer.size(Printer::Size::NORMAL);
    printer.line(1);
    printPair(printer, "Lewo:", "Prawo");
    printer.font(Printer::Font::B);
    printPair(printer, "Lewo:", "Prawo");
    printer.size(Printer::Size::DOUBLE_WIDTH);
    printer.font(Printer::Font::A);
    printPair(printer, "Lewo:", "Prawo");
    printer.font(Printer::Font::B);
    printPair(printer, "Lewo:", "Prawo");
    printer.size(Printer::Size::NORMAL);
    printer.font(Printer::Font::A);
    printer.line(1);
    printer.align(Printer::Align::LEFT);
    printer.println("Za¾¢ˆ† g©si¥ ja«ä");
    printer.println("End of print");
    printer.endFeed(90);
}

int main() {
    ReceiptData data;
    data.nazwaFirmy = "Nazwa firmy";
    data.adres = "ul. Ulica 00\nMiasto 00-000";
    data.nip = "000-000-00-00";
    data.data = "0000-00-00";
    data.nrWyrduku = 0;
    data.listaKarnetow.push_back({ "Nazwa karnetu1", 1234 });
    data.listaKarnetow.push_back({ "Nazwa karnetu2", 3456 });
    data.nrDobowy = 0;
    data.nrDoby = 0;
    data.godzina = "00:00";
    data.rodzajPlatnosci = "Got¢wka";
    data.zaplacono = 5000;
    //data.rodzajPlatnosci = "Karta";
    //data.zaplacono = 4690;
    data.nabywca = "Imi© Nazwisko";

    Printer printer;
    printer.open(); //otwarcie poˆ¥czenia

    printReceipt(printer, data);

    printer.close(); //zamkni©cie poˆ¥czenia
    return 0;
}
