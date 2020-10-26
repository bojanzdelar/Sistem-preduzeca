#ifndef KOLEKCIJA_ODELJENJA_H
#define KOLEKCIJA_ODELJENJA_H

#include <sstream>

#include "../model/Odeljenje.h"
#include "TabelarnaKolekcija.h"

class KolekcijaOdeljenja : public TabelarnaKolekcija {
private:
    vector<Odeljenje*> odeljenja;

public:
    KolekcijaOdeljenja();
    KolekcijaOdeljenja(vector<Odeljenje*> odeljenja);
    virtual ~KolekcijaOdeljenja();

    vector<Odeljenje*> getOdeljenja();
    void setOdeljenja(vector<Odeljenje*> odeljenja);

    virtual int kolone();
    virtual int redovi();
    virtual string zaglavljeKolone(int kolona);
    virtual string zaglavljeRedova(int red);
    virtual string vrednostPolja(int kolona, int red);

    friend istream& operator>>(istream &input, KolekcijaOdeljenja &kolekcijaOdeljenja);
    friend ostream& operator<<(ostream &output, const KolekcijaOdeljenja &kolekcijaOdeljenja);
};

#endif // KOLEKCIJA_ODELJENJA_H