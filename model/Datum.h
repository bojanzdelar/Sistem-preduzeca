#ifndef DATUM_H
#define DATUM_H

#include <iostream>

#include "../servisi/Util.h"

using namespace std;

class Datum {
private:
    int godina;
    int mesec;
    int dan;

public:
    Datum();
    Datum(int godina, int mesec, int dan);
    Datum(string input);
    virtual ~Datum();

    int getGodina() const;
    void setGodina(int godina);
    int getMesec() const;
    void setMesec(int mesec);
    int getDan() const;
    void setDan(int dan);

    friend istream& operator>>(istream& input, Datum &datum);
    friend ostream& operator<<(ostream& output, const Datum &datum);
};

#endif // DATUM_H