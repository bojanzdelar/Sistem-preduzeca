#ifndef POSLOVNA_JEDINICA_H
#define POSLOVNA_JEDINICA_H

class PoslovnaJedinica {
public:
    virtual double minimalnaPlata() const = 0;
    virtual double prosecnaPlata() const = 0;
    virtual double maksimalnaPlata() const = 0;
};

#endif // POSLOVNA_JEDINICA_H