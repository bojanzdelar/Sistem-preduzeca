#ifndef GRUPA_NAGRADA_H
#define GRUPA_NAGRADA_H

#include <FL/Fl_Input.H>
#include <FL/Fl_Int_Input.H>
#include <FL/Fl_Button.H>
#include <FL/fl_ask.H>

#include "Tabela.hpp"
#include "../kolekcije/Kolekcije.h"

class GrupaNagrada : public Fl_Group {
protected:
    Kolekcije* kolekcije;
    Tabela<Nagrada*> *tabela;
    Fl_Input *radnik;
    Fl_Int_Input *procenti;
    Fl_Int_Input *brojMeseci;
    Fl_Button *dodajButton;
    Fl_Button *prikaziButton;
    Fl_Button *izmeniButton;
    Fl_Button *ukloniButton;

    static void dodaj(Fl_Widget *widget, void *data);
    static void prikazi(Fl_Widget *widget, void *data);
    static void izmeni(Fl_Widget *widget, void *data);
    static void ukloni(Fl_Widget *widget, void *data);

public:
    GrupaNagrada(int x, int y, int w, int h, Kolekcije *kolekcije, const char *label = "Nagrade");
    virtual ~GrupaNagrada();

    void azuriraj();
};

#endif // GRUPA_NAGRADA_H