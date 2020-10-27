#include "FormaPreduzece.h"

FormaPreduzece::FormaPreduzece(int x, int y, int w, int h, const char *label) 
: Fl_Group(x, y, w, h, label) {
    naziv = new Fl_Input(x + 100, y + 10, 150, 30, "Naziv:");
    maticniBroj = new Fl_Int_Input(x + 100, y + 50, 150, 30, "Maticni broj:");
    pib = new Fl_Int_Input(x + 100, y + 90, 150, 30, "Pib:");
    dodaj = new Fl_Button(x + 100, y + 140, 50, 30, "Dodaj");
    izmeni = new Fl_Button(x + 166, y + 140, 50, 30, "Izmeni");
    ukloni = new Fl_Button(x + 232, y + 140, 50, 30, "Ukloni");
}

FormaPreduzece::~FormaPreduzece() {

}