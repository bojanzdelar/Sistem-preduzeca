#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Tabs.H>
#include <FL/fl_ask.H>

#include "kolekcije/Kolekcije.h"
#include "gui/Grupe.h"

using namespace std;

void sacuvaj(Fl_Widget *widget, void *data) {
    int izbor = fl_choice("Da li zelite da sacuvate izmene?", "Ne", "Da", 0);
    if (izbor == 1) {
        Kolekcije *kolekcije = (Kolekcije*) data;
        kolekcije->ispisiPodatke();
    }
    widget->hide();
}

int main() {
    KolekcijaPreduzeca preduzeca;
    KolekcijaOdeljenja odeljenja;
    KolekcijaRadnika radnici;
    KolekcijaNagrada nagrade;
    Kolekcije kolekcije(preduzeca, odeljenja, radnici, nagrade);

    kolekcije.procitajPodatke();
    kolekcije.poveziPodatke();
    
    Fl_Window *window = new Fl_Window(1225, 500, "Upravljanje preduzecima");
    {
        Fl_Tabs *tabs = new Fl_Tabs(10,10,1200,480);
        GrupaPreduzeca *grupaPreduzeca = new GrupaPreduzeca(10, 10, 1180, 435, &kolekcije);
        GrupaOdeljenja *grupaOdeljenja = new GrupaOdeljenja(10, 10, 1180, 435, &kolekcije);
        GrupaRadnika *grupaRadnika = new GrupaRadnika(10, 10, 1180, 435, &kolekcije);
        GrupaNagrada *grupaNagrada = new GrupaNagrada(10, 10, 1180, 435, &kolekcije);
        Grupe grupe(grupaPreduzeca, grupaOdeljenja, grupaRadnika, grupaNagrada);
        tabs->callback(Grupe::azuriraj, &grupe);
        tabs->end();
    }
    window->end();
    window->callback(sacuvaj, &kolekcije);
    window->show();
    return Fl::run();
}