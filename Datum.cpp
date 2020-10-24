#include "Datum.h"

Datum::Datum() {

}

Datum::Datum(int godina, int mesec, int dan) 
: godina(godina), mesec(mesec), dan(dan) { 

}

Datum::~Datum() {

}

int Datum::getGodina() {
    return godina;
}

void Datum::setGodina(int godina) {
    this->godina = godina;
}

int Datum::getMesec() {
    return mesec;
}

void Datum::setMesec(int mesec) {
    this->mesec = mesec;
}

int Datum::getDan() {
    return dan;
}

void Datum::setDan(int dan) {
    this->dan = dan;
}