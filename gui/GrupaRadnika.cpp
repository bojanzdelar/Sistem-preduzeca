#include "GrupaRadnika.h"

GrupaRadnika::GrupaRadnika(int x, int y, int w, int h, Kolekcije *kolekcije, const char *label) 
: Fl_Group(x, y, w, h, label), kolekcije(kolekcije) {
    tabela = new Tabela<Radnik*>(x + 10, y + 10, 700, 415, &kolekcije->radnici);
    id = new Fl_Input(x + 800, y + 10, 150, 30, "ID:");
    ime = new Fl_Input(x + 800, y + 50, 150, 30, "Ime:");
    prezime = new Fl_Input(x + 800, y + 90, 150, 30, "Prezime:");
    plata = new Fl_Float_Input(x + 800, y + 130, 150, 30, "Plata");
    plata->maximum_size(9);
    odeljenje = new Fl_Input(x + 800, y + 170, 150, 30, "Odeljenje:");
    nadredjeni = new Fl_Input(x + 800, y + 210, 150, 30, "Nadredjeni:");
    posao = new Fl_Choice(x + 1035, y + 10, 150, 30, "Posao");
    posao->add("Racunovodja|Revizor|Komercijalista");
    posao->value(0);
    posao->callback(promeniPosao, this);

    // Racunovodja
    izdavacLicence = new Fl_Input(x + 1035, y + 50, 150, 30, "Izdavac\nlicence:");
    maksimalniPrihod = new Fl_Float_Input(x + 1035, y + 90, 150, 30, "Maksimalni\nprihod");
    maksimalniPrihod->maximum_size(9);

    // Revizor
    brojRevizija = new Fl_Choice(x + 1035, y + 50, 150, 30, "Broj\nrevizija");
    brojRevizija->add("0");
    for (int i = 0; i < MAX_REVIZIJE; i++) {
        brojRevizija->add(to_string(i+1).c_str());
        revizije[i] = new Fl_Input(x + 1035, y + 90 + i * 40, 150, 30, "Revizija:");
    }
    brojRevizija->value(0);
    brojRevizija->callback(promeniBrojRevizija, this);

    // Komercijalista
    brojPoslovnihKontakta = new Fl_Choice(x + 1035, y + 50, 150, 30, "Broj\nkontakta");
    brojPoslovnihKontakta->add("0");
    for (int i = 0; i < MAX_KONTAKTI; i++) {
        brojPoslovnihKontakta->add(to_string(i+1).c_str());
        kontakti[i] = new Fl_Input(x + 1035, y + 90 + i * 40, 150, 30, "Poslovni\nkontakt:");
    }
    brojPoslovnihKontakta->value(0);
    brojPoslovnihKontakta->callback(promeniBrojKontakta, this);

    dodajButton = new Fl_Button(x + 750, y + 260, 80, 40, "Dodaj");
    dodajButton->callback(dodaj, this);
    prikaziButton = new Fl_Button(x + 840, y + 260, 80, 40, "Prikazi");
    prikaziButton->callback(prikazi, this);
    izmeniButton = new Fl_Button(x + 930, y + 260, 80, 40, "Izmeni");
    izmeniButton->callback(izmeni, this);
    ukloniButton = new Fl_Button(x + 1020, y + 260, 80, 40, "Ukloni");
    ukloniButton->callback(ukloni, this);

    plateOdeljenje = new PrikazPlata(x + 750, y + 370, 150, 30, "Odeljenje");
    platePreduzece = new PrikazPlata(x + 975, y + 370, 150, 30, "Preduzece");

    posao->do_callback();
    end();
}

GrupaRadnika::~GrupaRadnika() {

}

