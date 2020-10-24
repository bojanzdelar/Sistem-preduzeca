#include "Revizor.h"

Revizor::Revizor() : Radnik() {

}

Revizor::Revizor(string ime, string prezime, double plata, Radnik *nadredjeni, vector<string> revizije)
: Radnik(ime, prezime, plata, nadredjeni), revizije(revizije) {

}

Revizor::~Revizor() {

}

vector<string> Revizor::getRevizije() {
    return revizije;
}

void Revizor::setRevizije(vector<string> revizije) {
    this->revizije = revizije;
}

string Revizor::getPosao() {
    return "revizor";
}