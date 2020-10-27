#include "Podaci.h"

void popuniPreduzeca(KolekcijaPreduzeca &kolekcijaPreduzeca, const KolekcijaOdeljenja &kolekcijaOdeljenja) {
    for (Preduzece *preduzece : kolekcijaPreduzeca.getKolekcija()) {
        for (Odeljenje *odeljenje : kolekcijaOdeljenja.getKolekcija()) {
            if (preduzece->getMaticniBroj() == odeljenje->getPreduzece()->getMaticniBroj()) {
                preduzece->getOdeljenja()->push_back(odeljenje);
                odeljenje->setPreduzece(preduzece);
            }
        }
    }
}

void popuniOdeljenja(KolekcijaOdeljenja &kolekcijaOdeljenja, const KolekcijaRadnika &KolekcijaRadnika) {
    for (Odeljenje *odeljenje : kolekcijaOdeljenja.getKolekcija()) {
        for (Radnik *radnik : KolekcijaRadnika.getKolekcija()) {
            // Dodela zaposlenog odeljenju
            if (odeljenje->getId() == radnik->getOdeljenje()->getId()) {
                odeljenje->getZaposleni()->push_back(radnik);
                radnik->setOdeljenje(odeljenje);
            }
            // Dodela sefa odeljenju
            if (odeljenje->getSef()->getId() == radnik->getId()) {
                odeljenje->setSef(radnik);
            }
        }
    }
}

void dodeliNadredjene(KolekcijaRadnika &kolekcijaRadnika) {
    for (Radnik *sef : kolekcijaRadnika.getKolekcija()) {
        for (Radnik *radnik : kolekcijaRadnika.getKolekcija()) {
            if (sef->getId() == radnik->getIdNadredjeni()) {
                radnik->setNadredjeni(sef);
            }
        }
    }

}

void dodeliNagrade(KolekcijaRadnika &kolekcijaRadnika, const KolekcijaNagrada &kolekcijaNagrada) {
    for (Radnik *radnik : kolekcijaRadnika.getKolekcija()) {
        for (Nagrada *nagrada : kolekcijaNagrada.getKolekcija()) {
            if (radnik->getId() == nagrada->getRadnik()->getId()) {
                radnik->getNagrade()->push_back(nagrada);
                nagrada->setRadnik(radnik);
            }
        }
    }
}

void poveziPodatke(KolekcijaPreduzeca &kolekcijaPreduzeca, KolekcijaOdeljenja &kolekcijaOdeljenja,
         KolekcijaRadnika &kolekcijaRadnika, KolekcijaNagrada &kolekcijaNagrada) {
    popuniPreduzeca(kolekcijaPreduzeca, kolekcijaOdeljenja);
    popuniOdeljenja(kolekcijaOdeljenja, kolekcijaRadnika);
    dodeliNadredjene(kolekcijaRadnika);
    dodeliNagrade(kolekcijaRadnika, kolekcijaNagrada);
}

void procitajPodatke(KolekcijaPreduzeca &kolekcijaPreduzeca, KolekcijaOdeljenja &kolekcijaOdeljenja,
        KolekcijaRadnika &kolekcijaRadnika, KolekcijaNagrada &kolekcijaNagrada) {
    ifstream input("podaci.txt");
    input >> kolekcijaPreduzeca;
    input >> kolekcijaOdeljenja;
    input >> kolekcijaRadnika;
    input >> kolekcijaNagrada;
    input.close();
}

void ispisiPodatke(KolekcijaPreduzeca &kolekcijaPreduzeca, KolekcijaOdeljenja &kolekcijaOdeljenja,
        KolekcijaRadnika &kolekcijaRadnika, KolekcijaNagrada &kolekcijaNagrada) {
    ofstream output("test.txt"); // privremeno
    output << kolekcijaPreduzeca;
    output << kolekcijaOdeljenja;
    output << kolekcijaRadnika;
    output << kolekcijaNagrada;
    output.close();
}