#ifndef KOLEKCIJE_H
#define KOLEKCIJE_H

#include "KolekcijaPreduzeca.h"
#include "KolekcijaOdeljenja.h"
#include "KolekcijaRadnika.h"
#include "KolekcijaNagrada.h"

struct Kolekcije { 
    KolekcijaPreduzeca &preduzeca;
    KolekcijaOdeljenja &odeljenja;
    KolekcijaRadnika &radnici;
    KolekcijaNagrada &nagrade;

    Kolekcije(KolekcijaPreduzeca &preduzeca, KolekcijaOdeljenja &odeljenja, KolekcijaRadnika &radnici, KolekcijaNagrada &nagrade);
};

#endif // KOLEKCIJE_H