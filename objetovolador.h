#ifndef OBJETOVOLADOR_H
#define OBJETOVOLADOR_H

#include <QVector2D>
#include "dibujable.h"

class ObjetoVolador : public dibujable
{

public:
    ObjetoVolador(QVector2D posicion);
    ObjetoVolador(QVector2D posicion, QVector2D velocidad);

    void actualizar(float time);

    QVector2D getPosicion() {return posicion;};
    QVector2D getVelocidad() {return velocidad;};

protected:
    QVector2D posicion, velocidad;
};


#endif // OBJETOVOLADOR_H
