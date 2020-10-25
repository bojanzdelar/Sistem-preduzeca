#ifndef TABELARNA_KOLEKCIJA_H
#define TABELARNA_KOLEKCIJA_H

#include <string>

using namespace std;

class TabelarnaKolekcija {
    virtual int kolone() = 0;
    virtual int redovi() = 0;
    virtual string zaglavljeKolone(int kolona) = 0;
    virtual string zaglavljeRedova(int red) = 0;
    virtual string vrednostPolja(int kolona, int red) = 0;
};

#endif // TABELARNA_KOLEKCIJA_H