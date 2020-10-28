#ifndef RADNIK_H
#define RADNIK_H

#include <string>
#include <vector>

#include "Nagrada.h"

using namespace std;

class Odeljenje;

// Svaki radnik je predstavljen apstraktnom klasom koja od atributa sadrži 
// ime, prezime, visinu plate i podataka o nadređenom radniku
// Radnik istovremeno može imati više bonusa.
class Radnik {
protected:
    string id;
    string ime;
    string prezime;
    double plata;
    Odeljenje *odeljenje;
    vector<Nagrada*> *nagrade;
    string idNadredjeni; // pomoc za ucitavanje iz datoteke
    Radnik *nadredjeni;

public:
    Radnik();
    Radnik(string id, string ime, string prezime, double plata, vector<Nagrada*> *nagrade, Odeljenje *odeljenje, Radnik *nadredjeni);
    virtual ~Radnik();

    string getId() const;
    void setId(string id);
    string getIme() const;
    void setIme(string ime);
    string getPrezime() const;
    void setPrezime(string prezime);
    double getPlata() const;
    void setPlata(double plata);
    Odeljenje* getOdeljenje() const;
    void setOdeljenje(Odeljenje *odeljenje);
    vector<Nagrada*>* getNagrade() const;
    void setNagrade(vector<Nagrada*> *nagrade);
    string getIdNadredjeni() const;
    Radnik* getNadredjeni() const;
    void setNadredjeni(Radnik *nadredjeni);
    virtual string getPosao() const = 0;

    void dodajNagradu(Nagrada *nagrada);
    void ukloniNagradu(Nagrada *nagrada);

    virtual void procitaj(istream &input, vector<string> elementi) = 0;
    virtual void zapisi(ostream &output) const = 0;

    friend istream& operator>>(istream &input, Radnik *radnik);
    friend ostream& operator<<(ostream &output, const Radnik *radnik);
};

#endif // RADNIK_H