#include "KolekcijaOdeljenja.h"

KolekcijaOdeljenja::KolekcijaOdeljenja() {

}

KolekcijaOdeljenja::KolekcijaOdeljenja(vector<Odeljenje*> kolekcija) : TabelarnaKolekcija(kolekcija) {

}

KolekcijaOdeljenja::~KolekcijaOdeljenja() {

}

int KolekcijaOdeljenja::kolone() const {
    return 4;
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

string KolekcijaOdeljenja::vrednostPolja(int kolona, int red) const {
    ostringstream out;
    if (kolona == 0) {
        out << kolekcija.at(red)->getId();
    }
    else if (kolona == 1) {
        out << kolekcija.at(red)->getNaziv();
    } 
    else if (kolona == 2) {
        out << kolekcija.at(red)->getSef()->getId();
    } 
    else if (kolona == 3) {
        out << kolekcija.at(red)->getPreduzece()->getMaticniBroj();
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
        kolekcijaOdeljenja.kolekcija.push_back(odeljenje);
    }
    return input;
}

ostream& operator<<(ostream &output, const KolekcijaOdeljenja &kolekcijaOdeljenja) {
    output << "#odeljenje" << endl;
    for (Odeljenje *odeljenje : kolekcijaOdeljenja.kolekcija) {
        output << odeljenje;
    }
    return output;
}