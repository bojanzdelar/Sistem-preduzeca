#ifndef RADNIK_H
#define RADNIK_H

#include <string>
#include <vector>

#include "Nagrada.h"

using namespace std;

// Svaki radnik je predstavljen apstraktnom klasom koja od atributa sadrži 
// ime, prezime, visinu plate i podataka o nadređenom radniku
// Radnik istovremeno može imati više bonusa.
class Radnik {
protected:
    string id;
    string ime;
    string prezime;
    double plata;
    vector<Nagrada*> nagrade;
    Radnik *nadredjeni;

public:
    Radnik();
    Radnik(string id, string ime, string prezime, double plata, vector<Nagrada*> nagrade, Radnik *nadredjeni);
    virtual ~Radnik();

    string getIme() const;
    void setIme(string ime);
    string getPrezime() const;
    void setPrezime(string prezime);
    double getPlata() const;
    void setPlata(double plata);
    Radnik* getNadredjeni() const;
    void setNadredjeni(Radnik *nadredjeni);
    virtual string getPosao() const = 0;
};

#endif // RADNIK_H