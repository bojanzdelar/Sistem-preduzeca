#ifndef GRUPA_NAGRADA_H
#define GRUPA_NAGRADA_H

#include <FL/Fl_Input.H>
#include <FL/Fl_Int_Input.H>
#include <FL/Fl_Button.H>

#include "Tabela.h"
#include "../kolekcije/KolekcijaNagrada.h"

class GrupaNagrada : public Fl_Group {
protected:
    Tabela *tabela;
    Fl_Input *radnik;
    Fl_Int_Input *procenti;
    Fl_Input *pocetak;
    Fl_Input *kraj;
    Fl_Button *dodaj;
    Fl_Button *izmeni;
    Fl_Button *ukloni;

public:
    GrupaNagrada(int x, int y, int w, int h, KolekcijaNagrada *nagrade, const char *label = "Nagrade");
    virtual ~GrupaNagrada();
};

#endif // GRUPA_NAGRADA_H