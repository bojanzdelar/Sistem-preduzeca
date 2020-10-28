#ifndef NAGRADA_H
#define NAGRADA_H

#include <iostream>
#include <string>

#include "../servisi/Util.h"

using namespace std;

const string SEP = ";"; // separator

class Radnik;

// Nagrada se specificira kao privremeno uvećanje plate koje je izraženo procentualno i ima važenje u zadatom vremenskom periodu
class Nagrada {
private:
    Radnik *radnik;
    int procenti;
    int brojMeseci;

public:
    Nagrada();
    Nagrada(Radnik *radnik, int procenti, int brojMeseci);
    virtual ~Nagrada();
    
    Radnik* getRadnik() const;
    void setRadnik(Radnik *radnik);
    int getProcenti() const;
    void setProcenti(int procenti);
    int getBrojMeseci() const;
    void setBrojMeseci(int brojMeseci);

    friend istream& operator>>(istream &input, Nagrada *nagrada);
    friend ostream& operator<<(ostream &output, const Nagrada* nagrada);
};

#endif // NAGRADA_H