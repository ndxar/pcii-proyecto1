#include "proyectil.h"

Proyectil::Proyectil(Nave* autor, QVector2D posicionDisparo, QVector2D direccionDisparo, float velocidad)
{
    // qDebug() << "Pos proy: " << posicion;
    this->posicion = posicionDisparo;
    // qDebug() << "Pos proy: " << posicion;
    this->velocidad = direccionDisparo * velocidad;
    this->autor = autor;
}

void Proyectil::dibujar(QPainter* p)
{
    // p->resetTransform();
    p->drawEllipse(QPointF(posicion.x(), posicion.y()), 10, 10);
}

void Proyectil::actualizar(float time)
{
    posicion.setX( posicion.x() + velocidad.x() * time );
    posicion.setY( posicion.y() + velocidad.y() * time );

    tiempoProyectil = tiempoProyectil+time;
}

bool Proyectil::isAlive(float tiempoDeVida)
{
    if (tiempoProyectil <= tiempoDeVida)
    {
        // qDebug() << "proyec: " << tiempoProyectil << "vida: " << tiempoDeVida;
        return 1;
    }
    else
    {
        // qDebug() << "DED";
        return 0;
    }
}

Proyectil::~Proyectil() {}
