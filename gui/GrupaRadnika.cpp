#include "GrupaRadnika.h"

GrupaRadnika::GrupaRadnika(int x, int y, int w, int h, Kolekcije *kolekcije, const char *label) 
: Fl_Group(x, y, w, h, label), kolekcije(kolekcije) {
    tabela = new Tabela<Radnik*>(x + 50, y + 50, 300, 300, &kolekcije->radnici);
    id = new Fl_Input(x + 500, y + 10, 150, 30, "ID:");
    ime = new Fl_Input(x + 500, y + 50, 150, 30, "Ime:");
    prezime = new Fl_Input(x + 500, y + 90, 150, 30, "Prezime:");
    plata = new Fl_Float_Input(x + 500, y + 130, 150, 30, "Plata");
    plata->maximum_size(9);
    odeljenje = new Fl_Input(x + 500, y + 170, 150, 30, "Odeljenje");
    nadredjeni = new Fl_Input(x + 500, y + 210, 150, 30, "Nadredjeni");
    posao = new Fl_Choice(x + 820, y + 10, 150, 30, "Posao");
    posao->add("Racunovodja|Revizor|Komercijalista");
    posao->value(0);
    posao->callback(promeniPosao, this);

    // Racunovodja
    izdavacLicence = new Fl_Input(x + 820, y + 50, 150, 30, "Izdavac licence:");
    maksimalniPrihod = new Fl_Float_Input(x + 820, y + 90, 150, 30, "Maksimalni prihod");
    maksimalniPrihod->maximum_size(9);

    // Revizor
    brojRevizija = new Fl_Choice(x + 820, y + 50, 150, 30, "Broj revizija");
    brojRevizija->add("0");
    for (int i = 0; i < MAX_REVIZIJE; i++) {
        brojRevizija->add(to_string(i+1).c_str());
        revizije[i] = new Fl_Input(x + 820, y + 90 + i * 40, 150, 30, "Revizija:");
    }
    brojRevizija->value(0);
    brojRevizija->callback(promeniBrojRevizija, this);

    // Komercijalista
    brojPoslovnihKontakta = new Fl_Choice(x + 820, y + 50, 150, 30, "Broj poslovnih\nkontakta");
    brojPoslovnihKontakta->add("0");
    for (int i = 0; i < MAX_KONTAKTI; i++) {
        brojPoslovnihKontakta->add(to_string(i+1).c_str());
        kontakti[i] = new Fl_Input(x + 820, y + 90 + i * 40, 150, 30, "Kontakt:");
    }
    brojPoslovnihKontakta->value(0);
    brojPoslovnihKontakta->callback(promeniBrojKontakta, this);

    dodajButton = new Fl_Button(x + 500, y + 250, 50, 30, "Dodaj");
    dodajButton->callback(dodaj, this);
    prikaziButton = new Fl_Button(x + 500, y + 280, 50, 30, "Prikazi");
    prikaziButton->callback(prikazi, this);
    izmeniButton = new Fl_Button(x + 566, y + 250, 50, 30, "Izmeni");
    izmeniButton->callback(izmeni, this);
    ukloniButton = new Fl_Button(x + 632, y + 250, 50, 30, "Ukloni");
    ukloniButton->callback(ukloni, this);

    plateOdeljenje = new PrikazPlata(x + 500, y + 340, 200, 30);
    platePreduzece = new PrikazPlata(x + 800, y + 340, 200, 30);

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
        return;
    }
    Radnik *radnik = nullptr;
    Radnik *nadredjeni = (id == nadredjeniId) ? radnik : grupa->kolekcije->radnici.dobaviId(nadredjeniId);
    Odeljenje *odeljenje = grupa->kolekcije->odeljenja.dobaviId(odeljenjeId);

    int posao = grupa->posao->value();
    // Racunovodja
    if (posao == 0) {
        string izdavacLicence = grupa->izdavacLicence->value();
        string maksimalniPrihod = grupa->maksimalniPrihod->value();
        if (izdavacLicence == "" || maksimalniPrihod == "" || maksimalniPrihod.find("-") != string::npos) {
            return;
        }
        radnik = new Racunovodja(id, ime, prezime, stod(plata), odeljenje, nadredjeni, izdavacLicence, stod(maksimalniPrihod));
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
            return;
        }
        radnik = new Revizor(id, ime, prezime, stod(plata), odeljenje, nadredjeni, revizije);
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
            return;
        }
        radnik = new Komercijalista(id, ime, prezime, stod(plata), odeljenje, nadredjeni, kontakti);
    }
    grupa->kolekcije->radnici.dodaj(radnik);
    odeljenje->zaposli(radnik);
    grupa->azuriraj();
}

void GrupaRadnika::prikazi(Fl_Widget *widget, void *data) {
    // Zajednicko za sve radnike
    GrupaRadnika *grupa = (GrupaRadnika*) data;
    int red = grupa->tabela->izabraniRed();
    if (red == -1) {
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
    if (id == "" || ime == "" || prezime == "" || plata == "" || odeljenjeId == "" || nadredjeniId == ""  
            || plata.find("-") != string::npos || (!grupa->kolekcije->radnici.idZauzet(nadredjeniId) && id != nadredjeniId)
            || red == -1 || id != grupa->kolekcije->radnici.dobavi(red)->getId()) {
        return;
    }
    Radnik *radnik = grupa->kolekcije->radnici.dobavi(red);

    int posao = grupa->posao->value();
    // Racunovodja
    if (posao == 0) {
        string izdavacLicence = grupa->izdavacLicence->value();
        string maksimalniPrihod = grupa->maksimalniPrihod->value();
        if (izdavacLicence == "" || maksimalniPrihod == "" || maksimalniPrihod.find("-") != string::npos) {
            return;
        }
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
        if (brojRevizija != revizije.size()) {
            return;
        }
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
        if (brojPoslovnihKontakta != kontakti.size()) {
            return;
        }
        Komercijalista *komercijalista = (Komercijalista*) radnik;
        komercijalista->setPoslovniKontakti(kontakti);
    }
    radnik->setIme(ime);
    radnik->setPrezime(prezime);
    radnik->setPlata(stod(plata));
    radnik->getOdeljenje()->otkaz(radnik);
    radnik->setOdeljenje(grupa->kolekcije->odeljenja.dobaviId(odeljenjeId));
    radnik->getOdeljenje()->zaposli(radnik);
    radnik->setNadredjeni((id == nadredjeniId) ? radnik : grupa->kolekcije->radnici.dobaviId(nadredjeniId));
    grupa->azuriraj();
}

void GrupaRadnika::ukloni(Fl_Widget *widget, void *data) {
    GrupaRadnika *grupa = (GrupaRadnika*) data;
    int red = grupa->tabela->izabraniRed();
    if (red == -1) {
         return;
    }
    Radnik *radnik = grupa->kolekcije->radnici.dobavi(red);
    grupa->kolekcije->ukloniRadnika(radnik);
    delete radnik;
    grupa->azuriraj();
}

void GrupaRadnika::azuriraj() {
    tabela->azuriraj();
    plateOdeljenje->setRadnik(nullptr);
    plateOdeljenje->redraw();
    platePreduzece->setPoslovnaJedinica(nullptr);
    platePreduzece->redraw();
}