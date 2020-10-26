#include "PrikazPlata.h"

PrikazPlata::PrikazPlata(int x, int y, int w, int h) : Fl_Widget(x, y, w, h) {

}

PrikazPlata::~PrikazPlata() {
    
}

Radnik* PrikazPlata::getRadnik() const {
    return radnik;
}

void PrikazPlata::setRadnik(Radnik* radnik) { 
    this->radnik = radnik;
    draw();
}

PoslovnaJedinica* PrikazPlata::getPoslovnaJednica() const {
    return poslovnaJedinica;
}

void PrikazPlata::setPoslovnaJedinica(PoslovnaJedinica* poslovnaJedinica) {
    this->poslovnaJedinica = poslovnaJedinica;
    draw();
}

void PrikazPlata::draw() {
    double plata = radnik->getPlata();
    double min = poslovnaJedinica->minimalnaPlata();
    double max = poslovnaJedinica->maksimalnaPlata();
    double avg = poslovnaJedinica->prosecnaPlata();

    // Pozadina
    fl_color(FL_WHITE);
    fl_rectf(x(), y(), w(), h());

    // Ivice
    fl_color(FL_BLACK);
    fl_rect(x(), y(), w(), h());

    // Linija za platu radnka
    fl_color(FL_RED);
    fl_line_style(FL_SOLID, 4);
    fl_yxline(x() + w()*(plata-min)/(max-min), y(), y() + h());
    
    // Linija za prosecnu platu
    fl_color(FL_YELLOW);
    fl_line_style(FL_SOLID, 4);
    fl_yxline(x() + w()*(avg-min)/(max-min), y(), y() + h());

    // Vrednosti
    fl_color(FL_BLACK);
    ostringstream out;
    out.precision(2);

    out << fixed << min;
    fl_draw(out.str().c_str(), x(), y() + h() + 20); 

    out.str("");
    out << max;
    fl_draw(out.str().c_str(), x() + w(), y() + h() + 20);

    out.str("");
    out << plata;
    fl_draw(out.str().c_str(), x() +w()*(plata-min)/(max-min), y() - 10);

    out.str("");
    out << avg;
    fl_draw(out.str().c_str(), x() + w()*(avg-min)/(max-min), y() + h() + 20);
}