#include "Radnik.h"

Radnik::Radnik() {
    nagrade = new vector<Nagrada*>;
}

Radnik::Radnik(string id, string ime, string prezime, double plata, vector<Nagrada*> *nagrade, string odeljenje, Radnik *nadredjeni) 
: id(id), ime(ime), prezime(prezime), plata(plata), odeljenje(odeljenje), nagrade(nagrade), nadredjeni(nadredjeni) {

}

Radnik::~Radnik() {

}

string Radnik::getId() const {
    return id;
}

void Radnik::setId(string id) {
    this->id = id;
}

string Radnik::getIme() const {
    return ime;
}

void Radnik::setIme(string ime) {
    this->ime = ime;
}

string Radnik::getPrezime() const {
    return prezime;
}

void Radnik::setPrezime(string prezime) {
    this->prezime = prezime;
}

double Radnik::getPlata() const {
    return plata;
}

void Radnik::setPlata(double plata) {
    this->plata = plata;
}

string Radnik::getOdeljenje() const {
    return odeljenje;
}

void Radnik::setOdeljenje(string odeljenje) {
    this->odeljenje = odeljenje;
}

vector<Nagrada*>* Radnik::getNagrade() const {
    return nagrade;
}

void Radnik::setNagrade(vector<Nagrada*> *nagrade) {
    this->nagrade = nagrade;
}

string Radnik::getIdNadredjeni() const {
    return idNadredjeni;
}

Radnik* Radnik::getNadredjeni() const {
    return nadredjeni;
}

void Radnik::setNadredjeni(Radnik *nadredjeni) {
    this->nadredjeni = nadredjeni;
}

void Radnik::procitaj(istream &input, vector<string> elementi) {
    id = elementi[0];
    ime = elementi[1];
    prezime = elementi[2];
    plata = stod(elementi[3]);
    odeljenje = elementi[4];
    idNadredjeni = elementi[5];
}

void Radnik::zapisi(ostream &output) const {
    output << getPosao() << endl;
    output << id << SEP << ime << SEP << prezime << SEP << plata << SEP << odeljenje << SEP << idNadredjeni;
}

istream& operator>>(istream& input, Radnik* radnik) {
    string linija;
    getline(input, linija);
    vector<string> elementi = tokenizacija(linija, SEP);
    radnik->procitaj(input, elementi);
    return input;
}

ostream& operator<<(ostream& output, const Radnik* radnik) {
    radnik->zapisi(output);
    return output;
}