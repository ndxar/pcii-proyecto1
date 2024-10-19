#ifndef NAVE_H
#define NAVE_H

#include "objetovolador.h"

class Nave : public ObjetoVolador
{
public:
    Nave();

    virtual void actualizar(float time) = 0;

protected:

};

#endif // NAVE_H
