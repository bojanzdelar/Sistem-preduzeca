#include "FormaOdeljenje.h"

FormaOdeljenje::FormaOdeljenje(int x, int y, int w, int h, const char *label) 
: Fl_Group(x, y, w, h, label) {
    idInput = new Fl_Input(x + 100, y + 10, 200, 30, "ID:");
    nazivInput = new Fl_Input(x + 100, y + 50, 200, 30, "Naziv:");
    sefInput = new Fl_Input(x + 100, y + 90, 200, 30, "Sef:");
    preduzeceInput = new Fl_Input(x + 100, y + 130, 200, 30, "Preduzece");
    dodaj = new Fl_Button(x + 100, y + 180, 50, 30, "Dodaj");
    izmeni = new Fl_Button(x + 166, y + 180, 50, 30, "Izmeni");
    ukloni = new Fl_Button(x + 232, y + 180, 50, 30, "Ukloni");
}

FormaOdeljenje::~FormaOdeljenje() {

}