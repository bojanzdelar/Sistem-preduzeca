#include "FormaNagrada.h"

FormaNagrada::FormaNagrada(int x, int y, int w, int h, const char *label) 
: Fl_Group(x, y, w, h, label) {
    radnik = new Fl_Input(x + 100, y + 10, 150, 30, "Radnik:");
    procenti = new Fl_Int_Input(x + 100, y + 50, 150, 30, "Procenti:");
    pocetak = new Fl_Input(x + 100, y + 90, 150, 30, "Datum pocetka\n(dd-mm-gggg):");
    kraj = new Fl_Int_Input(x + 100, y + 130, 150, 30, "Datum kraja\n(dd-mm-gggg)");
    dodaj = new Fl_Button(x + 100, y + 180, 50, 30, "Dodaj");
    izmeni = new Fl_Button(x + 166, y + 180, 50, 30, "Izmeni");
    ukloni = new Fl_Button(x + 232, y + 180, 50, 30, "Ukloni");
}

FormaNagrada::~FormaNagrada() {

}