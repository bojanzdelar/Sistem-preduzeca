#include "Preduzece.h"

Preduzece::Preduzece() {
    odeljenja = new vector<Odeljenje*>;
}

Preduzece::Preduzece(string naziv, int maticniBroj, int pib, vector<Odeljenje*> *odeljenja)
: naziv(naziv), maticniBroj(maticniBroj), pib(pib), odeljenja(odeljenja) {

}

Preduzece::~Preduzece() {

}

string Preduzece::getNaziv() const {
    return naziv;
}

void Preduzece::setNaziv(string naziv) {
    this->naziv = naziv;
}

int Preduzece::getMaticniBroj() const {
    return maticniBroj;
}

void Preduzece::setMaticniBroj(int maticniBroj) {
    this->maticniBroj = maticniBroj;
}

int Preduzece::getPib() const {
    return pib;
}

void Preduzece::setPib(int pib) {
    this->pib = pib;
}

vector<Odeljenje*> *Preduzece::getOdeljenja() const {
    return odeljenja;
}

void Preduzece::setOdeljenja(vector<Odeljenje*> *odeljenja) {
    this->odeljenja = odeljenja;
}

istream& operator>>(istream &input, Preduzece *preduzece) {
    string linija;
    getline(input, linija);
    vector<string> elementi = tokenizacija(linija, SEP);
    preduzece->naziv = elementi[0];
    preduzece->maticniBroj = stoi(elementi[1]);
    preduzece->pib = stoi(elementi[2]);
    return input;
}

ostream& operator<<(ostream &output, const Preduzece *preduzece) {
    output << preduzece->naziv << SEP << preduzece->maticniBroj << SEP << preduzece->pib << endl;
    return output;
}