void GrupaRadnika::promeniPosao(Fl_Widget *widget, void *data) {
    GrupaRadnika *grupa = (GrupaRadnika*) data;
    // sakrij sve komponenente specificne za odredjeni posao
    grupa->izdavacLicence->hide();
    grupa->maksimalniPrihod->hide();
    grupa->brojRevizija->hide();
    for (int i = 0; i < MAX_REVIZIJE; i++) {
        grupa->revizije[i]->hide();
    }
    grupa->brojPoslovnihKontakta->hide();
    for (int i = 0; i < MAX_KONTAKTI; i++) {
        grupa->kontakti[i]->hide();
    }
    // prikazi komponente specificne za izabrani posao
    if (grupa->posao->value() == 0) {
        grupa->izdavacLicence->show();
        grupa->maksimalniPrihod->show();
    }
    else if (grupa->posao->value() == 1) {
        grupa->brojRevizija->show();
        grupa->brojRevizija->do_callback();
    }
    else if (grupa->posao->value() == 2) {
        grupa->brojPoslovnihKontakta->show();
        grupa->brojPoslovnihKontakta->do_callback();
    }
}

void GrupaRadnika::promeniBrojRevizija(Fl_Widget *widget, void *data) {
    GrupaRadnika *grupa = (GrupaRadnika*) data;
    int brojRevizija = grupa->brojRevizija->value();
    for (int i = 0; i < brojRevizija; i++) {
        grupa->revizije[i]->show();
    }
    for (int i = brojRevizija; i < MAX_REVIZIJE; i++) {
        grupa->revizije[i]->hide();
    }
}

void GrupaRadnika::promeniBrojKontakta(Fl_Widget *widget, void *data) {
    GrupaRadnika *grupa = (GrupaRadnika*) data;
    int brojKontakta = grupa->brojPoslovnihKontakta->value();
    for (int i = 0; i < brojKontakta; i++) {
        grupa->kontakti[i]->show();
    }
    for (int i = brojKontakta; i < MAX_KONTAKTI; i++) {
        grupa->kontakti[i]->hide();
    }
}

void GrupaRadnika::dodaj(Fl_Widget *widget, void *data) {
    GrupaRadnika *grupa = (GrupaRadnika*) data;

    // Zajednicko za sve radnike
    string id = grupa->id->value();
    string ime = grupa->ime->value();
    string prezime = grupa->prezime->value();
    string plata = grupa->plata->value();
    string odeljenjeId = grupa->odeljenje->value();
    string nadredjeniId = grupa->nadredjeni->value();
    if (id == "" || ime == "" || prezime == "" || plata == "" || odeljenjeId == "" || nadredjeniId == "" 
            || plata.find("-") != string::npos || !grupa->kolekcije->odeljenja.idZauzet(odeljenjeId)
            || (!grupa->kolekcije->radnici.idZauzet(nadredjeniId) && id != nadredjeniId)) {
        fl_alert("Niste ispunili zahteve za izvrsavanje funkcije");
        return;
    }
    Radnik *radnik = nullptr;
    Odeljenje *odeljenje = grupa->kolekcije->odeljenja.dobaviId(odeljenjeId);

    int posao = grupa->posao->value();
    // Racunovodja
    if (posao == 0) {
        string izdavacLicence = grupa->izdavacLicence->value();
        string maksimalniPrihod = grupa->maksimalniPrihod->value();
        if (izdavacLicence == "" || maksimalniPrihod == "" || maksimalniPrihod.find("-") != string::npos) {
            fl_alert("Niste ispunili zahteve za izvrsavanje funkcije");
            return;
        }
        radnik = new Racunovodja(id, ime, prezime, stod(plata), odeljenje, nullptr, izdavacLicence, stod(maksimalniPrihod));
    }
    // Revizor
    else if (posao == 1) {
        int brojRevizija = grupa->brojRevizija->value();
        vector<string> revizije;
        for (int i = 0; i < brojRevizija; i++) {
            string revizija = grupa->revizije[i]->value();
            if (revizija != "") {
                revizije.push_back(revizija);
            }
        }
        if (brojRevizija != revizije.size()) {
            fl_alert("Niste ispunili zahteve za izvrsavanje funkcije");
            return;
        }
        radnik = new Revizor(id, ime, prezime, stod(plata), odeljenje, nullptr, revizije);
    }
    // Komercijalista
    else if (posao == 2) {
        int brojPoslovnihKontakta = grupa->brojPoslovnihKontakta->value();
        vector<string> kontakti;
        for (int i = 0; i < brojPoslovnihKontakta; i++) {
            string kontakt = grupa->kontakti[i]->value();
            if (kontakt != "") {
                kontakti.push_back(kontakt);
            }
        }
        if (brojPoslovnihKontakta != kontakti.size()) {
            fl_alert("Niste ispunili zahteve za izvrsavanje funkcije");
            return;
        }
        radnik = new Komercijalista(id, ime, prezime, stod(plata), odeljenje, nullptr, kontakti);
    }
    // moralo je naknadno da se postavi da se ispravi bug
    radnik->setNadredjeni((id == nadredjeniId) ? radnik : grupa->kolekcije->radnici.dobaviId(nadredjeniId)); 
    grupa->kolekcije->radnici.dodaj(radnik);
    odeljenje->zaposli(radnik);
    grupa->azuriraj();
}

