#include "TabelaRadnik.h"

TabelaRadnik::TabelaRadnik(int x, int y, int w, int h, vector<Radnik*> radnici) 
: Fl_Table_Row(x, y, w, h), radnici(radnici) {
    end();
    cols(6);
    rows(radnici.size());
    col_header(1);
    row_header(1);
}

TabelaRadnik::~TabelaRadnik() {

}

void TabelaRadnik::draw_cell(TableContext context, int red, int kolona, int x, int y, int w, int h) {
    switch (context) {
	case CONTEXT_COL_HEADER:
	    fl_push_clip(x, y, w, h); 
        {
            string s;
            if (kolona == 0) {
                s = "Posao";
            } else if (kolona == 1) {
                s = "ID";
            } else if (kolona == 2) {
                s = "Ime";
            } else if (kolona == 3) {
                s = "Prezime";
            } else if (kolona == 4) {
                s = "Plata";
            } else if (kolona == 5) {
                s = "Nadredjeni";
            } else {
                return;
            }
            fl_draw_box(FL_THIN_UP_BOX,x, y, w, h, col_header_color());
            fl_color(FL_BLACK);
            fl_draw(s.c_str(), x, y, w, h, FL_ALIGN_CENTER);
	    }
	    fl_pop_clip();
	    return;

	case CONTEXT_ROW_HEADER:
	    fl_push_clip(x, y, w, h);  
        {
            fl_draw_box(FL_THIN_UP_BOX, x, y, w, h, row_header_color());
            fl_color(FL_BLACK);
            fl_draw("x\0", x, y, w, h, FL_ALIGN_CENTER);
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
            ostringstream out;
            if (kolona == 0) {
                out << radnici.at(red)->getPosao();
            } else if (kolona == 1) {
                out << radnici.at(red)->getId();
            } else if (kolona == 2) {
                out << radnici.at(red)->getIme();
            } else if (kolona == 3) {
                out << radnici.at(red)->getPrezime();
            } else if (kolona == 4) {
                out.precision(2);
                out << fixed << radnici.at(red)->getPlata();
            } else if (kolona == 5) {
                out << radnici.at(red)->getNadredjeni()->getId();
            } else {
                return;
            }
            fl_color(FL_BLACK);
            fl_draw(out.str().c_str(), x, y, w, h, FL_ALIGN_CENTER);

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


    