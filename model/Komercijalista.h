#ifndef KOMERCIJALISTA_H
#define KOMERCIJALISTA_H

#include "Radnik.h"

// Komercijalista sadrži spisak ostvarenih poslovnih kontakata
class Komercijalista : public Radnik {
private:
    vector<string> poslovniKontakti;

public:
    Komercijalista();
    Komercijalista(string id, string ime, string prezime, double plata, Odeljenje* odeljenje, Radnik *nadredjeni, 
        vector<string> poslovniKontakti, vector<Nagrada*> *nagrade = new vector<Nagrada*>);
    virtual ~Komercijalista();

    vector<string> getPoslovniKontakti() const;
    void setPoslovniKontakti(vector<string> poslovniKontakti);
    virtual string getPosao() const;

    virtual void procitaj(istream &input, vector<string> elementi);
    virtual void zapisi(ostream &output) const;
};

#endif // KOMERCIJALISTA_H