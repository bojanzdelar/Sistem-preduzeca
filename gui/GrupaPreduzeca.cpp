#include "GrupaPreduzeca.h"

GrupaPreduzeca::GrupaPreduzeca(int x, int y, int w, int h, Kolekcije *kolekcije, const char *label) 
: Fl_Group(x, y, w, h, label), kolekcije(kolekcije) {
    tabela = new Tabela<Preduzece*>(x + 10, y + 10, 700, 415, &kolekcije->preduzeca);
    naziv = new Fl_Input(x + 800, y + 10, 150, 30, "Naziv:");
    maticniBroj = new Fl_Int_Input(x + 800, y + 50, 150, 30, "Maticni\nbroj:");
    maticniBroj->maximum_size(8);
    pib = new Fl_Int_Input(x + 800, y + 90, 150, 30, "Pib:");
    pib->maximum_size(9);
    dodajButton = new Fl_Button(x + 750, y + 140, 80, 40, "Dodaj");
    dodajButton->callback(dodaj, this);
    prikaziButton = new Fl_Button(x + 840, y + 140, 80, 40, "Prikazi");
    prikaziButton->callback(prikazi, this);
    izmeniButton = new Fl_Button(x + 930, y + 140, 80, 40, "Izmeni");
    izmeniButton->callback(izmeni, this);
    ukloniButton = new Fl_Button(x + 1020, y + 140, 80, 40, "Ukloni");
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
    grupa->azuriraj();
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
    grupa->azuriraj();
}

void GrupaPreduzeca::ukloni(Fl_Widget *widget, void *data) {
    GrupaPreduzeca *grupa = (GrupaPreduzeca*) data;
    int red = grupa->tabela->izabraniRed();
    if (red == -1) {
        return;
    }
    Preduzece *preduzece = grupa->kolekcije->preduzeca.dobavi(red);
    grupa->kolekcije->ukloniPreduzece(preduzece);
    delete preduzece;
    grupa->azuriraj();
}

void GrupaPreduzeca::azuriraj() {
    tabela->azuriraj();
}