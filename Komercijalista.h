#ifndef KOMERCIJALISTA_H
#define KOMERCIJALISTA_H

#include <vector>

#include "Radnik.h"

// Komercijalista sadrži spisak ostvarenih poslovnih kontakata
class Komercijalista : public Radnik {
private:
    vector<string> poslovniKontakti;

public:
    Komercijalista();
    Komercijalista(string ime, string prezime, double plata, Radnik *nadredjeni, vector<string> poslovniKontakti);
    virtual ~Komercijalista();

    vector<string> getPoslovniKontakti();
    void setPoslovniKontakti();
    virtual string getPosao();
};

#endif // KOMERCIJALISTA_H