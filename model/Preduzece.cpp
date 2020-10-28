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

double Preduzece::minimalnaPlata() const {
    double min = odeljenja->size() ? odeljenja->at(0)->minimalnaPlata() : -1;
    for (size_t i = 1; i < odeljenja->size(); i++) {
        double plata = odeljenja->at(i)->minimalnaPlata();
        if (min > plata) {
            min = plata;
        }
    }
    return min;
}

// nije najprezicnija matematicka formula za prosek
double Preduzece::prosecnaPlata() const {
    double prosek = 0;
     for (size_t i = 0; i < odeljenja->size(); i++) {
         prosek += odeljenja->at(i)->prosecnaPlata(); 
    }
    return prosek / odeljenja->size();
}

double Preduzece::maksimalnaPlata() const {
    double max = odeljenja->size() ? odeljenja->at(0)->maksimalnaPlata() : -1;
    for (size_t i = 1; i < odeljenja->size(); i++) {
        double plata = odeljenja->at(i)->maksimalnaPlata();
        if (max < plata) {
            max = plata;
        }
    }
    return max;
}

void Preduzece::dodajOdeljenje(Odeljenje *odeljenje) {
    odeljenja->push_back(odeljenje);
}

void Preduzece::ukloniOdeljenje(Odeljenje* odeljenje) {
    for (size_t i = 0; i < odeljenja->size(); i++) {
        if (odeljenje == odeljenja->at(i)) {
            odeljenja->erase(odeljenja->begin() + i);
            return;
        }
    }
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