#ifndef PRIKAZ_PLATA_H
#define PRIKAZ_PLATA_H

#include <sstream>

#include <FL/Fl_Widget.H>
#include <FL/fl_draw.H>

#include "../model/Preduzece.h"

using namespace std;

// Ova komponenta iscrtava pravougaonik na čijem se levom kraju nalazi ispisana minimalna plata a na desnom maksimalna plata.
// Unutar pravougaonika se nalaze dve vertikalne crte. Prva crta označava srednju vrednost plate i njena
// pozicija unutar pravougaonika je prporcionalna srednjoj vrednosti plate. Ispod ove crte je ispisana srednja
// vrednost plate. Druga crta predstavlja visinu plate posmatranog radnika, njena pozicija unutar pravougaonika
// je prporcionalna visini plate posmatranog radnika. Iznad ove crte ispisana je visina plate posmatranog radnika.
class PrikazPlata : public Fl_Widget
{
protected:
    Radnik *radnik;
    PoslovnaJedinica *poslovnaJedinica;
    virtual void draw();

public:
    PrikazPlata(int x, int y, int w, int h);
    virtual ~PrikazPlata();

    Radnik* getRadnik() const;
    void setRadnik(Radnik* radnik);
    PoslovnaJedinica* getPoslovnaJednica() const;
    void setPoslovnaJedinica(PoslovnaJedinica* poslovnaJedinica);
};

#endif // PRIKAZ_PLATA_H