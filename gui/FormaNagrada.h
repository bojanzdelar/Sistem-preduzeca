#ifndef FORMA_NAGRADA_H
#define FORMA_NAGRADA_H

#include <FL/Fl_Group.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Int_Input.H>
#include <FL/Fl_Button.H>

#include "../model/Nagrada.h"

class FormaNagrada : public Fl_Group {
protected:
    Fl_Input *radnik;
    Fl_Int_Input *procenti;
    Fl_Input *pocetak;
    Fl_Input *kraj;
    Fl_Button *dodaj;
    Fl_Button *izmeni;
    Fl_Button *ukloni;

public:
    FormaNagrada(int x, int y, int w, int h, const char *label = "Podaci o nagradi");
    virtual ~FormaNagrada();
};

#endif // FORMA_NAGARADA_H