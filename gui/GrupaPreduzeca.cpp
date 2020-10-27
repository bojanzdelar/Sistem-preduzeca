#include "GrupaPreduzeca.h"

GrupaPreduzeca::GrupaPreduzeca(int x, int y, int w, int h, KolekcijaPreduzeca *preduzeca, const char *label) 
: Fl_Group(x, y, w, h, label) {
    Tabela<Preduzece*> *tabela = new Tabela<Preduzece*>(x + 50, x + 50, 300, 300, preduzeca);
    naziv = new Fl_Input(x + 500, y + 10, 150, 30, "Naziv:");
    maticniBroj = new Fl_Int_Input(x + 500, y + 50, 150, 30, "Maticni broj:");
    pib = new Fl_Int_Input(x + 500, y + 90, 150, 30, "Pib:");
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
    string pib = grupa->maticniBroj->value();
    if (naziv == "" || maticniBroj == "" || pib == "") {
        return;
    }
    Preduzece *preduzece = new Preduzece(naziv, stoi(maticniBroj), stoi(pib));


}

void GrupaPreduzeca::prikazi(Fl_Widget *widget, void *data) {
    GrupaPreduzeca *grupa = (GrupaPreduzeca*) data;

}

void GrupaPreduzeca::izmeni(Fl_Widget *widget, void *data) {
    GrupaPreduzeca *grupa = (GrupaPreduzeca*) data;

}

void GrupaPreduzeca::ukloni(Fl_Widget *widget, void *data) {
    GrupaPreduzeca *grupa = (GrupaPreduzeca*) data;

}