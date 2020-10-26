#include "KolekcijaNagrada.h"

KolekcijaNagrada::KolekcijaNagrada() {

}

KolekcijaNagrada::KolekcijaNagrada(vector<Nagrada*> nagrade) 
: nagrade(nagrade) {

}

KolekcijaNagrada::~KolekcijaNagrada() {

}

vector<Nagrada*> KolekcijaNagrada::getNagrade() const {
    return nagrade;
}

void KolekcijaNagrada::setNagrade(vector<Nagrada*> nagrade) {
    this->nagrade = nagrade;
}

int KolekcijaNagrada::kolone() const {
    return 4;
}

int KolekcijaNagrada::redovi() const {
    return nagrade.size();
}

string KolekcijaNagrada::zaglavljeKolone(int kolona) const {
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

string KolekcijaNagrada::zaglavljeRedova(int red) const {
    ostringstream out;
    out << red + 1;
    return out.str();
}

string KolekcijaNagrada::vrednostPolja(int kolona, int red) const {
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

istream& operator>>(istream &input, KolekcijaNagrada &kolekcijaNagrada) {
    string linija = "";
    while (linija != "#nagrada") {
        getline(input, linija);
    }
    while (input.peek() != '#' && input.peek() != EOF) { 
        Nagrada *nagrada = new Nagrada();
        input >> nagrada;
        kolekcijaNagrada.nagrade.push_back(nagrada);
    }
    return input;
}

ostream& operator<<(ostream &output, const KolekcijaNagrada &kolekcijaNagrada) {
    output << "#nagrada" << endl;
    for (Nagrada *nagrada : kolekcijaNagrada.nagrade) {
        output << nagrada;
    }
    return output;
}