#include "Revizor.h"

Revizor::Revizor() : Radnik() {

}

Revizor::Revizor(string id, string ime, string prezime, double plata, vector<Nagrada*> nagrade, Radnik *nadredjeni, vector<Datum> revizije)
: Radnik(id, ime, prezime, plata, nagrade, nadredjeni), revizije(revizije) {

}

Revizor::~Revizor() {

}

vector<Datum> Revizor::getRevizije() {
    return revizije;
}

void Revizor::setRevizije(vector<Datum> revizije) {
    this->revizije = revizije;
}

string Revizor::getPosao() {
    return "revizor";
}