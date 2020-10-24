#include "Nagrada.h"

Nagrada::Nagrada() {

}

Nagrada::Nagrada(Radnik* radnik, int procenti, Datum pocetak, Datum kraj)
: radnik(radnik), procenti(procenti), pocetak(pocetak), kraj(kraj) {

}

Nagrada::~Nagrada() {

}

Radnik* Nagrada::getRadnik() {
    return radnik;
}

void Nagrada::setRadnik(Radnik* radnik) {
    this->radnik = radnik;
}

int Nagrada::getProcenti() {
    return procenti;
}

void Nagrada::setProcenti(int procenti) {
    this->procenti = procenti;
}

Datum Nagrada::getPocetak() {
    return pocetak;
}

void Nagrada::setPocetak(Datum pocetak) {
    this->pocetak = pocetak;
}

Datum Nagrada::getKraj() {
    return kraj;
}

void Nagrada::setKraj(Datum kraj) {
    this->kraj = kraj;
}