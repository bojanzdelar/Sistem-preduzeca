#include "Radnik.h"

Radnik::Radnik() {

}

Radnik::Radnik(string ime, string prezime, double plata, Radnik *nadredjeni) 
: ime(ime), prezime(prezime), plata(plata), nadredjeni(nadredjeni) {

}

Radnik::~Radnik() {

}

string Radnik::getIme() {
    return ime;
}

void Radnik::setIme(string ime) {
    this->ime = ime;
}

string Radnik::getPrezime() {
    return prezime;
}

void Radnik::setPrezime(string prezime) {
    this->prezime = prezime;
}

double Radnik::getPlata() {
    return plata;
}

void Radnik::setPlata(double plata) {
    this->plata = plata;
}

Radnik* Radnik::getNadredjeni() {
    return nadredjeni;
}

void Radnik::setNadredjeni(Radnik *nadredjeni) {
    this->nadredjeni = nadredjeni;
}