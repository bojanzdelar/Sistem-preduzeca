#ifndef KOLEKCIJA_RADNIKA_H
#define KOLEKCIJA_RADNIKA_H

#include <sstream>

#include "../model/Radnik.h"
#include "../model/Racunovodja.h"
#include "../model/Revizor.h"
#include "../model/Komercijalista.h"
#include "TabelarnaKolekcija.h"

class KolekcijaRadnika : public TabelarnaKolekcija {
private:
    vector<Radnik*> radnici;

public:
    KolekcijaRadnika();
    KolekcijaRadnika(vector<Radnik*> radnici);
    virtual ~KolekcijaRadnika();

    vector<Radnik*> getRadnici() const;
    void setRadnici(vector<Radnik*> radnici);

    virtual int kolone() const;
    virtual int redovi() const;
    virtual string zaglavljeKolone(int kolona) const;
    virtual string zaglavljeRedova(int red) const;
    virtual string vrednostPolja(int kolona, int red) const;

    friend istream& operator>>(istream &input, KolekcijaRadnika &kolekcijaRadnika);
    friend ostream& operator<<(ostream &output, const KolekcijaRadnika &kolekcijaRadnika);
};

#endif // KOLEKCIJA_RADNIKA_H