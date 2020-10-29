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
            Radnik *sef = odeljenje->getSef();
            if (sef == nullptr) {
                continue;
            }
            else if (sef->getId() == radnik->getId()) {
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

void poveziPodatke(Kolekcije &kolekcije) {
    popuniPreduzeca(kolekcije.preduzeca, kolekcije.odeljenja);
    popuniOdeljenja(kolekcije.odeljenja, kolekcije.radnici);
    dodeliNadredjene(kolekcije.radnici);
    dodeliNagrade(kolekcije.radnici, kolekcije.nagrade);
}

void procitajPodatke(Kolekcije &kolekcije) {
    ifstream input("podaci.txt");
    input >> kolekcije.preduzeca;
    input >> kolekcije.odeljenja;
    input >> kolekcije.radnici;
    input >> kolekcije.nagrade;
    input.close();
}

void ispisiPodatke(Kolekcije &kolekcije) {
    ofstream output("podaci.txt");
    output << kolekcije.preduzeca;
    output << kolekcije.odeljenja;
    output << kolekcije.radnici;
    output << kolekcije.nagrade;
    output.close();
}