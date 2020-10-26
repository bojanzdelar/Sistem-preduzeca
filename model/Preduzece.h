#ifndef PREDUZECE_H
#define PREDUZECE_H

#include "Odeljenje.h"

// Preduzeće je opisano nazivom, matičnim brojem i poreskim identifikacionim brojem - pib. 
// Svako preduzeće se sastoji iz proizvoljnog broja odeljenja
class Preduzece : public PoslovnaJedinica {
private: 
    string naziv;
    int maticniBroj;
    int pib;
    vector<Odeljenje*> *odeljenja;

public:
    Preduzece();
    Preduzece(string naziv, int maticniBroj, int pib, vector<Odeljenje*> *odeljenja);
    virtual ~Preduzece();

    string getNaziv() const;
    void setNaziv(string naziv);
    int getMaticniBroj() const;
    void setMaticniBroj(int maticniBroj);
    int getPib() const;
    void setPib(int pib);
    vector<Odeljenje*> *getOdeljenja() const;
    void setOdeljenja(vector<Odeljenje*> *odeljenja);

    virtual double minimalnaPlata() const;
    virtual double prosecnaPlata() const;
    virtual double maksimalnaPlata() const;

    friend istream& operator>>(istream &input, Preduzece *preduzece);
    friend ostream& operator<<(ostream &output, const Preduzece *preduzece);
};

#endif // PREDUZECE_H