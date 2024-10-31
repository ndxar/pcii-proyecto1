#include "asteroide.h"
#include <QDebug>

Asteroide::Asteroide(QVector2D posicion, QVector2D velocidad):
ObjetoVolador(posicion, velocidad)
{
    qDebug() << "pos: " << posicion << "vel:" << velocidad;
}

void Asteroide::actualizar(float time)
{
    // qDebug() << "mueve asteroide";
    posicion.setX( posicion.x() + velocidad.x() * time);
    posicion.setY( posicion.y() + velocidad.y() * time);
}
