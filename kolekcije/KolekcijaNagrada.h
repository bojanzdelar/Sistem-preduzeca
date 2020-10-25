#ifndef KOLEKCIJA_NAGRADA_H
#define KOLEKCIJA_NAGRADA_H

#include <vector>
#include <sstream>

#include "../model/Nagrada.h"
#include "TabelarnaKolekcija.h"

class KolekcijaNagrada : public TabelarnaKolekcija {
private:
    vector<Nagrada*> nagrade;

public:
    KolekcijaNagrada();
    KolekcijaNagrada(vector<Nagrada*> nagrade);
    virtual ~KolekcijaNagrada();

    vector<Nagrada*> getNagrade();
    void setNagrade(vector<Nagrada*> nagrade);

    virtual int kolone();
    virtual int redovi();
    virtual string zaglavljeKolone(int kolona);
    virtual string zaglavljeRedova(int red);
    virtual string vrednostPolja(int kolona, int red);
};

#endif // KOLEKCIJA_ODELJENJA_H