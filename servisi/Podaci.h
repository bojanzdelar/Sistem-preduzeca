#ifndef PODACI_H
#define PODACI_H

#include <fstream>

#include "../kolekcije/Kolekcije.h"

void popuniPreduzeca(KolekcijaPreduzeca &kolekcijaPreduzeca, const KolekcijaOdeljenja &kolekcijaOdeljenja);

void popuniOdeljenja(KolekcijaOdeljenja &kolekcijaOdeljenja, const KolekcijaRadnika &KolekcijaRadnika);

void dodeliNadredjene(KolekcijaRadnika &kolekcijaRadnika);

void dodeliNagrade(KolekcijaRadnika &KolekcijaRadnika, const KolekcijaNagrada &kolekcijaNagrada);

void procitajPodatke(Kolekcije &kolekcije);

void poveziPodatke(Kolekcije &kolekcije);

void ispisiPodatke(Kolekcije &kolekcije);

#endif // PODACI_H