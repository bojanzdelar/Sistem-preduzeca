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

    vector<Preduzece*> getPreduzeca() const;
    void setPreduzeca(vector<Preduzece*> preduzeca);

    virtual int kolone() const;
    virtual int redovi() const;
    virtual string zaglavljeKolone(int kolona) const;
    virtual string zaglavljeRedova(int red) const;
    virtual string vrednostPolja(int kolona, int red) const;

    friend istream& operator>>(istream &input, KolekcijaPreduzeca &kolekcijaPreduzeca);
    friend ostream& operator<<(ostream &output, const KolekcijaPreduzeca &KolekcijaPreduzeca);
};

#endif // KOLEKCIJA_ODELJENJA_H