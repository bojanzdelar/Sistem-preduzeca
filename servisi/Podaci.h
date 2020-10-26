#ifndef PODACI_H
#define PODACI_H

#include <fstream>

#include "../kolekcije/KolekcijaPreduzeca.h"
#include "../kolekcije/KolekcijaOdeljenja.h"
#include "../kolekcije/KolekcijaRadnika.h"
#include "../kolekcije/KolekcijaNagrada.h"

void popuniPreduzeca(KolekcijaPreduzeca &kolekcijaPreduzeca, const KolekcijaOdeljenja &kolekcijaOdeljenja);

void popuniOdeljenja(KolekcijaOdeljenja &kolekcijaOdeljenja, const KolekcijaRadnika &KolekcijaRadnika);

void dodeliNadredjene(KolekcijaRadnika &kolekcijaRadnika);

void dodeliNagrade(KolekcijaRadnika &KolekcijaRadnika, const KolekcijaNagrada &kolekcijaNagrada);

void procitajPodatke(KolekcijaPreduzeca &kolekcijaPreduzeca, KolekcijaOdeljenja &kolekcijaOdeljenja,
        KolekcijaRadnika &kolekcijaRadnika, KolekcijaNagrada &kolekcijaNagrada);

void poveziPodatke(KolekcijaPreduzeca &kolekcijaPreduzeca, KolekcijaOdeljenja &kolekcijaOdeljenja,
        KolekcijaRadnika &kolekcijaRadnika, KolekcijaNagrada &kolekcijaNagrada);

void ispisiPodatke(KolekcijaPreduzeca &kolekcijaPreduzeca, KolekcijaOdeljenja &kolekcijaOdeljenja,
        KolekcijaRadnika &kolekcijaRadnika, KolekcijaNagrada &kolekcijaNagrada);

#endif // PODACI_H