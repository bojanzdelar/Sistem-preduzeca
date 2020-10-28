#include "KolekcijaPreduzeca.h"

KolekcijaPreduzeca::KolekcijaPreduzeca() {

}

KolekcijaPreduzeca::KolekcijaPreduzeca(vector<Preduzece*> kolekcija) : TabelarnaKolekcija(kolekcija) {

}

KolekcijaPreduzeca::~KolekcijaPreduzeca() {

}

int KolekcijaPreduzeca::kolone() const {
    return 3;
}

string KolekcijaPreduzeca::zaglavljeKolone(int kolona) const {
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

string KolekcijaPreduzeca::vrednostPolja(int kolona, int red) const {
    ostringstream out;
    if (kolona == 0) {
        out << kolekcija.at(red)->getNaziv();
    } 
    else if (kolona == 1) {
        out << kolekcija.at(red)->getMaticniBroj();
    } 
    else if (kolona == 2) {
        out << kolekcija.at(red)->getPib();
    }
    return out.str();
}

Preduzece* KolekcijaPreduzeca::dobaviId(int maticniBroj) const {
    for (size_t i = 0; i < redovi(); i++) {
        if (maticniBroj == kolekcija.at(i)->getMaticniBroj()) {
            return kolekcija.at(i);
        }
    }
    return nullptr;
}

bool KolekcijaPreduzeca::maticniBrojZauzet(int maticniBroj) const {
    for (size_t i = 0; i < redovi(); i++) {
        if (maticniBroj == kolekcija.at(i)->getMaticniBroj()) {
            return true;
        }
    }
    return false;
}

istream& operator>>(istream &input, KolekcijaPreduzeca &kolekcijaPreduzeca) {
    string linija = "";
    while (linija != "#preduzece" && input.peek() != EOF) {
        getline(input, linija);
    }
    while (input.peek() != '#' && input.peek() != EOF) { 
        Preduzece *preduzece = new Preduzece();
        input >> preduzece;
        kolekcijaPreduzeca.kolekcija.push_back(preduzece);
    }
    return input;
}

ostream& operator<<(ostream &output, const KolekcijaPreduzeca &kolekcijaPreduzeca) {
    output << "#preduzece" << endl;
    for (Preduzece *preduzece : kolekcijaPreduzeca.kolekcija) {
        output << preduzece;
    }
    return output;
}