void GrupaRadnika::prikazi(Fl_Widget *widget, void *data) {
    // Zajednicko za sve radnike
    GrupaRadnika *grupa = (GrupaRadnika*) data;
    int red = grupa->tabela->izabraniRed();
    if (red == -1) {
        fl_alert("Niste ispunili zahteve za izvrsavanje funkcije");
        return;
    }
    Radnik *radnik = grupa->kolekcije->radnici.dobavi(red);
    grupa->id->value(radnik->getId().c_str());
    grupa->ime->value(radnik->getIme().c_str());
    grupa->prezime->value(radnik->getPrezime().c_str());
    ostringstream out;
    out.precision(2);
    out << fixed << radnik->getPlata();
    grupa->plata->value(out.str().c_str());
    grupa->odeljenje->value(radnik->getOdeljenje()->getId().c_str());
    grupa->nadredjeni->value(radnik->getNadredjeni()->getId().c_str());
    // Speicificno po zanimanju
    string posao = radnik->getPosao();
    if (posao == "racunovodja") {
        grupa->posao->value(0);
        Racunovodja *racunovodja = (Racunovodja*) radnik;
        grupa->izdavacLicence->value(racunovodja->getIzdavacLicence().c_str());
        out.str("");
        out << racunovodja->getMaksimalniPrihod();
        grupa->maksimalniPrihod->value(out.str().c_str());
    }
    else if (posao == "revizor") {
        grupa->posao->value(1);
        Revizor *revizor = (Revizor*) radnik;
        vector<string> revizije = revizor->getRevizije();
        int brojRevizija = revizije.size();
        grupa->brojRevizija->value(brojRevizija);
        for (int i = 0; i < brojRevizija; i++) {
            grupa->revizije[i]->value(revizije[i].c_str());
        }
    }
    else if (posao == "komercijalista") {
        grupa->posao->value(2);
        Komercijalista *komercijalista = (Komercijalista*) radnik;
        vector<string> kontakti = komercijalista->getPoslovniKontakti();
        int brojKontakta = kontakti.size();
        grupa->brojPoslovnihKontakta->value(brojKontakta);
        for (int i = 0; i < brojKontakta; i++) {
            grupa->kontakti[i]->value(kontakti[i].c_str());
        }
    }
    grupa->posao->do_callback();
    grupa->azuriraj();
    grupa->plateOdeljenje->azuriraj(radnik, radnik->getOdeljenje());
    grupa->platePreduzece->azuriraj(radnik, radnik->getOdeljenje()->getPreduzece());
}

