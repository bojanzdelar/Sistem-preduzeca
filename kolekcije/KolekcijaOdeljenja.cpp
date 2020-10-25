#include "KolekcijaOdeljenja.h"

KolekcijaOdeljenja::KolekcijaOdeljenja() {

}

KolekcijaOdeljenja::KolekcijaOdeljenja(vector<Odeljenje*> odeljenja) 
: odeljenja(odeljenja) {

}

KolekcijaOdeljenja::~KolekcijaOdeljenja() {

}

vector<Odeljenje*> KolekcijaOdeljenja::getOdeljenja() {
    return odeljenja;
}

void KolekcijaOdeljenja::setOdeljenja(vector<Odeljenje*> odeljenja) {
    this->odeljenja = odeljenja;
}

int KolekcijaOdeljenja::kolone() {
    return 4;
}

int KolekcijaOdeljenja::redovi() {
    return odeljenja.size();
}

string KolekcijaOdeljenja::zaglavljeKolone(int kolona) {
    if (kolona == 0) {
        return "ID";
    }
    else if (kolona == 1) {
        return "Naziv";
    } 
    else if (kolona == 2) {
        return "Sef";
    } 
    else if (kolona == 3) {
        return "Preduzece";
    } 
    else {
        return "";
    }
}

string KolekcijaOdeljenja::zaglavljeRedova(int red) {
    ostringstream out;
    out << red + 1;
    return out.str();
}

string KolekcijaOdeljenja::vrednostPolja(int kolona, int red) {
    if (kolona == 0) {
        return odeljenja.at(red)->getId();
    }
    else if (kolona == 1) {
        return odeljenja.at(red)->getNaziv();
    } 
    else if (kolona == 2) {
        return odeljenja.at(red)->getSef()->getId();
    } 
    else if (kolona == 3) {
        return odeljenja.at(red)->getPreduzece();
    }
    else {
        return "";
    } 
}