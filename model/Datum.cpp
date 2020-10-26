#include "Datum.h"

Datum::Datum() {

}

Datum::Datum(int godina, int mesec, int dan) 
: godina(godina), mesec(mesec), dan(dan) { 

}

Datum::Datum(string input) {
    vector<string> elementi = tokenizacija(input, "-");
    dan = stoi(elementi[0]);
    mesec = stoi(elementi[1]);
    godina = stoi(elementi[2]);
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
    datum = Datum(linija);
    return input;
}

ostream& operator<<(ostream& output, const Datum &datum) {
    output << datum.dan << "-" << datum.mesec << "-" << datum.godina;
    return output;
}