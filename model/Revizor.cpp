#include "Revizor.h"

Revizor::Revizor() : Radnik() {

}

Revizor::Revizor(string id, string ime, string prezime, double plata, vector<Nagrada*> nagrade, string odeljenje, Radnik *nadredjeni, vector<Datum> revizije)
: Radnik(id, ime, prezime, plata, nagrade, odeljenje, nadredjeni), revizije(revizije) {

}

Revizor::~Revizor() {

}

vector<Datum> Revizor::getRevizije() const {
    return revizije;
}

void Revizor::setRevizije(vector<Datum> revizije) {
    this->revizije = revizije;
}

string Revizor::getPosao() const {
    return "revizor";
}


void Revizor::procitaj(istream &input, vector<string> elementi) {
    Radnik::procitaj(input, elementi);
    for (size_t i = 6; i < elementi.size(); i++) {
        revizije.push_back(Datum(elementi[i]));
    }
}

void Revizor::zapisi(ostream &output) const {
    Radnik::zapisi(output);
    for (size_t i = 0; i < revizije.size(); i++) {
        output << SEP << revizije[i];
    }
    output << endl;
}