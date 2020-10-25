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

    int getGodina() const;
    void setGodina(int godina);
    int getMesec() const;
    void setMesec(int mesec);
    int getDan() const;
    void setDan(int dan);
};

#endif // DATUM_H