#ifndef KOLEKCIJA_NAGRADA_H
#define KOLEKCIJA_NAGRADA_H

#include <vector>
#include <sstream>

#include "../model/Nagrada.h"
#include "../model/Radnik.h"
#include "TabelarnaKolekcija.h"

class KolekcijaNagrada : public TabelarnaKolekcija {
private:
    vector<Nagrada*> nagrade;

public:
    KolekcijaNagrada();
    KolekcijaNagrada(vector<Nagrada*> nagrade);
    virtual ~KolekcijaNagrada();

    vector<Nagrada*> getNagrade() const;
    void setNagrade(vector<Nagrada*> nagrade);

    virtual int kolone() const;
    virtual int redovi() const;
    virtual string zaglavljeKolone(int kolona) const;
    virtual string zaglavljeRedova(int red) const;
    virtual string vrednostPolja(int kolona, int red) const;

    friend istream& operator>>(istream &input, KolekcijaNagrada &kolekcijaNagrada);
    friend ostream& operator<<(ostream &output, const KolekcijaNagrada &kolekcijaNagrada);
};

#endif // KOLEKCIJA_ODELJENJA_H