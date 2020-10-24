#include "Preduzece.h"

Preduzece::Preduzece() {

}

Preduzece::Preduzece(string naziv, int maticniBroj, int pib, vector<Odeljenje*> odeljenja)
: naziv(naziv), maticniBroj(maticniBroj), pib(pib), odeljenja(odeljenja) {

}

Preduzece::~Preduzece() {

}

string Preduzece::getNaziv() {
    return naziv;
}

void Preduzece::setNaziv(string naziv) {
    this->naziv = naziv;
}

int Preduzece::getMaticniBroj() {
    return maticniBroj;
}

void Preduzece::setMaticniBroj(int maticniBroj) {
    this->maticniBroj = maticniBroj;
}

int Preduzece::getPib() {
    return pib;
}

void Preduzece::setPib(int pib) {
    this->pib = pib;
}

vector<Odeljenje*> Preduzece::getOdeljenja() {
    return odeljenja;
}

void Preduzece::setOdeljenja(vector<Odeljenje*> odeljenja) {
    this->odeljenja = odeljenja;
}