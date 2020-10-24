#ifndef DATUM_H
#define DATUM_H

class Datum {
private:
    int godina;
    int mesec;
    int dan;

public:
    Datum();
    Datum(int godina, int mesec, int dan);
    virtual ~Datum();

    int getGodina();
    void setGodina(int godina);
    int getMesec();
    void setMesec(int mesec);
    int getDan();
    void setDan(int dan);
};

#endif // DATUM_H