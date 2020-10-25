#include "Preduzece.h"

Preduzece::Preduzece() {

}

Preduzece::Preduzece(string naziv, int maticniBroj, int pib, vector<Odeljenje*> odeljenja)
: naziv(naziv), maticniBroj(maticniBroj), pib(pib), odeljenja(odeljenja) {

}

Preduzece::~Preduzece() {

}

string Preduzece::getNaziv() const {
    return naziv;
}

void Preduzece::setNaziv(string naziv) {
    this->naziv = naziv;
}

int Preduzece::getMaticniBroj() const {
    return maticniBroj;
}

void Preduzece::setMaticniBroj(int maticniBroj) {
    this->maticniBroj = maticniBroj;
}

int Preduzece::getPib() const {
    return pib;
}

void Preduzece::setPib(int pib) {
    this->pib = pib;
}

vector<Odeljenje*> Preduzece::getOdeljenja() const {
    return odeljenja;
}

void Preduzece::setOdeljenja(vector<Odeljenje*> odeljenja) {
    this->odeljenja = odeljenja;
}