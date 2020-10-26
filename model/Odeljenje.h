#ifndef ODELJENJE_H
#define ODELJENJE_H

#include <vector>

#include "Radnik.h"
#include "Revizor.h" 

// Odeljenje je opisano nazivom i u sebi sadrži podatke o šefu odeljenja i trenutno zaposlenim
// radnicima. U odeljenju obezbediti metode za zapošljavanje novih radnika i za davanje otkaza već zaposlenim radnicima.
class Odeljenje {
private:
    string id;
    string naziv;
    Radnik* sef;
    vector<Radnik*>* zaposleni;
    string preduzece;

public:
    Odeljenje();
    Odeljenje(string naziv, Radnik* sef, vector<Radnik*>* zaposleni, string preduzece);
    virtual ~Odeljenje();

    string getId() const;
    void setId(string id);
    string getNaziv() const;
    void setNaziv(string naziv);
    Radnik* getSef() const;
    void setSef(Radnik* sef);
    vector<Radnik*> *getZaposleni() const;
    void setZaposleni(vector<Radnik*>* zaposleni);
    string getPreduzece() const;
    void setPreduzece(string preduzece);

    double minimalnaPlata();
    double prosecnaPlata();
    double maksimalnaPlata();

    void zaposli(Radnik* radnik);
    void otkaz(int indeks);

    friend istream& operator>>(istream &input, Odeljenje *odeljenje);
    friend ostream& operator<<(ostream &output, const Odeljenje *odeljenje);
};

#endif // ODELJENJE_H
