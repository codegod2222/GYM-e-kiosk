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
    Printer::Align a = printer.align(); //kopia wyrównania
    printer.align(Printer::Align::LEFT); //wyrównanie do lewej
    char* white = new char[spaces+1];
    for (char i = 0; i < spaces; i++) {
        white[i] = ' ';
        white[spaces] = '\0';
    }
    int ret = printer.print(left);
    ret += printer.print(white);
    ret += printer.println(right);
    printer.align(a); //przywrócenie wyrównania
    return ret;
}

int example1(Printer& printer) {
    int nrRachunku = 0;
    std::string nazwaFirmy = "Nazwa firmy";
    std::string adresFirmy = "Miasto, ul. Ulica 0/0";
    std::string nip = "000-000-00-00";
    std::string imieNazwisko = "Imię nazwisko";
    std::string dataWystawienia = "00-00-0000";
    std::string dataSprzedazy = "00-00-0000";
    std::string nazwaKarnetu = "karnetowy";
    unsigned int cena = 1234;
    std::string sposobZaplaty = "gotówka";
    std::string terminZaplaty = "00-00-0000";
    unsigned int doZaplaty = 1234;
    std::string kwotaSlownie = "Dwanaście złotych i trzydzieści cztery grosze";

    printer.init(); //inicjalizacja wydruku
    printer.codePage852(); //ustaw stronę kodową
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
    printer.printPair("Data wystawienia: ", dataWystawienia);
    printer.printPair("Data sprzedaży: ", dataSprzedazy);
    printer.font(Printer::Font::A);
    /*printer.font(Printer::Font::B);
    printer.printPair("Data wystawienia", "Data sprzedaży");
    printer.font(Printer::Font::A);
    printer.bold(false);
    printer.printPair(dataWystawienia, dataSprzedazy);*/
    printer.line(1);
    printer.bold(true);
    printer.printPair("Nazwa towaru/usługi", "Cena");
    printer.bold(false);
    printer.printPair("Karnet " + nazwaKarnetu, std::to_string(cena/100)+','+std::to_string(cena%100)+" zł");
    printer.line(1);
    //printer.bold(true);
    printer.printPair("Sposób zapłaty:", sposobZaplaty);
    //printer.bold(false);
    printer.printPair("Termin zapłaty: ", terminZaplaty);
    printer.line(1);
    printer.bold(true);
    printer.printPair("Do zapłaty:", std::to_string(doZaplaty/100)+','+std::to_string(doZaplaty%100)+" zł");
    //printer.println("Do zapłaty");
    //printer.println(std::to_string(doZaplaty/100)+','+std::to_string(doZaplaty%100)+" zł");
    printer.bold(false);
    printer.font(Printer::Font::B);
    printer.println("(słownie: " + kwotaSlownie + ")");
    printer.font(Printer::Font::A);
    printer.line(1);
    printer.bold(true);
    printer.printPair("Zapłacono", "Pozostało do zapłaty");
    printer.bold(false);
    printer.printPair(std::to_string(doZaplaty/100)+','+std::to_string(doZaplaty%100)+" zł", "0 zł");
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

int printReceipt(Printer& printer, ReceiptData& data) {
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

int example2(Printer& printer) {
    printer.init(); //inicjalizacja wydruku
    printer.codePage852(); //ustaw stronę kodową
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

int example3(Printer& printer) {
    printer.init(); //inicjalizacja wydruku
    printer.codePage852(); //ustaw stronę kodową
    printer.println("Font A");
    printer.font(Printer::FONT::B);
    printer.println("Font B");
    printer.font(Printer::FONT::A);
    printer.align(Printer::ALIGN::CENTER);
    printer.bold(true);
    printer.println("Bold");
    printer.bold(false);
    printer.underline(true);
    printer.println("Underline");
    printer.underline(false);
    printer.align(Printer::ALIGN::RIGHT);
    printer.size(Printer::SIZE::DOUBLE_HEIGHT);
    printer.println("Double-Height");
    printer.size(Printer::SIZE::DOUBLE_SIZE);
    printer.println("Double-Size");
    printer.size(Printer::SIZE::DOUBLE_WIDTH);
    printer.println("Double-Width");
    printer.size(Printer::SIZE::NORMAL);
    printer.line(1);
    printer.printPair("Lewo:", "Prawo");
    printer.font(Printer::FONT::B);
    printer.printPair("Lewo:", "Prawo");
    printer.size(Printer::SIZE::DOUBLE_WIDTH);
    printer.font(Printer::FONT::A);
    printer.printPair("Lewo:", "Prawo");
    printer.font(Printer::FONT::B);
    printer.printPair("Lewo:", "Prawo");
    printer.size(Printer::SIZE::NORMAL);
    printer.font(Printer::FONT::A);
    printer.line(1);
    printer.align(Printer::ALIGN::LEFT);
    printer.println("Zażółć gęsią jaźń");
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
    data.rodzajPlatnosci = "Gotówka";
    data.zaplacono = 5000;
    //data.rodzajPlatnosci = "Karta";
    //data.zaplacono = 4690;
    data.nabywca = "Imię Nazwisko";

    Printer printer;
    printer.open(); //otwarcie połączenia

    printReceipt(printer, data);

    printer.close(); //zamknięcie połączenia
    return 0;
}
