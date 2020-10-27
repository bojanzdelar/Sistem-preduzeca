#ifndef GRUPA_ODELJENJA_H
#define GRUPA_ODELJENJA_H

#include <FL/Fl_Input.H>
#include <FL/Fl_Int_Input.H>
#include <FL/Fl_Button.H>

#include "Tabela.h"
#include "../kolekcije/KolekcijaOdeljenja.h"

class GrupaOdeljenja : public Fl_Group {
protected:
    Tabela *tabela;
    Fl_Input *id;
    Fl_Input *naziv;
    Fl_Input *sef;
    Fl_Int_Input *preduzece;
    Fl_Button *dodaj;
    Fl_Button *izmeni;
    Fl_Button *ukloni;

public:
    GrupaOdeljenja(int x, int y, int w, int h, KolekcijaOdeljenja *odeljenja, const char *label = "Odeljenja");
    virtual ~GrupaOdeljenja();
};

#endif // GRUPA_ODELJENJA_H