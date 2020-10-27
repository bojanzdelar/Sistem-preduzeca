#ifndef KOLEKCIJA_ODELJENJA_H
#define KOLEKCIJA_ODELJENJA_H

#include "../model/Odeljenje.h"
#include "../model/Preduzece.h"
#include "TabelarnaKolekcija.hpp"

class KolekcijaOdeljenja : public TabelarnaKolekcija<Odeljenje*> {
public:
    KolekcijaOdeljenja();
    KolekcijaOdeljenja(vector<Odeljenje*> kolekcija);
    virtual ~KolekcijaOdeljenja();

    virtual int kolone() const;
    virtual string zaglavljeKolone(int kolona) const;
    virtual string vrednostPolja(int kolona, int red) const;

    friend istream& operator>>(istream &input, KolekcijaOdeljenja &kolekcijaOdeljenja);
    friend ostream& operator<<(ostream &output, const KolekcijaOdeljenja &kolekcijaOdeljenja);
};

#endif // KOLEKCIJA_ODELJENJA_H