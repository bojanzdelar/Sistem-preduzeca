#include "KolekcijaPreduzeca.h"

KolekcijaPreduzeca::KolekcijaPreduzeca() {

}

KolekcijaPreduzeca::KolekcijaPreduzeca(vector<Preduzece*> preduzeca) 
: preduzeca(preduzeca) {

}

KolekcijaPreduzeca::~KolekcijaPreduzeca() {

}

vector<Preduzece*> KolekcijaPreduzeca::getPreduzeca() const {
    return preduzeca;
}

void KolekcijaPreduzeca::setPreduzeca(vector<Preduzece*> preduzeca) {
    this->preduzeca = preduzeca;
}

int KolekcijaPreduzeca::kolone() const {
    return 3;
}

int KolekcijaPreduzeca::redovi() const {
    return preduzeca.size();
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

string KolekcijaPreduzeca::zaglavljeRedova(int red) const {
    ostringstream out;
    out << red + 1;
    return out.str();
}

string KolekcijaPreduzeca::vrednostPolja(int kolona, int red) const {
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

istream& operator>>(istream &input, KolekcijaPreduzeca &kolekcijaPreduzeca) {
    string linija = "";
    while (linija != "#preduzece") {
        getline(input, linija);
    }
    while (input.peek() != '#' && input.peek() != EOF) { 
        Preduzece *preduzece = new Preduzece();
        input >> preduzece;
        kolekcijaPreduzeca.preduzeca.push_back(preduzece);
    }
    return input;
}

ostream& operator<<(ostream &output, const KolekcijaPreduzeca &kolekcijaPreduzeca) {
    output << "#preduzece" << endl;
    for (Preduzece *preduzece : kolekcijaPreduzeca.preduzeca) {
        output << preduzece;
    }
    return output;
}