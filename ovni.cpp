#include "ovni.h"

Ovni::Ovni(QVector2D posicion, QVector2D velocidad):
    Nave(posicion, velocidad)
{

}

void Ovni::actualizar(float time)
{
    posicion.setX( posicion.x() + velocidad.x() * time);
    posicion.setY( posicion.y() + velocidad.y() * time);
}
