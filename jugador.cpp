#include <QDebug>

#include "jugador.h"

Jugador::Jugador(QVector2D posicion, float friccion)
{
    this->posicion = posicion;
    this->friccion = friccion;
    this->angulo = 180;
}

void Jugador::dibujar(QPainter* p)
{
    QPolygon Poligono;
    Poligono << QPoint(-40,-20) << QPoint(40,-20) << QPoint(40,-10) << QPoint(10,10) << QPoint(0,50) << QPoint(-10,10) << QPoint(-40,-10);
    // Poligono.translate(QPoint(100,100));
    p->translate(posicion.x(),posicion.y());
    p->rotate(angulo);
    p->drawPolygon(Poligono);
}

float Jugador::getAngRad()
{
    return angulo*3.14159/180;
}

void Jugador::setVelocidad(float newVelocidad)
{
    if (newVelocidad > 0)
        {
        velocidad = QVector2D(-newVelocidad*sin(this->getAngRad()),newVelocidad*cos(this->getAngRad()));
        qDebug() << velocidad;
        }
    else { velocidad = QVector2D(0,0); }
}

void Jugador::rotar(int deltaAngulo)
{
    angulo = angulo+deltaAngulo;
}

void Jugador::actualizar(float time)
{
    posicion.setX( posicion.x() + velocidad.x() * time );
    posicion.setY( posicion.y() + velocidad.y() * time );

    velocidad.setX( velocidad.x() * friccion);
    velocidad.setY( velocidad.y() * friccion);
}
