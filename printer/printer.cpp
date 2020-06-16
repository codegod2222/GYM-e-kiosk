#include "printer.h"
#include <iostream> //debug

//otwiera połączenie z drukarką
bool Printer::open() {
#ifdef __linux__
    printer = popen("/usr/bin/lp", "w");
#elif _WIN32
    printer = fopen("prnt", "wb");
#else
    #error "UNKNOWN OS"
#endif
    printer = printer;
    if (!printer) //kontrola poprawności
        return false;
    else
        return true;
}
//inicjalizuje wydruk
int Printer::init() {
    return fprintf(printer, "\e@");
}
//ustawia stronę kodową CP852
int Printer::codePage852() {
    return fprintf(printer, "\et%c", 18);
}
//drukuje 'text'
int Printer::print(const std::string& text) {
    return print(text.c_str());
}
int Printer::print(const char* text) {
    return fprintf(printer, "%s", text);
}
//drukuje 'text' zakończony znakiem nowej linii
int Printer::println(const std::string& text) {
    return println(text.c_str());
}
int Printer::println(const char* text) {
    return fprintf(printer, "%s\n", text);
}
//wypisuje 'n' pustych linii
int Printer::line(unsigned char n) {
    return fprintf(printer, "\ed%c", n);
}
//końcowy odstęp 'n' jednostek
int Printer::endFeed(unsigned char n) {
    return fprintf(printer, "\eJ%c", n);
}
//zamyka połączenie z drukarką
bool Printer::close() {
#ifdef __linux__
    return !pclose(printer);
#elif _WIN32
    return !fclose(printer);
#else
    #error "UNKNOWN OS"
#endif
}

//zwraca tryb wyrównania tekstu
Printer::Align Printer::align() const {
    return _align;
}
//ustawia tryb wyrównania tekstu
int Printer::align(Printer::Align val) {
    if (_align == val)
        return 0;
    _align = val;
    return fprintf(printer, "\ea%c", (char)val);
}

//zwraca aktualną czcionkę
Printer::Font Printer::font() const {
    return _font;
}
//ustawia czcionkę
int Printer::font(Font val) {
    if (_font == val) {
        return 0;
    }
    else {
        _font = val;
        return fprintf(printer, "\eM%c", (char)val);
    }
}

//zwraca czy aktywne jest pogrubienie tekstu
bool Printer::bold() const {
    return _bold;
}
//ustawia pogrubienie tekstu
int Printer::bold(bool val) {
    if (_bold == val) {
        return 0;
    }
    else {
        _bold = val;
        return fprintf(printer, "\eE%c", (char)val);
    }
}
//zwraca czy aktywne jest podkreślenie tekstu
bool Printer::underline() const {
    return _underline;
}
//ustawia podkreślenie tekstu
int Printer::underline(bool val) {
    if (_underline == val) {
        return 0;
    }
    else {
        _underline = val;
        return fprintf(printer, "\e-%c", val);
    }
}
//zwraca aktualny rozmiar czcionki
Printer::Size Printer::size() const {
    return _size;
}
//ustawia rozmiar czcionki
int Printer::size(Size val) {
    if (_size == val) {
        return 0;
    }
    else {
        _size = val;
        return fprintf(printer, "\x1d!%c", (char)val);
    }
}
