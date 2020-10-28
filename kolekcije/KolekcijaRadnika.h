#ifndef KOLEKCIJA_RADNIKA_H
#define KOLEKCIJA_RADNIKA_H

#include "../model/Radnik.h"
#include "../model/Racunovodja.h"
#include "../model/Revizor.h"
#include "../model/Komercijalista.h"
#include "../model/Odeljenje.h"
#include "TabelarnaKolekcija.hpp"

class KolekcijaRadnika : public TabelarnaKolekcija<Radnik*> {
public:
    KolekcijaRadnika();
    KolekcijaRadnika(vector<Radnik*> radnici);
    virtual ~KolekcijaRadnika();

    virtual int kolone() const;
    virtual string zaglavljeKolone(int kolona) const;
    virtual string vrednostPolja(int kolona, int red) const;
    Radnik* dobaviId(string id) const;
    bool idZauzet(string id) const;

    friend istream& operator>>(istream &input, KolekcijaRadnika &kolekcijaRadnika);
    friend ostream& operator<<(ostream &output, const KolekcijaRadnika &kolekcijaRadnika);
};

#endif // KOLEKCIJA_RADNIKA_H