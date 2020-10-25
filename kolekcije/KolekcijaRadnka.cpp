#include "KolekcijaRadnika.h"

KolekcijaRadnika::KolekcijaRadnika() {

}

KolekcijaRadnika::KolekcijaRadnika(vector<Radnik*> radnici) 
: radnici(radnici) {

}

KolekcijaRadnika::~KolekcijaRadnika() {

}

vector<Radnik*> KolekcijaRadnika::getRadnici() {
    return radnici;
}

void KolekcijaRadnika::setRadnici(vector<Radnik*> radnici) {
    this->radnici = radnici;
}

int KolekcijaRadnika::kolone() {
    return 6;
}

int KolekcijaRadnika::redovi() {
    return radnici.size();
}

string KolekcijaRadnika::zaglavljeKolone(int kolona) {
    if (kolona == 0) {
        return "Posao";
    } 
    else if (kolona == 1) {
        return "ID";
    } 
    else if (kolona == 2) {
        return "Ime";
    } 
    else if (kolona == 3) {
        return "Prezime";
    } 
    else if (kolona == 4) {
        return "Plata";
    } 
    else if (kolona == 5) {
        return "Nadredjeni";
    } 
    else {
        return "";
    }
}

string KolekcijaRadnika::zaglavljeRedova(int red) {
    ostringstream out;
    out << red + 1;
    return out.str();
}

string KolekcijaRadnika::vrednostPolja(int kolona, int red) {
    Radnik* radnik = radnici.at(red);
    ostringstream out;
    if (kolona == 0) {
        out << radnici.at(red)->getPosao();
    } 
    else if (kolona == 1) {
        out << radnici.at(red)->getId();
    } 
    else if (kolona == 2) {
        out << radnici.at(red)->getIme();
    } 
    else if (kolona == 3) {
        out << radnici.at(red)->getPrezime();
    } 
    else if (kolona == 4) {
        out.precision(2);
        out << fixed << radnici.at(red)->getPlata();
    } 
    else if (kolona == 5) {
        out << radnici.at(red)->getNadredjeni()->getId();
    } 
    return out.str();
}