#include "KolekcijaOdeljenja.h"

KolekcijaOdeljenja::KolekcijaOdeljenja() {

}

KolekcijaOdeljenja::KolekcijaOdeljenja(vector<Odeljenje*> odeljenja) 
: odeljenja(odeljenja) {

}

KolekcijaOdeljenja::~KolekcijaOdeljenja() {

}

vector<Odeljenje*> KolekcijaOdeljenja::getOdeljenja() const {
    return odeljenja;
}

void KolekcijaOdeljenja::setOdeljenja(vector<Odeljenje*> odeljenja) {
    this->odeljenja = odeljenja;
}

int KolekcijaOdeljenja::kolone() const {
    return 4;
}

int KolekcijaOdeljenja::redovi() const {
    return odeljenja.size();
}

string KolekcijaOdeljenja::zaglavljeKolone(int kolona) const {
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

string KolekcijaOdeljenja::zaglavljeRedova(int red) const {
    ostringstream out;
    out << red + 1;
    return out.str();
}

string KolekcijaOdeljenja::vrednostPolja(int kolona, int red) const {
    ostringstream out;
    if (kolona == 0) {
        out << odeljenja.at(red)->getId();
    }
    else if (kolona == 1) {
        out << odeljenja.at(red)->getNaziv();
    } 
    else if (kolona == 2) {
        out << odeljenja.at(red)->getSef()->getId();
    } 
    else if (kolona == 3) {
        out << odeljenja.at(red)->getPreduzece()->getMaticniBroj();
    }
    return out.str();
}

istream& operator>>(istream &input, KolekcijaOdeljenja &kolekcijaOdeljenja) {
    string linija = "";
    while (linija != "#odeljenje") {
        getline(input, linija);
    }
    while (input.peek() != '#' && input.peek() != EOF) { 
        Odeljenje *odeljenje = new Odeljenje();
        input >> odeljenje;
        kolekcijaOdeljenja.odeljenja.push_back(odeljenje);
    }
    return input;
}

ostream& operator<<(ostream &output, const KolekcijaOdeljenja &kolekcijaOdeljenja) {
    output << "#odeljenje" << endl;
    for (Odeljenje *odeljenje : kolekcijaOdeljenja.odeljenja) {
        output << odeljenje;
    }
    return output;
}