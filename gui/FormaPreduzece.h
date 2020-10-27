#ifndef FORMA_PREDUZECE_H
#define FORMA_PREDUZECE_H

#include <FL/Fl_Group.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Int_Input.H>
#include <FL/Fl_Button.H>

#include "../model/Preduzece.h"

class FormaPreduzece : public Fl_Group {
private:
    Fl_Input *nazivInput;
    Fl_Int_Input *maticniBrojInput;
    Fl_Int_Input *pibInput;
    Fl_Button *dodaj;
    Fl_Button *izmeni;
    Fl_Button *ukloni;

public:
    FormaPreduzece(int x, int y, int w, int h, const char *label = "Podaci o preduzecu");
    virtual ~FormaPreduzece();
};

#endif // FORMA_PREDUZECE_H