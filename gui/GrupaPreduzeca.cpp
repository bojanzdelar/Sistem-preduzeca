#include "GrupaPreduzeca.h"

GrupaPreduzeca::GrupaPreduzeca(int x, int y, int w, int h, Kolekcije *kolekcije, const char *label) 
: Fl_Group(x, y, w, h, label), kolekcije(kolekcije) {
    tabela = new Tabela<Preduzece*>(x + 50, y + 50, 300, 300, &kolekcije->preduzeca);
    naziv = new Fl_Input(x + 500, y + 10, 150, 30, "Naziv:");
    maticniBroj = new Fl_Int_Input(x + 500, y + 50, 150, 30, "Maticni broj:");
    maticniBroj->maximum_size(8);
    pib = new Fl_Int_Input(x + 500, y + 90, 150, 30, "Pib:");
    pib->maximum_size(9);
    dodajButton = new Fl_Button(x + 500, y + 140, 50, 30, "Dodaj");
    dodajButton->callback(dodaj, this);
    prikaziButton = new Fl_Button(x + 500, y + 190, 50, 30, "Prikazi");
    prikaziButton->callback(prikazi, this);
    izmeniButton = new Fl_Button(x + 566, y + 140, 50, 30, "Izmeni");
    izmeniButton->callback(izmeni, this);
    ukloniButton = new Fl_Button(x + 632, y + 140, 50, 30, "Ukloni");
    ukloniButton->callback(ukloni, this);
    end();
}

GrupaPreduzeca::~GrupaPreduzeca() {

}

void GrupaPreduzeca::dodaj(Fl_Widget *widget, void *data) {
    GrupaPreduzeca *grupa = (GrupaPreduzeca*) data;
    string naziv = grupa->naziv->value();
    string maticniBroj = grupa->maticniBroj->value();
    string pib = grupa->pib->value();
    if (naziv == "" || maticniBroj == "" || pib == "" || maticniBroj.find("-") != string::npos || pib.find("-") != string::npos
            || grupa->kolekcije->preduzeca.maticniBrojZauzet(stoi(maticniBroj))) {
        return;
    }
    Preduzece *preduzece = new Preduzece(naziv, stoi(maticniBroj), stoi(pib));
    grupa->kolekcije->preduzeca.dodaj(preduzece);
    grupa->tabela->azuriraj();
}

void GrupaPreduzeca::prikazi(Fl_Widget *widget, void *data) {
    GrupaPreduzeca *grupa = (GrupaPreduzeca*) data;
    int red = grupa->tabela->izabraniRed();
    if (red == -1) {
        return;
    }
    Preduzece *preduzece = grupa->kolekcije->preduzeca.dobavi(red);
    grupa->naziv->value(preduzece->getNaziv().c_str());
    ostringstream out;
    out << preduzece->getMaticniBroj();
    grupa->maticniBroj->value(out.str().c_str());
    out.str("");
    out << preduzece->getPib();
    grupa->pib->value(out.str().c_str());
}

void GrupaPreduzeca::izmeni(Fl_Widget *widget, void *data) {
    GrupaPreduzeca *grupa = (GrupaPreduzeca*) data;
    string naziv = grupa->naziv->value();
    string maticniBroj = grupa->maticniBroj->value();
    string pib = grupa->pib->value();
    int red = grupa->tabela->izabraniRed();
    if (naziv == "" || maticniBroj == "" || pib == "" || maticniBroj.find("-") != string::npos || pib.find("-") != string::npos 
            || red == -1 || stoi(maticniBroj) != grupa->kolekcije->preduzeca.dobavi(red)->getMaticniBroj()) {
        return;
    }
    Preduzece *preduzece = grupa->kolekcije->preduzeca.dobavi(red);
    preduzece->setNaziv(naziv);
    preduzece->setPib(stoi(pib));
    grupa->tabela->azuriraj();
}

void GrupaPreduzeca::ukloni(Fl_Widget *widget, void *data) {
    GrupaPreduzeca *grupa = (GrupaPreduzeca*) data;
    int red = grupa->tabela->izabraniRed();
    if (red == -1) {
        return;
    }
    grupa->kolekcije->preduzeca.ukloni(red);
    grupa->tabela->azuriraj();
}