void GrupaRadnika::izmeni(Fl_Widget *widget, void *data) {
    GrupaRadnika *grupa = (GrupaRadnika*) data;

    // Zajednicko za sve radnike
    string id = grupa->id->value();
    string ime = grupa->ime->value();
    string prezime = grupa->prezime->value();
    string plata = grupa->plata->value();
    string odeljenjeId = grupa->odeljenje->value();
    string nadredjeniId = grupa->nadredjeni->value();
    int red = grupa->tabela->izabraniRed();
    if (id == "" || ime == "" || prezime == "" || plata == "" || odeljenjeId == "" || nadredjeniId == ""  || plata.find("-") != string::npos 
            || (!grupa->kolekcije->radnici.idZauzet(nadredjeniId) && id != nadredjeniId)
            || red == -1 || (id != grupa->kolekcije->radnici.dobavi(red)->getId() && grupa->kolekcije->radnici.idZauzet(id))) {
        fl_alert("Niste ispunili zahteve za izvrsavanje funkcije");
        return;
    }
    Radnik *radnik = grupa->kolekcije->radnici.dobavi(red);
    bool sebiNadredjen = (radnik->getId() == radnik->getNadredjeni()->getId());

    int posao = grupa->posao->value();
    // Racunovodja
    if (posao == 0) {
        string izdavacLicence = grupa->izdavacLicence->value();
        string maksimalniPrihod = grupa->maksimalniPrihod->value();
        if (izdavacLicence == "" || maksimalniPrihod == "" || maksimalniPrihod.find("-") != string::npos || radnik->getPosao() != "racunovodja") {
            fl_alert("Niste ispunili zahteve za izvrsavanje funkcije");
            return;
        }
        radnik->getOdeljenje()->otkaz(radnik);
        Racunovodja *racunovodja = (Racunovodja*) radnik;
        racunovodja->setIzdavacLicence(izdavacLicence);
        racunovodja->setMaksimalniPrihod(stod(maksimalniPrihod));
    }
    // Revizor
    else if (posao == 1) {
        int brojRevizija = grupa->brojRevizija->value();
        vector<string> revizije;
        for (int i = 0; i < brojRevizija; i++) {
            string revizija = grupa->revizije[i]->value();
            if (revizija != "") {
                revizije.push_back(revizija);
            }
        }
        if (brojRevizija != revizije.size() || radnik->getPosao() != "revizor") {
            fl_alert("Niste ispunili zahteve za izvrsavanje funkcije");
            return;
        }
        radnik->getOdeljenje()->otkaz(radnik);
        Revizor *revizor = (Revizor*) radnik;
        revizor->setRevizije(revizije);
    }
    // Komercijalista
    else if (posao == 2) {
        int brojPoslovnihKontakta = grupa->brojPoslovnihKontakta->value();
        vector<string> kontakti;
        for (int i = 0; i < brojPoslovnihKontakta; i++) {
            string kontakt = grupa->kontakti[i]->value();
            if (kontakt != "") {
                kontakti.push_back(kontakt);
            }
        }
        if (brojPoslovnihKontakta != kontakti.size() || radnik->getPosao() != "komercijalista") {
            fl_alert("Niste ispunili zahteve za izvrsavanje funkcije");
            return;
        }
        radnik->getOdeljenje()->otkaz(radnik);
        Komercijalista *komercijalista = (Komercijalista*) radnik;
        komercijalista->setPoslovniKontakti(kontakti);
    }
    radnik->setId(id);
    radnik->setIme(ime);
    radnik->setPrezime(prezime);
    radnik->setPlata(stod(plata));
    radnik->setOdeljenje(grupa->kolekcije->odeljenja.dobaviId(odeljenjeId));
    radnik->getOdeljenje()->zaposli(radnik);
    radnik->setNadredjeni((sebiNadredjen) ? radnik : grupa->kolekcije->radnici.dobaviId(nadredjeniId));
    grupa->azuriraj();
}

void GrupaRadnika::ukloni(Fl_Widget *widget, void *data) {
    GrupaRadnika *grupa = (GrupaRadnika*) data;
    int red = grupa->tabela->izabraniRed();
    if (red == -1) {
        fl_alert("Niste ispunili zahteve za izvrsavanje funkcije");
        return;
    }
    Radnik *radnik = grupa->kolekcije->radnici.dobavi(red);
    grupa->kolekcije->ukloniRadnika(radnik);
    grupa->kolekcije->ukloniSefa(radnik);
    delete radnik;
    grupa->kolekcije->dodeliNadredjene();
    grupa->azuriraj();
}

void GrupaRadnika::azuriraj() {
    tabela->azuriraj();
    plateOdeljenje->setRadnik(nullptr);
    plateOdeljenje->setPoslovnaJedinica(nullptr);
    plateOdeljenje->redraw();
    platePreduzece->setRadnik(nullptr);
    platePreduzece->setPoslovnaJedinica(nullptr);
    platePreduzece->redraw();
}