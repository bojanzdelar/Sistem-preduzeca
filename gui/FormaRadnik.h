#ifndef FORMA_RADNIK_H
#define FORMA_RADNIK_H

#include <FL/Fl_Group.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Float_Input.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Button.H>

#include "../model/Radnik.h"

const int MAX_REVIZIJE = 5;
const int MAX_KONTAKTI = 5;

class FormaRadnik : public Fl_Group {
protected:
    Fl_Input *id;
    Fl_Input *ime;
    Fl_Input *prezime;
    Fl_Float_Input *plata;
    Fl_Input *odeljenje;
    Fl_Input *nadredjeni;
    Fl_Choice *posao;

    // Racunovodja
    Fl_Input *izdavacLicence;
    Fl_Float_Input *maksimalniPrihod;
    // Revizor
    Fl_Choice *brojRevizija;
    Fl_Input *revizije[MAX_REVIZIJE];
    // Komercijalista
    Fl_Choice *brojPoslovnihKontakta;
    Fl_Input *kontakti[MAX_KONTAKTI];
    
    Fl_Button *dodaj;
    Fl_Button *izmeni;
    Fl_Button *ukloni;
    
    static void promeniPosao(Fl_Widget *widget, void *data);
    static void promeniBrojRevizija(Fl_Widget *widget, void *data);
    static void promeniBrojKontakta(Fl_Widget *widget, void *data);

public:
    FormaRadnik(int x, int y, int w, int h, const char *label = "Podaci o radniku");
    virtual ~FormaRadnik();
};

#endif // FORMA_RADNIK_H