#ifndef KOLEKCIJA_NAGRADA_H
#define KOLEKCIJA_NAGRADA_H

#include <vector>
#include <sstream>

#include "../model/Nagrada.h"
#include "../model/Radnik.h"
#include "TabelarnaKolekcija.h"

class KolekcijaNagrada : public TabelarnaKolekcija<Nagrada*> {
private:
    vector<Nagrada*> kolekcija;

public:
    KolekcijaNagrada();
    KolekcijaNagrada(vector<Nagrada*> kolekcija);
    virtual ~KolekcijaNagrada();

    virtual int kolone() const;
    virtual string zaglavljeKolone(int kolona) const;
    virtual string vrednostPolja(int kolona, int red) const;

    friend istream& operator>>(istream &input, KolekcijaNagrada &kolekcijaNagrada);
    friend ostream& operator<<(ostream &output, const KolekcijaNagrada &kolekcijaNagrada);
};

#endif // KOLEKCIJA_ODELJENJA_H