#ifndef ODELJENJE_H
#define ODELJENJE_H

#include <vector>

#include "Radnik.h"

// Odeljenje je opisano nazivom i u sebi sadrži podatke o šefu odeljenja i trenutno zaposlenim
// radnicima. U odeljenju obezbediti metode za zapošljavanje novih radnika i za davanje otkaza već zaposlenim radnicima.
class Odeljenje {
private:
    string naziv;
    Radnik* sef;
    vector<Radnik*> zaposleni;

public:
    Odeljenje();
    Odeljenje(string naziv, Radnik* sef, vector<Radnik*> zaposleni);
    virtual ~Odeljenje();

    string getNaziv();
    void setNaziv(string naziv);
    Radnik* getSef();
    void setSef(Radnik* sef);
    vector<Radnik*> getZaposleni();
    void setZaposleni(vector<Radnik*> zaposleni);

    void zaposli(Radnik* radnik);
    void otkaz(int indeks);
};

#endif // ODELJENJE_H
