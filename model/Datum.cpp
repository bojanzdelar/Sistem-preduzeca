#include "Datum.h"

Datum::Datum() {

}

Datum::Datum(int godina, int mesec, int dan) 
: godina(godina), mesec(mesec), dan(dan) { 

}

Datum::~Datum() {

}

int Datum::getGodina() const {
    return godina;
}

void Datum::setGodina(int godina) {
    this->godina = godina;
}

int Datum::getMesec() const {
    return mesec;
}

void Datum::setMesec(int mesec) {
    this->mesec = mesec;
}

int Datum::getDan() const {
    return dan;
}

void Datum::setDan(int dan) {
    this->dan = dan;
}

istream& operator>>(istream& input, Datum &datum) {
    string linija;
    getline(input, linija);
    vector<string> elementi = tokenizacija(linija);
    datum.godina = stoi(elementi[0]);
    datum.mesec = stoi(elementi[0]);
    datum.dan = stoi(elementi[0]);
    return input;
}

ostream& operator<<(ostream& output, const Datum &datum) {
    output << datum.godina << "-" << datum.mesec << "-" << datum.dan;
    return output;
}