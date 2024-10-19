#ifndef NAVE_H
#define NAVE_H

#include "objetovolador.h"
#include "tablero.h"

class Nave : public ObjetoVolador
{
public:
    Nave();

    // void checkColision(QList<asteroide*> lista_asteroides);

    virtual void actualizar(float time) = 0;

protected:

};

#endif // NAVE_H
