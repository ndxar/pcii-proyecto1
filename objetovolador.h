#ifndef OBJETOVOLADOR_H
#define OBJETOVOLADOR_H

#include <QVector2D>
#include "dibujable.h"

class ObjetoVolador : public dibujable
{

public:
    // tiene sentido que esto tenga un constructor que no sea por defecto??????? no, se implementa en cada objeto (ovni, jugador, asteroide, etc)
    // ObjetoVolador(QVector2D posicion);
    // ObjetoVolador(QVector2D posicion, QVector2D velocidad);
    ObjetoVolador();

    virtual void actualizar(float time) = 0;

    QVector2D getPosicion() {return posicion;}
    QVector2D getVelocidad() {return velocidad;}

protected:
    QVector2D posicion, velocidad;
};


#endif // OBJETOVOLADOR_H
