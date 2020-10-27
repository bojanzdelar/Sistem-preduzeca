#include "GrupaNagrada.h"

GrupaNagrada::GrupaNagrada(int x, int y, int w, int h, KolekcijaNagrada *nagrade, const char *label) 
: Fl_Group(x, y, w, h, label) {
    Tabela *tabela = new Tabela(x + 50, x + 50, 300, 300, nagrade);
    radnik = new Fl_Input(x + 500, y + 10, 150, 30, "Radnik:");
    procenti = new Fl_Int_Input(x + 500, y + 50, 150, 30, "Procenti:");
    pocetak = new Fl_Input(x + 500, y + 90, 150, 30, "Datum pocetka\n(dd-mm-gggg):");
    kraj = new Fl_Int_Input(x + 500, y + 130, 150, 30, "Datum kraja\n(dd-mm-gggg)");
    dodajButton = new Fl_Button(x + 500, y + 180, 50, 30, "Dodaj");
    prikaziButton = new Fl_Button(x + 500, y + 230, 50, 30, "Prikazi");
    izmeniButton = new Fl_Button(x + 566, y + 180, 50, 30, "Izmeni");
    ukloniButton = new Fl_Button(x + 632, y + 180, 50, 30, "Ukloni");

    end();
}

GrupaNagrada::~GrupaNagrada() {

}