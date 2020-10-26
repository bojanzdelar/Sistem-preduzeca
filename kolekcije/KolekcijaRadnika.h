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

    vector<Radnik*> getRadnici();
    void setRadnici(vector<Radnik*> radnici);

    virtual int kolone();
    virtual int redovi();
    virtual string zaglavljeKolone(int kolona);
    virtual string zaglavljeRedova(int red);
    virtual string vrednostPolja(int kolona, int red);

    friend istream& operator>>(istream &input, KolekcijaRadnika &kolekcijaRadnika);
    friend ostream& operator<<(ostream &output, const KolekcijaRadnika &kolekcijaRadnika);
};

#endif // KOLEKCIJA_RADNIKA_H