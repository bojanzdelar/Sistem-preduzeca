#ifndef TABELA_H
#define TABELA_H

#include <sstream>

#include <FL/Fl.H>
#include <FL/Fl_Table_Row.H>
#include <FL/fl_draw.H>

#include "../kolekcije/TabelarnaKolekcija.h"

template <typename T>
class Tabela : public Fl_Table_Row {
protected:
    TabelarnaKolekcija<T> *kolekcija;
    virtual void draw_cell(TableContext context, int red, int kolona, int x, int y, int w, int h);

public:
    Tabela(int x, int y, int w, int h, TabelarnaKolekcija<T> *kolekcija);
    virtual ~Tabela();

    TabelarnaKolekcija<T>* getKolekcija();
    void setKolekcija(TabelarnaKolekcija<T>* kolekcija);
};

template <typename T>
Tabela<T>::Tabela(int x, int y, int w, int h, TabelarnaKolekcija<T> *kolekcija) 
: Fl_Table_Row(x, y, w, h), kolekcija(kolekcija){
    cols(kolekcija->kolone());
    rows(kolekcija->redovi());
    col_header(1);
    row_header(1);
    Fl_Table_Row::type(SELECT_SINGLE);
    end();
}

template <typename T>
Tabela<T>::~Tabela() {

}

template <typename T>
void Tabela<T>::draw_cell(TableContext context, int red, int kolona, int x, int y, int w, int h) {
    switch (context) {
	case CONTEXT_COL_HEADER:
	    fl_push_clip(x, y, w, h); 
        {           
            fl_draw_box(FL_THIN_UP_BOX,x, y, w, h, col_header_color());
            fl_color(FL_BLACK);
            fl_draw(kolekcija->zaglavljeKolone(kolona).c_str(), x, y, w, h, FL_ALIGN_CENTER);
	    }
	    fl_pop_clip();
	    return;

	case CONTEXT_ROW_HEADER:
	    fl_push_clip(x, y, w, h);  
        {
            fl_draw_box(FL_THIN_UP_BOX, x, y, w, h, row_header_color());
            fl_color(FL_BLACK);
            fl_draw(kolekcija->zaglavljeRedova(red).c_str(), x, y, w, h, FL_ALIGN_CENTER);
	    }
	    fl_pop_clip();
	    return;

	case CONTEXT_CELL: 
	    fl_push_clip(x, y, w, h); 
        {
	        // boja pozadine
            fl_color( row_selected(red) ? FL_SELECTION_COLOR : FL_WHITE);
            fl_rectf(x, y, w, h);

            // tekst            
            fl_color(FL_BLACK);
            fl_draw(kolekcija->vrednostPolja(kolona,red).c_str(), x, y, w, h, FL_ALIGN_CENTER);

            // ivica
            fl_color(color()); 
            fl_rect(x, y, w, h);
	    }
	    fl_pop_clip();
	    return;	

    default:
	    return;
    }
}

#endif // TABELA_H