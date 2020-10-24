#ifndef PREDUZECE_H
#define PREDUZECE_H

#include "Odeljenje.h"

// Preduzeće je opisano nazivom, matičnim brojem i poreskim identifikacionim brojem - pib. 
// Svako preduzeće se sastoji iz proizvoljnog broja odeljenja
class Preduzece {
private: 
    string naziv;
    int maticniBroj;
    int pib;
    vector<Odeljenje*> odeljenja;

public:
    Preduzece();
    Preduzece(string naziv, int maticniBroj, int pib, vector<Odeljenje*> odeljenja);
    virtual ~Preduzece();

    string getNaziv();
    void setNaziv(string naziv);
    int getMaticniBroj();
    void setMaticniBroj(int maticniBroj);
    int getPib();
    void setPib(int pib);
    vector<Odeljenje*> getOdeljenja();
    void setOdeljenja(vector<Odeljenje*> odeljenja);
};

#endif // PREDUZECE_H