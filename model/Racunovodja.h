#ifndef RACUNOVODJA_H
#define RACUNOVODJA_H

#include "Radnik.h"

// Računovođa sadrži podatak o telu koje mu je izdalo licencu za rad i o 
// maksimalnoj visini prihoda preduzeća za koje može da vodi knjige
class Racunovodja : public Radnik {
private:
    string izdavacLicence;
    double maksimalniPrihod; // preduzeća za koje može da vodi knjige

public:
    Racunovodja();
    Racunovodja(string id, string ime, string prezime, double plata, Odeljenje* odeljenje,
        Radnik *nadredjeni, string izdavacLicence, double maksimalniPrihod, vector<Nagrada*> *nagrade = new vector<Nagrada*>);
    virtual ~Racunovodja();

    string getIzdavacLicence() const;
    void setIzdavacLicence(string izdavacLicence);
    double getMaksimalniPrihod() const;
    void setMaksimalniPrihod(double maksimalniPrihod);
    virtual string getPosao() const;

    virtual void procitaj(istream &input, vector<string> elementi);
    virtual void zapisi(ostream &output) const;
};

#endif // RACUNOVODJA_H