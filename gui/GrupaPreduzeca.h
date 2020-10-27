#ifndef GRUPA_PREDUZECE_H
#define GRUPA_PREDUZECE_H

#include <FL/Fl_Input.H>
#include <FL/Fl_Int_Input.H>
#include <FL/Fl_Button.H>

#include "Tabela.h"
#include "../kolekcije/KolekcijaPreduzeca.h"

class GrupaPreduzeca : public Fl_Group {
protected:
    Tabela *tabela;
    Fl_Input *naziv;
    Fl_Int_Input *maticniBroj;
    Fl_Int_Input *pib;
    Fl_Button *dodajButton;
    Fl_Button *izmeniButton;
    Fl_Button *ukloniButton;

public:
    GrupaPreduzeca(int x, int y, int w, int h, KolekcijaPreduzeca *preduzeca, const char *label = "Preduzeca");
    virtual ~GrupaPreduzeca();
};

#endif // GRUPA_PREUZECE_H