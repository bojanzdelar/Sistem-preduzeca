#ifndef FORMA_ODELJENJE_H
#define FORMA_ODELJENJE_H

#include <FL/Fl_Group.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Int_Input.H>
#include <FL/Fl_Button.H>

#include "../model/Odeljenje.h"

class FormaOdeljenje : public Fl_Group {
protected:
    Fl_Input *id;
    Fl_Input *naziv;
    Fl_Input *sef;
    Fl_Int_Input *preduzece;
    Fl_Button *dodaj;
    Fl_Button *izmeni;
    Fl_Button *ukloni;

public:
    FormaOdeljenje(int x, int y, int w, int h, const char *label = "Podaci o odeljenju");
    virtual ~FormaOdeljenje();
};

#endif // FORMA_ODELJENJE_H