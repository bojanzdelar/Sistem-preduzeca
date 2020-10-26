#ifndef KOLEKCIJA_ODELJENJA_H
#define KOLEKCIJA_ODELJENJA_H

#include <sstream>

#include "../model/Odeljenje.h"
#include "../model/Preduzece.h"
#include "TabelarnaKolekcija.h"

class KolekcijaOdeljenja : public TabelarnaKolekcija {
private:
    vector<Odeljenje*> odeljenja;

public:
    KolekcijaOdeljenja();
    KolekcijaOdeljenja(vector<Odeljenje*> odeljenja);
    virtual ~KolekcijaOdeljenja();

    vector<Odeljenje*> getOdeljenja() const;
    void setOdeljenja(vector<Odeljenje*> odeljenja);

    virtual int kolone() const;
    virtual int redovi() const;
    virtual string zaglavljeKolone(int kolona) const;
    virtual string zaglavljeRedova(int red) const;
    virtual string vrednostPolja(int kolona, int red) const;

    friend istream& operator>>(istream &input, KolekcijaOdeljenja &kolekcijaOdeljenja);
    friend ostream& operator<<(ostream &output, const KolekcijaOdeljenja &kolekcijaOdeljenja);
};

#endif // KOLEKCIJA_ODELJENJA_H