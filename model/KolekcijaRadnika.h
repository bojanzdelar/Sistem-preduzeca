// nazovi tabela radnika?

#ifndef KOLEKCIJA_RADNIKA_H
#define KOLEKCIJA_RADNIKA_H

#include <sstream>

#include "Radnik.h"
#include "TabelarnaKolekcija.h"

class KolekcijaRadnika {
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
};

#endif // KOLEKCIJA_RADNIKA_H