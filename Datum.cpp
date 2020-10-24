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