#include "GrupaOdeljenja.h"

GrupaOdeljenja::GrupaOdeljenja(int x, int y, int w, int h, KolekcijaOdeljenja *odeljenja, const char *label) 
: Fl_Group(x, y, w, h, label) {
    Tabela<Odeljenje*> *tabela = new Tabela<Odeljenje*>(x + 50, x + 50, 300, 300, odeljenja);
    id = new Fl_Input(x + 500, y + 10, 150, 30, "ID:");
    naziv = new Fl_Input(x + 500, y + 50, 150, 30, "Naziv:");
    sef = new Fl_Input(x + 500, y + 90, 150, 30, "Sef:");
    preduzece = new Fl_Int_Input(x + 500, y + 130, 150, 30, "Preduzece");
    dodajButton = new Fl_Button(x + 500, y + 180, 50, 30, "Dodaj");
    prikaziButton = new Fl_Button(x + 500, y + 230, 50, 30, "Prikazi");
    izmeniButton = new Fl_Button(x + 566, y + 180, 50, 30, "Izmeni");
    ukloniButton = new Fl_Button(x + 632, y + 180, 50, 30, "Ukloni");

    end();
}

GrupaOdeljenja::~GrupaOdeljenja() {
    
}