#ifndef GRUPA_PREDUZECE_H
#define GRUPA_PREDUZECE_H

#include <FL/Fl_Input.H>
#include <FL/Fl_Int_Input.H>
#include <FL/Fl_Button.H>

#include "Tabela.hpp"
#include "../kolekcije/KolekcijaPreduzeca.h"

class GrupaPreduzeca : public Fl_Group {
protected:
    Tabela<Preduzece*> *tabela;
    Fl_Input *naziv;
    Fl_Int_Input *maticniBroj;
    Fl_Int_Input *pib;
    Fl_Button *dodajButton;
    Fl_Button *prikaziButton;
    Fl_Button *izmeniButton;
    Fl_Button *ukloniButton;

    static void dodaj(Fl_Widget *widget, void *data);
    static void prikazi(Fl_Widget *widget, void *data);
    static void izmeni(Fl_Widget *widget, void *data);
    static void ukloni(Fl_Widget *widget, void *data);

public:
    GrupaPreduzeca(int x, int y, int w, int h, KolekcijaPreduzeca *preduzeca, const char *label = "Preduzeca");
    virtual ~GrupaPreduzeca();
};

#endif // GRUPA_PREUZECE_H