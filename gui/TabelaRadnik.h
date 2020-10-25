#ifndef TABELA_RADNIK_H
#define TABELA_RADNIK_H

#include <sstream>

#include <FL/Fl.H>
#include <FL/Fl_Table_Row.H>
#include <FL/fl_draw.H>

#include "../model/KolekcijaRadnika.h"

class TabelaRadnik : public Fl_Table_Row {
protected:
    KolekcijaRadnika radnici;
    virtual void draw_cell(TableContext context, int red, int kolona, int x, int y, int w, int h);

public:
    TabelaRadnik(int x, int y, int w, int h, KolekcijaRadnika radnici);
    virtual ~TabelaRadnik();
};

#endif // TABELA_RADNIK_H