#ifndef RADNIK_H
#define RADNIK_H

#include <string>

using namespace std;

// Svaki radnik je predstavljen apstraktnom klasom koja od atributa sadrži 
// ime, prezime, visinu plate i podataka o nadređenom radniku
class Radnik {
protected:
    string ime;
    string prezime;
    double visinaPlate;
    Radnik *nadredjeni;

public:
    Radnik();
    Radnik(string ime, string prezime, double visinaPlate, Radnik *nadredjeni);
    virtual ~Radnik();

    string getIme();
    void setIme(string ime);
    string getPrezime();
    void setPrezime(string prezime);
    double getVisinaPlate();
    void setVisinaPlate(double visinaPlate);
    Radnik* getNadredjeni();
    void setNadredjeni(Radnik *nadredjeni);
    //virtual string getPosao() = 0;
};

#endif