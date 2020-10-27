#include "FormaNagrada.h"

FormaNagrada::FormaNagrada(int x, int y, int w, int h, const char *label) 
: Fl_Group(x, y, w, h, label) {
    radnikInput = new Fl_Input(x + 100, y + 10, 200, 30, "Radnik:");
    procentiInput = new Fl_Int_Input(x + 100, y + 50, 200, 30, "Procenti:");
    pocetakInput = new Fl_Input(x + 100, y + 90, 200, 30, "Datum pocetka\n(dd-mm-gggg):");
    krajInput = new Fl_Int_Input(x + 100, y + 130, 200, 30, "Datum kraja\n(dd-mm-gggg)");
    dodaj = new Fl_Button(x + 100, y + 180, 50, 30, "Dodaj");
    izmeni = new Fl_Button(x + 166, y + 180, 50, 30, "Izmeni");
    ukloni = new Fl_Button(x + 232, y + 180, 50, 30, "Ukloni");
}

FormaNagrada::~FormaNagrada() {

}