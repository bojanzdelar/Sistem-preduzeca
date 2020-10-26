#include "Nagrada.h"
#include "Radnik.h"
#include "Revizor.h"

Nagrada::Nagrada() {

}

Nagrada::Nagrada(Radnik *radnik, int procenti, Datum pocetak, Datum kraj)
: radnik(radnik), procenti(procenti), pocetak(pocetak), kraj(kraj) {

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

Datum Nagrada::getPocetak() const {
    return pocetak;
}

void Nagrada::setPocetak(Datum pocetak) {
    this->pocetak = pocetak;
}

Datum Nagrada::getKraj() const {
    return kraj;
}

void Nagrada::setKraj(Datum kraj) {
    this->kraj = kraj;
}

istream& operator>>(istream &input, Nagrada *nagrada) {
    string linija;
    getline(input, linija);
    vector<string> elementi = tokenizacija(linija, SEP);
    Radnik *radnik = new Revizor(); // privremeno za cuvanje id radnika
    radnik->setId(elementi[0]);
    nagrada->radnik = radnik;
    nagrada->procenti = stoi(elementi[1]);
    nagrada->pocetak = Datum(elementi[2]);
    nagrada->kraj = Datum(elementi[3]);
    return input;
}

ostream& operator<<(ostream &output, const Nagrada *nagrada) {
    output << nagrada->radnik->getId() << SEP << nagrada->procenti << SEP << nagrada->pocetak << SEP << nagrada->kraj << endl;
    return output;
}