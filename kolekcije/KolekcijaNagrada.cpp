#include "KolekcijaNagrada.h"

KolekcijaNagrada::KolekcijaNagrada() {

}

KolekcijaNagrada::KolekcijaNagrada(vector<Nagrada*> nagrade) 
: nagrade(nagrade) {

}

KolekcijaNagrada::~KolekcijaNagrada() {

}

vector<Nagrada*> KolekcijaNagrada::getOdeljenja() {
    return nagrade;
}

void KolekcijaNagrada::setOdeljenja(vector<Nagrada*> nagrade) {
    this->nagrade = nagrade;
}

int KolekcijaNagrada::kolone() {
    return 4;
}

int KolekcijaNagrada::redovi() {
    return nagrade.size();
}

string KolekcijaNagrada::zaglavljeKolone(int kolona) {
    if (kolona == 0) {
        return "ID radnika";
    } 
    else if (kolona == 1) {
        return "Bonus";
    } 
    else if (kolona == 2) {
        return "Datum pocetka";
    } 
    else if (kolona == 3) {
        return "Datum kraja";
    }
    else {
        return "";
    }
}

string KolekcijaNagrada::zaglavljeRedova(int red) {
    ostringstream out;
    out << red + 1;
    return out.str();
}

string KolekcijaNagrada::vrednostPolja(int kolona, int red) {
    ostringstream out;
    if (kolona == 0) {
        out << nagrade.at(red)->getRadnikId();
    } 
    else if (kolona == 1) {
        out << nagrade.at(red)->getProcenti();
    } 
    else if (kolona == 2) {
        out << nagrade.at(red)->getPocetak();
    }
    else if (kolona == 3) {
        out << nagrade.at(red)->getKraj();
    }
    return out.str();
}