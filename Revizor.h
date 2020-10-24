#ifndef REVIZOR_H
#define REVIZOR_H

#include <vector>

#include "Radnik.h"
#include "Datum.h"

// Revizor sadrži spisak datuma kada je vršio revizije u odeljenju u kojem je zaposlen
class Revizor : public Radnik {
private:
    vector<Datum> revizije; // datumi revizija

public:
    Revizor();
    Revizor(string ime, string prezime, double plata, Radnik *nadredjeni, vector<Datum> revizije);
    virtual ~Revizor();

    vector<Datum> getRevizije();
    void setRevizije(vector<Datum> revizije);
    virtual string getPosao();
};

#endif // REVIZOR_H