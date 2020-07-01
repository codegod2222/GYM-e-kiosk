#ifndef CLUBMEMBER_H
#define CLUBMEMBER_H

#include <string>

using namespace std;

class ClubMember
{
public:
    ClubMember(string imie, string nazwisko, string email, string haslo);

    string imie;
    string nazwisko;
    string email;
    string haslo;

};

#endif // CLUBMEMBER_H
