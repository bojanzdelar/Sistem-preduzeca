#ifndef KOLEKCIJA_PREDUZECA_H
#define KOLEKCIJA_PREDUZECA_H

#include "../model/Preduzece.h"
#include "TabelarnaKolekcija.hpp"

class KolekcijaPreduzeca : public TabelarnaKolekcija<Preduzece*> {
public:
    KolekcijaPreduzeca();
    KolekcijaPreduzeca(vector<Preduzece*> kolekcija);
    virtual ~KolekcijaPreduzeca();

    virtual int kolone() const;
    virtual string zaglavljeKolone(int kolona) const;
    virtual string vrednostPolja(int kolona, int red) const;

    friend istream& operator>>(istream &input, KolekcijaPreduzeca &kolekcijaPreduzeca);
    friend ostream& operator<<(ostream &output, const KolekcijaPreduzeca &KolekcijaPreduzeca);
};

#endif // KOLEKCIJA_ODELJENJA_H