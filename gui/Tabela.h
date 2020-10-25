#ifndef TABELA_H
#define TABELA_H

#include <sstream>

#include <FL/Fl.H>
#include <FL/Fl_Table_Row.H>
#include <FL/fl_draw.H>

#include "../kolekcije/TabelarnaKolekcija.h"

class Tabela : public Fl_Table_Row {
protected:
    TabelarnaKolekcija *kolekcija;
    virtual void draw_cell(TableContext context, int red, int kolona, int x, int y, int w, int h);

public:
    Tabela(int x, int y, int w, int h, TabelarnaKolekcija *kolekcija);
    virtual ~Tabela();
};

#endif // TABELA_H