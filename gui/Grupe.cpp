#include "Grupe.h"

Grupe::Grupe(GrupaPreduzeca *grupaPreduzeca, GrupaOdeljenja *grupaOdeljenja, GrupaRadnika *grupaRadnika, GrupaNagrada *grupaNagrada)
: grupaPreduzeca(grupaPreduzeca), grupaOdeljenja(grupaOdeljenja), grupaRadnika(grupaRadnika), grupaNagrada(grupaNagrada) {
    
}

void Grupe::azuriraj(Fl_Widget *widget, void *data) {
    Grupe *grupe = (Grupe*) data;
    grupe->grupaPreduzeca->azuriraj();
    grupe->grupaOdeljenja->azuriraj();
    grupe->grupaRadnika->azuriraj();
    grupe->grupaNagrada->azuriraj();
}