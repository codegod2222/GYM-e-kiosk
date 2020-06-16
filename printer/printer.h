#ifndef PRINTER_H
#define PRINTER_H

#include <iostream> //FILE*

class Printer {
public:
    enum class Align : char { LEFT = 0, CENTER = 1, RIGHT = 2 };
    enum class Font  : char { A = 0, B = 1 };
    enum class Size  : char { NORMAL = 0, DOUBLE_HEIGHT = 1, DOUBLE_WIDTH = 16, DOUBLE_SIZE = 17 };

    const static char lineWidthA = 32;
    const static char lineWidthB = 42;
private:
    FILE* printer; //printer connection
    Align _align; //tryb justowania tekstu
    Font _font; //czcionka
    bool _bold; //pogrubienie
    bool _underline; //podkreślenie
    Size _size; //rozmiar czcionki
public:
    //otwiera połączenie z drukarką
    bool open();
    //inicjalizuje wydruk
    int init();
    //ustawia stronę kodową CP852
    int codePage852();
    //drukuje 'text'
    int print(const std::string& text);
    int print(const char* text);
    //drukuje 'text' zakończony znakiem nowej linii
    int println(const std::string& text);
    int println(const char* text);
    //wypisuje 'n' pustych linii
    int line(unsigned char n);
    //końcowy odstęp 'n' jednostek
    int endFeed(unsigned char n);
    //zamyka połączenie z drukarką
    bool close();
    //zwraca tryb wyrównania tekstu
    Align align() const;
    //ustawia tryb wyrównania tekstu
    int align(Align);
    //zwraca aktualną czcionkę
    Font font() const;
    //ustawia czcionkę
    int font(Font);
    //zwraca czy aktywne jest pogrubienie tekstu
    bool bold() const;
    //ustawia pogrubienie tekstu
    int bold(bool);
    //zwraca czy aktywne jest podkreślenie tekstu
    bool underline() const;
    //ustawia podkreślenie tekstu
    int underline(bool);
    //zwraca aktualny rozmiar czcionki
    Size size() const;
    //ustawia rozmiar czcionki
    int size(Size);
};

#endif // PRINTER_H
