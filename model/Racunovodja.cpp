#include "Racunovodja.h"
 
Racunovodja::Racunovodja() : Radnik() {

}

Racunovodja::Racunovodja(string id, string ime, string prezime, double plata, Odeljenje* odeljenje, Radnik *nadredjeni, 
    string izdavacLicence, double maksimalniPrihod, vector<Nagrada*> *nagrade) 
: Radnik(id, ime, prezime, plata, nagrade, odeljenje, nadredjeni), izdavacLicence(izdavacLicence),  maksimalniPrihod(maksimalniPrihod) {

}
                                                   
Racunovodja::~Racunovodja() {

}

string Racunovodja::getIzdavacLicence() const {
    return izdavacLicence;
}

void Racunovodja::setIzdavacLicence(string izdavacLicence) {
    this->izdavacLicence;
}

double Racunovodja::getMaksimalniPrihod() const {
    return maksimalniPrihod;
}

void Racunovodja::setMaksimalniPrihod(double maksimalniPrihod)
{
    this->maksimalniPrihod = maksimalniPrihod;
}

string Racunovodja::getPosao() const {
    return "racunovodja";
}

void Racunovodja::procitaj(istream &input, vector<string> elementi) {
    Radnik::procitaj(input, elementi);
    izdavacLicence = elementi[6];
    maksimalniPrihod = stod(elementi[7]);
}

void Racunovodja::zapisi(ostream &output) const {
    Radnik::zapisi(output);
    output << SEP << izdavacLicence << SEP << maksimalniPrihod << endl;
}