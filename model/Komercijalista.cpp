#include "Komercijalista.h"
 
Komercijalista::Komercijalista() : Radnik() {

}

Komercijalista::Komercijalista(string id, string ime, string prezime, double plata, vector<Nagrada*> *nagrade, 
    Odeljenje* odeljenje, Radnik *nadredjeni, vector<string> poslovniKontakti)
: Radnik(id, ime, prezime, plata, nagrade, odeljenje, nadredjeni), poslovniKontakti(poslovniKontakti) {

}

Komercijalista::~Komercijalista() {

}

vector<string> Komercijalista::getPoslovniKontakti() const {
    return poslovniKontakti;
}

void Komercijalista::setPoslovniKontakti() {
    this->poslovniKontakti = poslovniKontakti;
}

string Komercijalista::getPosao() const {
    return "komercijalista";
}

void Komercijalista::procitaj(istream &input, vector<string> elementi) {
    Radnik::procitaj(input, elementi);
    for (size_t i = 6; i < elementi.size(); i++) {
        poslovniKontakti.push_back(elementi[i]);
    }
}

void Komercijalista::zapisi(ostream &output) const {
    Radnik::zapisi(output);
     for (size_t i = 0; i < poslovniKontakti.size(); i++) {
        output << SEP << poslovniKontakti[i];
    }
    output << endl;
}