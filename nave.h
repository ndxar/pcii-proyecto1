#ifndef NAVE_H
#define NAVE_H

#include "objetovolador.h"
#include "tablero.h"

class Nave : public ObjetoVolador
{
public:
    Nave(QVector2D posicion, QVector2D velocidad);

    // void checkColision(QList<asteroide*> lista_asteroides);
    bool puedoDisparar(int time, int cooldownDisparo = 100);
    virtual void actualizar(float time) = 0;
    virtual void setVelocidad(float magnitud, QVector2D direccion) = 0;
    void resetShotTimer();
protected:
    int timeSinceLastShot = 0;

};

#endif // NAVE_H
