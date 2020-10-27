#ifndef GRUPA_NAGRADA_H
#define GRUPA_NAGRADA_H

#include <FL/Fl_Input.H>
#include <FL/Fl_Int_Input.H>
#include <FL/Fl_Button.H>

#include "Tabela.hpp"
#include "../kolekcije/KolekcijaNagrada.h"

class GrupaNagrada : public Fl_Group {
protected:
    Tabela<Nagrada*> *tabela;
    Fl_Input *radnik;
    Fl_Int_Input *procenti;
    Fl_Input *pocetak;
    Fl_Input *kraj;
    Fl_Button *dodajButton;
    Fl_Button *prikaziButton;
    Fl_Button *izmeniButton;
    Fl_Button *ukloniButton;

public:
    GrupaNagrada(int x, int y, int w, int h, KolekcijaNagrada *nagrade, const char *label = "Nagrade");
    virtual ~GrupaNagrada();
};

#endif // GRUPA_NAGRADA_H