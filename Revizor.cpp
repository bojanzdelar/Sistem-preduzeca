#include "Revizor.h"

Revizor::Revizor() : Radnik() {

}

Revizor::Revizor(string ime, string prezime, double plata, Radnik *nadredjeni, vector<Datum> revizije)
: Radnik(ime, prezime, plata, nadredjeni), revizije(revizije) {

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