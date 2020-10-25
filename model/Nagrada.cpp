#include "Nagrada.h"

Nagrada::Nagrada() {

}

Nagrada::Nagrada(string radnikId, int procenti, Datum pocetak, Datum kraj)
: radnikId(radnikId), procenti(procenti), pocetak(pocetak), kraj(kraj) {

}

Nagrada::~Nagrada() {

}

string Nagrada::getRadnikId() const {
    return radnikId;
}

void Nagrada::setRadnikId(string radnikId) {
    this->radnikId = radnikId;
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