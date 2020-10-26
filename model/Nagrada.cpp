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

istream& operator>>(istream &input, Nagrada *nagrada) {
    string linija;
    getline(input, linija);
    vector<string> elementi = tokenizacija(linija, SEP);
    nagrada->radnikId = elementi[0];
    nagrada->procenti = stoi(elementi[1]);
    nagrada->pocetak = Datum(elementi[2]);
    nagrada->kraj = Datum(elementi[3]);
    return input;
}

ostream& operator<<(ostream &output, const Nagrada *nagrada) {
    output << nagrada->radnikId << SEP << nagrada->procenti << SEP << nagrada->pocetak << SEP << nagrada->kraj << endl;
    return output;
}