#include "FormaOdeljenje.h"

FormaOdeljenje::FormaOdeljenje(int x, int y, int w, int h, const char *label) 
: Fl_Group(x, y, w, h, label) {
    id = new Fl_Input(x + 100, y + 10, 150, 30, "ID:");
    naziv = new Fl_Input(x + 100, y + 50, 150, 30, "Naziv:");
    sef = new Fl_Input(x + 100, y + 90, 150, 30, "Sef:");
    preduzece = new Fl_Int_Input(x + 100, y + 130, 150, 30, "Preduzece");
    dodaj = new Fl_Button(x + 100, y + 180, 50, 30, "Dodaj");
    izmeni = new Fl_Button(x + 166, y + 180, 50, 30, "Izmeni");
    ukloni = new Fl_Button(x + 232, y + 180, 50, 30, "Ukloni");
}

FormaOdeljenje::~FormaOdeljenje() {

}