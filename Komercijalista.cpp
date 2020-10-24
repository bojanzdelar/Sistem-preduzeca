#include "Komercijalista.h"
 
Komercijalista::Komercijalista() : Radnik() {

}

Komercijalista::Komercijalista(string ime, string prezime, double plata, Radnik *nadredjeni, vector<string> poslovniKontakti)
: Radnik(ime, prezime, plata, nadredjeni), poslovniKontakti(poslovniKontakti) {

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