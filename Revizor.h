#ifndef REVIZOR_H
#define REVIZOR_H

#include <vector>

#include "Radnik.h"

// Revizor sadrži spisak datuma kada je vršio revizije u odeljenju u kojem je zaposlen
class Revizor : public Radnik {
private:
    vector<string> revizije; // datumi revizija

public:
    Revizor();
    Revizor(string ime, string prezime, double plata, Radnik *nadredjeni, vector<string> revizije);
    virtual ~Revizor();

    vector<string> getRevizije();
    void setRevizije(vector<string> revizije);
    virtual string getPosao();
};

#endif // REVIZOR_H