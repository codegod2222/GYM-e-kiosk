#ifndef PASS_H
#define PASS_H

#include <string>

class Pass
{
public:
    Pass(std::string nazwa, int cena, int ileDni);
    std::string nazwa;
    int cena;
    int ileDni;
};

#endif // PASS_H
