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
    Racunovodja(string ime, string prezime, double plata, Radnik *nadredjeni, string izdavacLicence, double maksimalniPrihod);
    virtual ~Racunovodja();

    string getIzdavacLicence();
    void setIzdavacLicence(string izdavacLicence);
    double getMaksimalniPrihod();
    void setMaksimalniPrihod(double maksimalniPrihod);
    virtual string getPosao();
};

#endif // RACUNOVODJA_H