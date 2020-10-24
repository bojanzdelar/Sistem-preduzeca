#ifndef NAGRADA_H
#define NAGRADA_H

#include "Radnik.h"
#include "Datum.h"

// Nagrada se specificira kao privremeno uvećanje plate koje je izraženo procentualno i ima važenje u zadatom vremenskom periodu
class Nagrada {
private:
    Radnik* radnik;
    int procenti;
    Datum pocetak;
    Datum kraj;

public:
    Nagrada();
    Nagrada(Radnik* radnik, int procenti, Datum pocetak, Datum kraj);
    virtual ~Nagrada();
    
    Radnik* getRadnik();
    void setRadnik(Radnik* radnik);
    int getProcenti();
    void setProcenti(int procenti);
    Datum getPocetak();
    void setPocetak(Datum pocetak);
    Datum getKraj();
    void setKraj(Datum kraj);
};

#endif // NAGRADA_H