#ifndef KOLEKCIJE_H
#define KOLEKCIJE_H

#include <fstream>

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

    void popuniPreduzeca();
    void popuniOdeljenja();
    void dodeliSefove();
    void dodeliNadredjene();
    void dodeliNagrade();

    void ukloniPreduzece(Preduzece *preduzece);
    void ukloniOdeljenje(Odeljenje *odeljenje);
    void ukloniRadnika(Radnik *radnik);
    void ukloniNagradu(Nagrada *nagrada);
    void ukloniSefa(Radnik *radnik);

    void procitajPodatke();
    void poveziPodatke();
    void ispisiPodatke();

};

#endif // KOLEKCIJE_H