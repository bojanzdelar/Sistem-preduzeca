#include "KolekcijaPreduzeca.h"

KolekcijaPreduzeca::KolekcijaPreduzeca() {

}

KolekcijaPreduzeca::KolekcijaPreduzeca(vector<Preduzece*> preduzeca) 
: preduzeca(preduzeca) {

}

KolekcijaPreduzeca::~KolekcijaPreduzeca() {

}

vector<Preduzece*> KolekcijaPreduzeca::getPreduzeca() {
    return preduzeca;
}

void KolekcijaPreduzeca::setPreduzeca(vector<Preduzece*> preduzeca) {
    this->preduzeca = preduzeca;
}

int KolekcijaPreduzeca::kolone() {
    return 3;
}

int KolekcijaPreduzeca::redovi() {
    return preduzeca.size();
}

string KolekcijaPreduzeca::zaglavljeKolone(int kolona) {
    if (kolona == 0) {
        return "Naziv";
    } 
    else if (kolona == 1) {
        return "Maticni broj";
    } 
    else if (kolona == 2) {
        return "PIB";
    } 
    else {
        return "";
    }
}

string KolekcijaPreduzeca::zaglavljeRedova(int red) {
    ostringstream out;
    out << red + 1;
    return out.str();
}

string KolekcijaPreduzeca::vrednostPolja(int kolona, int red) {
    ostringstream out;
    if (kolona == 0) {
        out << preduzeca.at(red)->getNaziv();
    } 
    else if (kolona == 1) {
        out << preduzeca.at(red)->getMaticniBroj();
    } 
    else if (kolona == 2) {
        out << preduzeca.at(red)->getPib();
    }
    return out.str();
}