#ifndef KOLEKCIJA_PREDUZECA_H
#define KOLEKCIJA_PREDUZECA_H

#include <sstream>

#include "../model/Preduzece.h"
#include "TabelarnaKolekcija.h"

class KolekcijaPreduzeca : public TabelarnaKolekcija {
private:
    vector<Preduzece*> preduzeca;

public:
    KolekcijaPreduzeca();
    KolekcijaPreduzeca(vector<Preduzece*> preduzeca);
    virtual ~KolekcijaPreduzeca();

    vector<Preduzece*> getPreduzeca();
    void setPreduzeca(vector<Preduzece*> preduzeca);

    virtual int kolone();
    virtual int redovi();
    virtual string zaglavljeKolone(int kolona);
    virtual string zaglavljeRedova(int red);
    virtual string vrednostPolja(int kolona, int red);

    friend istream& operator>>(istream &input, KolekcijaPreduzeca &kolekcijaPreduzeca);
    friend ostream& operator<<(ostream &output, const KolekcijaPreduzeca &KolekcijaPreduzeca);
};

#endif // KOLEKCIJA_ODELJENJA_H