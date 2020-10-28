#include "GrupaNagrada.h"

GrupaNagrada::GrupaNagrada(int x, int y, int w, int h, Kolekcije *kolekcije, const char *label) 
: Fl_Group(x, y, w, h, label), kolekcije(kolekcije) {
    tabela = new Tabela<Nagrada*>(x + 50, x + 50, 300, 300, &kolekcije->nagrade);
    radnik = new Fl_Input(x + 500, y + 10, 150, 30, "Radnik:");
    procenti = new Fl_Int_Input(x + 500, y + 50, 150, 30, "Procenti:");
    brojMeseci = new Fl_Int_Input(x + 500, y + 90, 150, 30, "Broj meseci\ntrajanja:");
    dodajButton = new Fl_Button(x + 500, y + 130, 50, 30, "Dodaj");
    prikaziButton = new Fl_Button(x + 500, y + 280, 50, 30, "Prikazi");
    izmeniButton = new Fl_Button(x + 566, y + 130, 50, 30, "Izmeni");
    ukloniButton = new Fl_Button(x + 632, y + 130, 50, 30, "Ukloni");

    end();
}

GrupaNagrada::~GrupaNagrada() {

}