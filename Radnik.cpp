#include "Radnik.h"

Radnik::Radnik() {

}

Radnik::Radnik(string id, string ime, string prezime, double plata, vector<Nagrada*> nagrade, Radnik *nadredjeni) 
: id(id), ime(ime), prezime(prezime), plata(plata), nagrade(nagrade), nadredjeni(nadredjeni) {

}

Radnik::~Radnik() {

}

string Radnik::getIme() const {
    return ime;
}

void Radnik::setIme(string ime) {
    this->ime = ime;
}

string Radnik::getPrezime() const {
    return prezime;
}

void Radnik::setPrezime(string prezime) {
    this->prezime = prezime;
}

double Radnik::getPlata() const {
    return plata;
}

void Radnik::setPlata(double plata) {
    this->plata = plata;
}

Radnik* Radnik::getNadredjeni() const {
    return nadredjeni;
}

void Radnik::setNadredjeni(Radnik *nadredjeni) {
    this->nadredjeni = nadredjeni;
}