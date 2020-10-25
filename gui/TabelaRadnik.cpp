#include "TabelaRadnik.h"

TabelaRadnik::TabelaRadnik(int x, int y, int w, int h, KolekcijaRadnika radnici) 
: Fl_Table_Row(x, y, w, h), radnici(radnici) {
    end();
    cols(radnici.kolone());
    rows(radnici.redovi());
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
            fl_draw_box(FL_THIN_UP_BOX,x, y, w, h, col_header_color());
            fl_color(FL_BLACK);
            fl_draw(radnici.zaglavljeKolone(kolona).c_str(), x, y, w, h, FL_ALIGN_CENTER);
	    }
	    fl_pop_clip();
	    return;

	case CONTEXT_ROW_HEADER:
	    fl_push_clip(x, y, w, h);  
        {
            fl_draw_box(FL_THIN_UP_BOX, x, y, w, h, row_header_color());
            fl_color(FL_BLACK);
            fl_draw(radnici.zaglavljeRedova(red).c_str(), x, y, w, h, FL_ALIGN_CENTER);
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
            fl_draw(radnici.vrednostPolja(kolona,red).c_str(), x, y, w, h, FL_ALIGN_CENTER);

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


    