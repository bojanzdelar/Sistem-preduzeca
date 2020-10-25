// nazovi tabela radnika?

#ifndef KOLEKCIJA_RADNIKA_H
#define KOLEKCIJA_RADNIKA_H

#include <sstream>

#include "Radnik.h"

class KolekcijaRadnika {
private:
    vector<Radnik*> radnici;

public:
    KolekcijaRadnika();
    KolekcijaRadnika(vector<Radnik*> radnici);
    virtual ~KolekcijaRadnika();

    vector<Radnik*> getRadnici();
    void setRadnici(vector<Radnik*> radnici);

    int kolone();
    int redovi();
    string zaglavljeKolone(int kolona);
    string zaglavljeRedova(int red);
    string vrednostPolja(int kolona, int red);
};

#endif // KOLEKCIJA_RADNIKA_H