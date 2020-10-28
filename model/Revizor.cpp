#include "Revizor.h"

Revizor::Revizor() : Radnik() {

}

Revizor::Revizor(string id, string ime, string prezime, double plata, Odeljenje* odeljenje, Radnik *nadredjeni, vector<string> revizije, vector<Nagrada*> *nagrade)
: Radnik(id, ime, prezime, plata, nagrade, odeljenje, nadredjeni), revizije(revizije) {

}

Revizor::~Revizor() {

}

vector<string> Revizor::getRevizije() const {
    return revizije;
}

void Revizor::setRevizije(vector<string> revizije) {
    this->revizije = revizije;
}

string Revizor::getPosao() const {
    return "revizor";
}


void Revizor::procitaj(istream &input, vector<string> elementi) {
    Radnik::procitaj(input, elementi);
    for (size_t i = 6; i < elementi.size(); i++) {
        revizije.push_back(elementi[i]);
    }
}

void Revizor::zapisi(ostream &output) const {
    Radnik::zapisi(output);
    for (size_t i = 0; i < revizije.size(); i++) {
        output << SEP << revizije[i];
    }
    output << endl;
}