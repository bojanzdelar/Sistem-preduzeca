#ifndef GRUPA_ODELJENJA_H
#define GRUPA_ODELJENJA_H

#include <FL/Fl_Input.H>
#include <FL/Fl_Int_Input.H>
#include <FL/Fl_Button.H>

#include "Tabela.hpp"
#include "../kolekcije/Kolekcije.h"

class GrupaOdeljenja : public Fl_Group {
protected:
    Kolekcije *kolekcije;
    Tabela<Odeljenje*> *tabela;
    Fl_Input *id;
    Fl_Input *naziv;
    Fl_Input *sef;
    Fl_Int_Input *preduzece;
    Fl_Button *dodajButton;
    Fl_Button *prikaziButton;
    Fl_Button *izmeniButton;
    Fl_Button *ukloniButton;

    static void dodaj(Fl_Widget *widget, void *data);
    static void prikazi(Fl_Widget *widget, void *data);
    static void izmeni(Fl_Widget *widget, void *data);
    static void ukloni(Fl_Widget *widget, void *data);

public:
    GrupaOdeljenja(int x, int y, int w, int h, Kolekcije *kolekcije, const char *label = "Odeljenja");
    virtual ~GrupaOdeljenja();
};

#endif // GRUPA_ODELJENJA_H