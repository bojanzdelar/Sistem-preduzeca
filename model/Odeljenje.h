#ifndef ODELJENJE_H
#define ODELJENJE_H

#include <vector>

#include "PoslovnaJedinica.h"
#include "Radnik.h"
#include "Revizor.h"

class Preduzece; 

// Odeljenje je opisano nazivom i u sebi sadrži podatke o šefu odeljenja i trenutno zaposlenim
// radnicima. U odeljenju obezbediti metode za zapošljavanje novih radnika i za davanje otkaza već zaposlenim radnicima.
class Odeljenje : public PoslovnaJedinica {
private:
    string id;
    string naziv;
    Radnik* sef;
    vector<Radnik*>* zaposleni;
    Preduzece *preduzece;

public:
    Odeljenje();
    Odeljenje(string id, string naziv, Radnik* sef, Preduzece *preduzece, vector<Radnik*>* zaposleni = new vector<Radnik*>);
    virtual ~Odeljenje();

    string getId() const;
    void setId(string id);
    string getNaziv() const;
    void setNaziv(string naziv);
    Radnik* getSef() const;
    void setSef(Radnik* sef);
    vector<Radnik*> *getZaposleni() const;
    void setZaposleni(vector<Radnik*>* zaposleni);
    Preduzece* getPreduzece() const;
    void setPreduzece(Preduzece *preduzece);

    virtual double minimalnaPlata() const;
    virtual double prosecnaPlata() const;
    virtual double maksimalnaPlata() const;

    void zaposli(Radnik* radnik);
    void otkaz(Radnik *radnik);

    friend istream& operator>>(istream &input, Odeljenje *odeljenje);
    friend ostream& operator<<(ostream &output, const Odeljenje *odeljenje);
};

#endif // ODELJENJE_H
