#include "GrupaPreduzeca.h"

GrupaPreduzeca::GrupaPreduzeca(int x, int y, int w, int h, KolekcijaPreduzeca *preduzeca, const char *label) 
: Fl_Group(x, y, w, h, label) {
    Tabela *tabela = new Tabela(x + 50, x + 50, 300, 300, preduzeca);
    naziv = new Fl_Input(x + 500, y + 10, 150, 30, "Naziv:");
    maticniBroj = new Fl_Int_Input(x + 500, y + 50, 150, 30, "Maticni broj:");
    pib = new Fl_Int_Input(x + 500, y + 90, 150, 30, "Pib:");
    dodajButton = new Fl_Button(x + 500, y + 140, 50, 30, "Dodaj");
    prikaziButton = new Fl_Button(x + 500, y + 190, 50, 30, "Prikazi");
    izmeniButton = new Fl_Button(x + 566, y + 140, 50, 30, "Izmeni");
    ukloniButton = new Fl_Button(x + 632, y + 140, 50, 30, "Ukloni");

    end();
}

GrupaPreduzeca::~GrupaPreduzeca() {

}