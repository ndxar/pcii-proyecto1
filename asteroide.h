#ifndef ASTEROIDE_H
#define ASTEROIDE_H

#include "objetovolador.h"

class Asteroide : public ObjetoVolador
{
public:
    Asteroide();

    void actualizar(float time);

    virtual ~Asteroide() { }

protected:

};

#endif // ASTEROIDE_H
