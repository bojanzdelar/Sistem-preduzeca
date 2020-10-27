#include "FormaRadnik.h"

FormaRadnik::FormaRadnik(int x, int y, int w, int h, const char *label) 
: Fl_Group(x, y, w, h, label) {
    id = new Fl_Input(x + 100, y + 10, 150, 30, "ID:");
    ime = new Fl_Input(x + 100, y + 50, 150, 30, "Ime:");
    prezime = new Fl_Input(x + 100, y + 90, 150, 30, "Prezime:");
    plata = new Fl_Float_Input(x + 100, y + 130, 150, 30, "Plata");
    odeljenje = new Fl_Input(x + 100, y + 170, 150, 30, "Odeljenje");
    nadredjeni = new Fl_Input(x + 100, y + 210, 150, 30, "Nadredjeni");
    posao = new Fl_Choice(x + 420, y + 10, 150, 30, "Posao");
    posao->add("Racunovodja|Revizor|Komercijalista");
    posao->value(0);
    posao->callback(promeniPosao, this);

    // Racunovodja
    izdavacLicence = new Fl_Input(x + 420, y + 50, 150, 30, "Izdavac licence:");
    maksimalniPrihod = new Fl_Float_Input(x + 420, y + 90, 150, 30, "Maksimalni prihod");

    // Revizor
    brojRevizija = new Fl_Choice(x + 420, y + 50, 150, 30, "Broj revizija");
    brojRevizija->add("0");
    for (int i = 0; i < MAX_REVIZIJE; i++) {
        brojRevizija->add(to_string(i+1).c_str());
        revizije[i] = new Fl_Input(x + 420, y + 90 + i * 40, 150, 30, "Revizija:");
    }
    brojRevizija->value(0);
    brojRevizija->callback(promeniBrojRevizija, this);

    // Komercijalista
    brojPoslovnihKontakta = new Fl_Choice(x + 420, y + 50, 150, 30, "Broj poslovnih\nkontakta");
    brojPoslovnihKontakta->add("0");
    for (int i = 0; i < MAX_KONTAKTI; i++) {
        brojPoslovnihKontakta->add(to_string(i+1).c_str());
        kontakti[i] = new Fl_Input(x + 420, y + 90 + i * 40, 150, 30, "Kontakt:");
    }
    brojPoslovnihKontakta->value(0);
    brojPoslovnihKontakta->callback(promeniBrojKontakta, this);

    dodaj = new Fl_Button(x + 100, y + 250, 50, 30, "Dodaj");
    izmeni = new Fl_Button(x + 166, y + 250, 50, 30, "Izmeni");
    ukloni = new Fl_Button(x + 232, y + 250, 50, 30, "Ukloni");

    posao->do_callback();
    this->end();
}

FormaRadnik::~FormaRadnik() {

}

void FormaRadnik::promeniPosao(Fl_Widget *widget, void *data) {
    FormaRadnik *forma = (FormaRadnik*) data;
    // sakrij sve komponenente specificne za odredjeni posao
    forma->izdavacLicence->hide();
    forma->maksimalniPrihod->hide();
    forma->brojRevizija->hide();
    for (int i = 0; i < MAX_REVIZIJE; i++) {
        forma->revizije[i]->hide();
    }
    forma->brojPoslovnihKontakta->hide();
    for (int i = 0; i < MAX_KONTAKTI; i++) {
        forma->kontakti[i]->hide();
    }
    // prikazi komponente specificne za izabrani posao
    if (forma->posao->value() == 0) {
        forma->izdavacLicence->show();
        forma->maksimalniPrihod->show();
    }
    else if (forma->posao->value() == 1) {
        forma->brojRevizija->show();
        forma->brojRevizija->do_callback();
    }
    else if (forma->posao->value() == 2) {
        forma->brojPoslovnihKontakta->show();
        forma->brojPoslovnihKontakta->do_callback();
    }
}

void FormaRadnik::promeniBrojRevizija(Fl_Widget *widget, void *data) {
    FormaRadnik *forma = (FormaRadnik*) data;
    int brojRevizija = forma->brojRevizija->value();
    for (int i = 0; i < brojRevizija; i++) {
        forma->revizije[i]->show();
    }
    for (int i = brojRevizija; i < MAX_REVIZIJE; i++) {
        forma->revizije[i]->hide();
    }
}

void FormaRadnik::promeniBrojKontakta(Fl_Widget *widget, void *data) {
    FormaRadnik *forma = (FormaRadnik*) data;
    int brojKontakta = forma->brojPoslovnihKontakta->value();
    for (int i = 0; i < brojKontakta; i++) {
        forma->kontakti[i]->show();
    }
    for (int i = brojKontakta; i < MAX_KONTAKTI; i++) {
        forma->kontakti[i]->hide();
    }
}
