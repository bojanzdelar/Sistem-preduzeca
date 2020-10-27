#include "KolekcijaNagrada.h"

KolekcijaNagrada::KolekcijaNagrada() {

}

KolekcijaNagrada::KolekcijaNagrada(vector<Nagrada*> kolekcija) : TabelarnaKolekcija(kolekcija) {

}

KolekcijaNagrada::~KolekcijaNagrada() {

}

int KolekcijaNagrada::kolone() const {
    return 4;
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

string KolekcijaNagrada::vrednostPolja(int kolona, int red) const {
    ostringstream out;
    if (kolona == 0) {
        out << kolekcija.at(red)->getRadnik()->getId();
    } 
    else if (kolona == 1) {
        out << kolekcija.at(red)->getProcenti();
    } 
    else if (kolona == 2) {
        out << kolekcija.at(red)->getPocetak();
    }
    else if (kolona == 3) {
        out << kolekcija.at(red)->getKraj();
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
        kolekcijaNagrada.kolekcija.push_back(nagrada);
    }
    return input;
}

ostream& operator<<(ostream &output, const KolekcijaNagrada &kolekcijaNagrada) {
    output << "#nagrada" << endl;
    for (Nagrada *nagrada : kolekcijaNagrada.kolekcija) {
        output << nagrada;
    }
    return output;
}