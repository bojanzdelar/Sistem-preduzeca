#include "Komercijalista.h"
 
Komercijalista::Komercijalista() : Radnik() {

}

Komercijalista::Komercijalista(string id, string ime, string prezime, double plata, vector<Nagrada*> nagrade, 
    Radnik *nadredjeni, vector<string> poslovniKontakti)
: Radnik(id, ime, prezime, plata, nagrade, nadredjeni), poslovniKontakti(poslovniKontakti) {

}

Komercijalista::~Komercijalista() {

}

vector<string> Komercijalista::getPoslovniKontakti() {
    return poslovniKontakti;
}

void Komercijalista::setPoslovniKontakti() {
    this->poslovniKontakti = poslovniKontakti;
}

string Komercijalista::getPosao() {
    return "komercijalista";
}