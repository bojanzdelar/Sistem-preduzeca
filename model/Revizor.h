#ifndef REVIZOR_H
#define REVIZOR_H

#include "Radnik.h"

// Revizor sadrži spisak datuma kada je vršio revizije u odeljenju u kojem je zaposlen
class Revizor : public Radnik {
private:
    vector<string> revizije; 

public:
    Revizor();
    Revizor(string id, string ime, string prezime, double plata, Odeljenje* odeljenje,
        Radnik *nadredjeni, vector<string> revizije, vector<Nagrada*> *nagrade = new vector<Nagrada*>);
    virtual ~Revizor();

    vector<string> getRevizije() const;
    void setRevizije(vector<string> revizije);
    virtual string getPosao() const;

    virtual void procitaj(istream &input, vector<string> elementi);
    virtual void zapisi(ostream &output) const;
};

#endif // REVIZOR_H