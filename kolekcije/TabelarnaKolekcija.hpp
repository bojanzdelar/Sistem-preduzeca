#ifndef TABELARNA_KOLEKCIJA_HPP
#define TABELARNA_KOLEKCIJA_HPP

#include <string>
#include <vector>
#include <sstream>

using namespace std;

template <typename T>
class TabelarnaKolekcija {
protected:
    vector<T> *kolekcija;

public:
    TabelarnaKolekcija();
    TabelarnaKolekcija(vector<T> *kolekcija);

    vector<T>* getKolekcija() const;
    void setKolekcija(vector<T>* kolekcija);
    virtual int kolone() const = 0;
    int redovi() const;
    virtual string zaglavljeKolone(int kolona) const = 0;
    string zaglavljeRedova(int red) const;
    virtual string vrednostPolja(int kolona, int red) const = 0;
    T dobavi(int red);
    void dodaj(T t);
    void ukloni(int red);
    void ukloni(T t);
};

template <typename T>
TabelarnaKolekcija<T>::TabelarnaKolekcija() {
    kolekcija = new vector<T>;
}

template <typename T>
TabelarnaKolekcija<T>::TabelarnaKolekcija(vector<T> *kolekcija) : kolekcija(kolekcija) {
    
}

template <typename T>
vector<T>* TabelarnaKolekcija<T>::getKolekcija() const {
    return kolekcija;
}

template <typename T>
void TabelarnaKolekcija<T>::setKolekcija(vector<T> *kolekcija) {
    this->kolekcija = kolekcija;
}

template <typename T>
int TabelarnaKolekcija<T>::redovi() const {
    return kolekcija->size();
}

template <typename T>
string TabelarnaKolekcija<T>::zaglavljeRedova(int red) const {
    ostringstream out;
    out << red + 1;
    return out.str();
}

template <typename T>
T TabelarnaKolekcija<T>::dobavi(int red) {
    if (red < 0 || red >= redovi()) {
        return T();
    }
    return kolekcija->at(red);
}

template <typename T>
void TabelarnaKolekcija<T>::dodaj(T t) {
    kolekcija->push_back(t);
}

template <typename T>
void TabelarnaKolekcija<T>::ukloni(int red) {
    if (red < 0 || red >= redovi()) {
        return;
    }
    kolekcija->erase(kolekcija->begin() + red);
}

template <typename T>
void TabelarnaKolekcija<T>::ukloni(T t) {
    for (size_t i = 0; i < redovi(); i++) {
        if (t == kolekcija->at(i)) {
            kolekcija->erase(kolekcija->begin() + i);
            return;
        }
    }
}

#endif // TABELARNA_KOLEKCIJA_HPP