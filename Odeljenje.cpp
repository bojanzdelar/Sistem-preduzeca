#include "Odeljenje.h"

Odeljenje::Odeljenje() {

}

Odeljenje::Odeljenje(string naziv, Radnik* sef, vector<Radnik*> zaposleni) 
: naziv(naziv), sef(sef), zaposleni(zaposleni) {

}

Odeljenje::~Odeljenje() {

}

string Odeljenje::getNaziv() {
    return naziv;
}

void Odeljenje::setNaziv(string naziv) {
    this->naziv = naziv;
}

Radnik* Odeljenje::getSef() {
    return sef;
}

void Odeljenje::setSef(Radnik* sef) {
    this->sef = sef;
}

vector<Radnik*> Odeljenje::getZaposleni() {
    return zaposleni;
}

void Odeljenje::setZaposleni(vector<Radnik*> zaposleni) {
    this->zaposleni = zaposleni;
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