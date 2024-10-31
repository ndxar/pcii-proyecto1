#include "asteroide.h"

Asteroide::Asteroide(QVector2D posicion, QVector2D velocidad):
ObjetoVolador(posicion, velocidad)
{

}

void Asteroide::actualizar(float time)
{
    posicion.setX( posicion.x() + velocidad.x() * time );
    posicion.setY( posicion.y() + velocidad.y() * time );
}
