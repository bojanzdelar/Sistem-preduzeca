#include "Nagrada.h"
#include "Radnik.h"
#include "Revizor.h"

Nagrada::Nagrada() {

}

Nagrada::Nagrada(Radnik *radnik, int procenti, int brojMeseci)
: radnik(radnik), procenti(procenti), brojMeseci(brojMeseci) {

}

Nagrada::~Nagrada() {

}

Radnik* Nagrada::getRadnik() const {
    return radnik;
}

void Nagrada::setRadnik(Radnik *radnik) {
    this->radnik = radnik;
}

int Nagrada::getProcenti() const {
    return procenti;
}

void Nagrada::setProcenti(int procenti) {
    this->procenti = procenti;
}

int Nagrada::getBrojMeseci() const {
    return brojMeseci;
}

void Nagrada::setBrojMeseci(int brojMeseci) {
    this->brojMeseci = brojMeseci;
}

istream& operator>>(istream &input, Nagrada *nagrada) {
    string linija;
    getline(input, linija);
    vector<string> elementi = tokenizacija(linija, SEP);
    Radnik *radnik = new Revizor(); // privremeno za cuvanje id radnika
    radnik->setId(elementi[0]);
    nagrada->radnik = radnik;
    nagrada->procenti = stoi(elementi[1]);
    nagrada->brojMeseci = stoi(elementi[2]);
    return input;
}

ostream& operator<<(ostream &output, const Nagrada *nagrada) {
    output << nagrada->radnik->getId() << SEP << nagrada->procenti << SEP << nagrada->brojMeseci << endl;
    return output;
}