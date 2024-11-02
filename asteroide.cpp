#include "asteroide.h"
#include <QRandomGenerator>
#include <QDebug>

Asteroide::Asteroide(QVector2D posicion, QVector2D velocidad):
ObjetoVolador(posicion, velocidad)
{
    qDebug() << "pos: " << posicion << "vel:" << velocidad;
}

Asteroide::Asteroide(QVector2D posicion, float velMagnitud)
{
    this->posicion = posicion;
    float randX = QRandomGenerator::global()->bounded(0,100);
    int randY = QRandomGenerator::global()->bounded(0,100);
    QVector2D vel = QVector2D(randX, randY).normalized() * velMagnitud;
    this->velocidad = vel;
    qDebug() << "pos: " << this->posicion << "vel:" << this->velocidad;
}

void Asteroide::actualizar(float time)
{
    posicion.setX( posicion.x() + velocidad.x() * time);
    posicion.setY( posicion.y() + velocidad.y() * time);
}
