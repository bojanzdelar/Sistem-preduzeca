#include "Nagrada.h"

Nagrada::Nagrada() {

}

Nagrada::Nagrada(string radnikId, int procenti, Datum pocetak, Datum kraj)
: radnikId(radnikId), procenti(procenti), pocetak(pocetak), kraj(kraj) {

}

Nagrada::~Nagrada() {

}

string Nagrada::getRadnikId() {
    return radnikId;
}

void Nagrada::setRadnikId(string radnikId) {
    this->radnikId = radnikId;
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