#include "Radnik.h"

Radnik::Radnik() {

}

Radnik::Radnik(string ime, string prezime, double visinaPlate, Radnik *nadredjeni) 
: ime(ime), prezime(prezime), visinaPlate(visinaPlate), nadredjeni(nadredjeni) {

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

double Radnik::getVisinaPlate() {
    return visinaPlate;
}

void Radnik::setVisinaPlate(double visinaPlate) {
    this->visinaPlate = visinaPlate;
}

Radnik* Radnik::getNadredjeni() {
    return nadredjeni;
}

void Radnik::setNadredjeni(Radnik *nadredjeni) {
    this->nadredjeni = nadredjeni;
}