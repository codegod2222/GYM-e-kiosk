#include <curl/curl.h>
#include <string>
#include <sstream>
#include "md5.h"
#include "json.hpp"

//metody płatności
enum PAYMENT_METHOD {
    KARTA_PLATNICZA = 103,
    ALIOR_BANK = 113,
    BANK_PEKAO = 102,
    PKO = 108,
    INTELIGO = 110,
    BLIK = 150,
    M_BANK = 160,
    ING = 111,
    BANK_MILLENNIUM = 114,
    SANTANDER = 115,
    CITIBANK = 132,
    CREDIT_AGRICOLE = 116,
    GETIN_BANK = 119,
    T_MOBILE = 112,
    BANK_POCZTOWY = 124,
    IDEA_BANK = 128,
    BANK_SPOL = 135,
    BANK_GOSP = 133,
    NEO_BANK = 159,
    NEST_BANK = 130,
    PLUS_BANK = 145,
    GOOGLE_PAY = 166,
    MASTER_PASS = 104,
    PAY_PAL = 106,
    ALIOR_RATY = 109,
    EURO_PAYMENT = 148,
    DRUCZEK = 157,
    VISA = 163
};

struct MemoryStruct {
    char* memory;
    size_t size;
};

//obcinanie niepotrzebnych zer po przecinku
template <typename T>
std::string to_string_best(const T& t);

//potrzebne do odczytania wyniku wysłanego requesta
static size_t WriteMemoryCallback(void* contents, size_t size, size_t nmemb, void* userp);

//stworzenie transakcji
//_amount - kwota transakcji
//_description - za co transakcja (np. serek danio)
//_payment - sposób płatności (dostępne spodoby w enum PAYMENT_METHOD)
//_mail - adres e-mail klienta
//_name - imię i nazwsiko klienta
//
//zwraca: adres www do dokonania opłaty
std::string makeTransaction(float _amount, std::string _description, PAYMENT_METHOD _payment, std::string _mail, std::string _name);

//sprawdzenie statusu transakcji
//title - tytuł transakcji (dotępny w adresie www: np. jeżeli www, to - https://secure.tpay.com/?gtitle=TR-BRA-22PVFAX, to tytuł - TR-BRA-22PVFAX)
//
//zwraca - status transakcji (możliwe wrtości:
//								correct - wtedy można uznać, że płatność zrealizowana
//								paid
//								pending
//								error
//								chargeback)
std::string getTransactionStatus(std::string title);
