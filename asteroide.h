#ifndef ASTEROIDE_H
#define ASTEROIDE_H

#include "objetovolador.h"

class Asteroide : public ObjetoVolador
{
public:
    Asteroide();

    void actualizar(float time);

    virtual bool hayQueDividir() = 0;
    virtual bool esGrande() = 0;

    virtual ~Asteroide() { }

protected:
    QPolygon poligono;

};

#endif // ASTEROIDE_H
