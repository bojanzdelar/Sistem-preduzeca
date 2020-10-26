#ifndef TABELARNA_KOLEKCIJA_H
#define TABELARNA_KOLEKCIJA_H

#include <string>

using namespace std;

class TabelarnaKolekcija {
public:
    virtual int kolone() const = 0;
    virtual int redovi() const = 0;
    virtual string zaglavljeKolone(int kolona) const = 0;
    virtual string zaglavljeRedova(int red) const = 0;
    virtual string vrednostPolja(int kolona, int red) const = 0;
};

#endif // TABELARNA_KOLEKCIJA_H