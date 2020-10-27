#include "KolekcijaRadnika.h"

KolekcijaRadnika::KolekcijaRadnika() {

}

KolekcijaRadnika::KolekcijaRadnika(vector<Radnik*> kolekcija) : TabelarnaKolekcija(kolekcija) {

} 

KolekcijaRadnika::~KolekcijaRadnika() {

}

int KolekcijaRadnika::kolone() const {
    return 6;
}

string KolekcijaRadnika::zaglavljeKolone(int kolona) const {
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

string KolekcijaRadnika::vrednostPolja(int kolona, int red) const {
    Radnik* radnik = kolekcija.at(red);
    ostringstream out;
    if (kolona == 0) {
        out << kolekcija.at(red)->getPosao();
    } 
    else if (kolona == 1) {
        out << kolekcija.at(red)->getId();
    } 
    else if (kolona == 2) {
        out << kolekcija.at(red)->getIme();
    } 
    else if (kolona == 3) {
        out << kolekcija.at(red)->getPrezime();
    } 
    else if (kolona == 4) {
        out.precision(2);
        out << fixed << kolekcija.at(red)->getPlata();
    } 
    else if (kolona == 5) {
        out << kolekcija.at(red)->getNadredjeni()->getId();
    } 
    return out.str();
}

istream& operator>>(istream &input, KolekcijaRadnika &kolekcijaRadnika) {
    string linija = "";
    while (linija != "#radnik") {
        getline(input, linija);
    }
    while (input.peek() != '#' && input.peek() != EOF) { 
        Radnik *radnik;
        string posao;
        getline(input, posao);
        if (posao == "racunovodja") {
            radnik = new Racunovodja();
        } 
        else if (posao == "revizor") {
            radnik = new Revizor();
        }
        else if (posao == "komercijalista") {
            radnik = new Komercijalista();
        } 
        input >> radnik;
        kolekcijaRadnika.kolekcija.push_back(radnik);
    }
    return input;
}

ostream& operator<<(ostream &output, const KolekcijaRadnika &kolekcijaRadnika) {
    output << "#radnik" << endl;
    for (Radnik *radnik : kolekcijaRadnika.kolekcija) {
        output << radnik;
    }
    return output;
}