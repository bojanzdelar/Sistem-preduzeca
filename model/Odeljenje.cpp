#include "Odeljenje.h"

Odeljenje::Odeljenje() {

}

Odeljenje::Odeljenje(string naziv, Radnik* sef, vector<Radnik*> zaposleni, string preduzece) 
: naziv(naziv), sef(sef), zaposleni(zaposleni), preduzece(preduzece) {

}

Odeljenje::~Odeljenje() {

}

string Odeljenje::getNaziv() const {
    return naziv;
}

void Odeljenje::setNaziv(string naziv) {
    this->naziv = naziv;
}

Radnik* Odeljenje::getSef() const {
    return sef;
}

void Odeljenje::setSef(Radnik* sef) {
    this->sef = sef;
}

vector<Radnik*> Odeljenje::getZaposleni() const {
    return zaposleni;
}

void Odeljenje::setZaposleni(vector<Radnik*> zaposleni) {
    this->zaposleni = zaposleni;
}

string Odeljenje::getPreduzece() const {
    return preduzece;
}

void Odeljenje::setPreduzece(string preduzece) {
    this->preduzece = preduzece;
}

void Odeljenje::zaposli(Radnik* radnik) {
    zaposleni.push_back(radnik);
}

void Odeljenje::otkaz(int indeks) {
    if (indeks < 0 || indeks >= zaposleni.size()) {
        return;
    }
    zaposleni.erase(zaposleni.begin() + indeks);
}