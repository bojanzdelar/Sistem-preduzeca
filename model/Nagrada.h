#ifndef NAGRADA_H
#define NAGRADA_H

#include <string>

#include "Datum.h"

using namespace std;

const string SEP = ";"; // separator

class Radnik;

// Nagrada se specificira kao privremeno uvećanje plate koje je izraženo procentualno i ima važenje u zadatom vremenskom periodu
class Nagrada {
private:
    Radnik *radnik;
    int procenti;
    Datum pocetak;
    Datum kraj;

public:
    Nagrada();
    Nagrada(Radnik *radnik, int procenti, Datum pocetak, Datum kraj);
    virtual ~Nagrada();
    
    Radnik* getRadnik() const;
    void setRadnik(Radnik *radnik);
    int getProcenti() const;
    void setProcenti(int procenti);
    Datum getPocetak() const;
    void setPocetak(Datum pocetak);
    Datum getKraj() const;
    void setKraj(Datum kraj);

    friend istream& operator>>(istream &input, Nagrada *nagrada);
    friend ostream& operator<<(ostream &output, const Nagrada* nagrada);
};

#endif // NAGRADA_H