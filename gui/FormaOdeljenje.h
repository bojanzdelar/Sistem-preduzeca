#ifndef FORMA_ODELJENJE_H
#define FORMA_ODELJENJE_H

#include <FL/Fl_Group.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Int_Input.H>
#include <FL/Fl_Button.H>

#include "../model/Odeljenje.h"

class FormaOdeljenje : public Fl_Group {
private:
    Fl_Input *idInput;
    Fl_Input *nazivInput;
    Fl_Input *sefInput;
    Fl_Input *preduzeceInput;
    Fl_Button *dodaj;
    Fl_Button *izmeni;
    Fl_Button *ukloni;

public:
    FormaOdeljenje(int x, int y, int w, int h, const char *label = "Podaci o odeljenju");
    virtual ~FormaOdeljenje();
};

#endif // FORMA_ODELJENJE_H