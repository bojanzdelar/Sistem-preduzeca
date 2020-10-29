#ifndef GRUPE_H
#define GRUPE_H

#include "GrupaPreduzeca.h"
#include "GrupaOdeljenja.h"
#include "GrupaRadnika.h"
#include "GrupaNagrada.h"

struct Grupe {
    GrupaPreduzeca *grupaPreduzeca;
    GrupaOdeljenja *grupaOdeljenja;
    GrupaRadnika *grupaRadnika;
    GrupaNagrada *grupaNagrada;

    Grupe(GrupaPreduzeca *grupaPreduzeca, GrupaOdeljenja *grupaOdeljenja, GrupaRadnika *grupaRadnika, GrupaNagrada *grupaNagrada);

    static void azuriraj(Fl_Widget* widget, void *data);
};

#endif // GRUPE_H