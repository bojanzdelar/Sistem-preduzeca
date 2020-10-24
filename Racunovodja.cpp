#include "Racunovodja.h"
 
Racunovodja::Racunovodja() : Radnik() {

}

Racunovodja::Racunovodja(string id, string ime, string prezime, double plata, vector<Nagrada*> nagrade, Radnik *nadredjeni, 
    string izdavacLicence, double maksimalniPrihod) 
: Radnik(id, ime, prezime, plata, nagrade, nadredjeni), izdavacLicence(izdavacLicence),  maksimalniPrihod(maksimalniPrihod) {

}
                                                   
Racunovodja::~Racunovodja() {

}

string Racunovodja::getIzdavacLicence() {
    return izdavacLicence;
}

void Racunovodja::setIzdavacLicence(string izdavacLicence) {
    this->izdavacLicence;
}

double Racunovodja::getMaksimalniPrihod() {
    return maksimalniPrihod;
}

void Racunovodja::setMaksimalniPrihod(double maksimalniPrihod)
{
    this->maksimalniPrihod = maksimalniPrihod;
}

string Racunovodja::getPosao() {
    return "racunovodja";
}