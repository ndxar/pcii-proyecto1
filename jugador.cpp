#include <QDebug>

#include "jugador.h"

Jugador::Jugador(QVector2D posicion, float friccion)
{
    this->posicion = posicion;
    this->friccion = friccion;
    QPolygon poly;
    poly << QPoint(-40,-20) << QPoint(40,-20) << QPoint(40,-10) << QPoint(10,10) << QPoint(0,50) << QPoint(-10,10) << QPoint(-40,-10);
    this->poligono = poly;
    QTransform transformada = QTransform().translate(posicion.x(),posicion.y()).rotate(angulo);
    this->colisionable.setPolyShape(poly);
    this->colisionable.setPoligono( transformada.map(colisionable.getPolyShape()) );
    this->angulo = 180;
}

void Jugador::dibujar(QPainter* p)
{
    // poligono << QPoint(-40,-20) << QPoint(40,-20) << QPoint(40,-10) << QPoint(10,10) << QPoint(0,50) << QPoint(-10,10) << QPoint(-40,-10);
    QTransform transformada = QTransform().translate(posicion.x(),posicion.y()).rotate(angulo);

    //transformo el colisionable
    QPolygon colisionableTrans = transformada.map( colisionable.getPolyShape() );
    colisionable.setPoligono( colisionableTrans );

    //dibuja el poligono del colisionable
    p->drawPolygon(colisionable.getPoligono());



    //dibuja el poligono del modelo que ve el usuario
    // p->drawPolygon(transformada.map(poligono));


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
    // angulo = deltaAngulo;
}

void Jugador::actualizar(float time)
{
    posicion.setX( posicion.x() + velocidad.x() * time );
    posicion.setY( posicion.y() + velocidad.y() * time );

    // QTransform transformada = QTransform().translate(velocidad.x() * time,velocidad.y() * time);
    // colisionable.setPoligono( transformada.map(colisionable.getPolyShape()) );

    velocidad.setX( velocidad.x() * friccion);
    velocidad.setY( velocidad.y() * friccion);
}

QVector2D Jugador::getDireccion()
{
    return QVector2D( -sin(getAngRad()), cos(getAngRad()) );
}

Proyectil* Jugador::disparar()
{
    // qDebug() << "Pos jug: " << posicion;
    Proyectil* newBala = new Proyectil(this, posicion, getDireccion(), 0.9);
    return newBala;
}
