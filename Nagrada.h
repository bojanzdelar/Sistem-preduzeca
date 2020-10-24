#ifndef NAGRADA_H
#define NAGRADA_H

#include <string>

#include "Datum.h"

using namespace std;

// Nagrada se specificira kao privremeno uvećanje plate koje je izraženo procentualno i ima važenje u zadatom vremenskom periodu
class Nagrada {
private:
    string radnikId;
    int procenti;
    Datum pocetak;
    Datum kraj;

public:
    Nagrada();
    Nagrada(string radnikId, int procenti, Datum pocetak, Datum kraj);
    virtual ~Nagrada();
    
    string getRadnikId() const;
    void setRadnikId(string radnikId);
    int getProcenti() const;
    void setProcenti(int procenti);
    Datum getPocetak() const;
    void setPocetak(Datum pocetak);
    Datum getKraj() const;
    void setKraj(Datum kraj);
};

#endif // NAGRADA_H