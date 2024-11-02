#include <QDebug>

#include "jugador.h"

Jugador::Jugador(QVector2D posicion, int tiempoInvencible, float friccion) :
    Nave(posicion, QVector2D(0,0))
{
    this->friccion = friccion;
    this->tiempoInvencible = tiempoInvencible;

    QPolygonF poly;
    poly << QPointF(-40,-20) << QPointF(40,-20) << QPointF(40,-10) << QPointF(10,10) << QPointF(0,50) << QPointF(-10,10) << QPointF(-40,-10);
    this->poligono = poly;

    QTransform transformada = QTransform().translate(posicion.x(),posicion.y()).rotate(angulo);
    this->colisionable.setPolyShape(poly);
    this->colisionable.setPoligono( transformada.map(colisionable.getPolyShape()) );
}

void Jugador::dibujar(QPainter* p)
{
    // poligono << QPoint(-40,-20) << QPoint(40,-20) << QPoint(40,-10) << QPoint(10,10) << QPoint(0,50) << QPoint(-10,10) << QPoint(-40,-10);
    QTransform transformada = QTransform().translate(posicion.x(),posicion.y()).rotate(angulo);

    //transformo el colisionable
    QPolygonF colisionableTrans = transformada.map( colisionable.getPolyShape() );
    colisionable.setPoligono( colisionableTrans );

    //dibuja el poligono del colisionable
    // p->drawPolygon(colisionable.getPoligono());



    //dibuja el poligono del modelo que ve el usuario
    p->drawPolygon(transformada.map(poligono));


}

void Jugador::setVelocidad(float newVelocidad)
{
    if (newVelocidad > 0)
        {
        velocidad = QVector2D(-newVelocidad*sin(this->getAngRad()),newVelocidad*cos(this->getAngRad()));
        }
    else { velocidad = QVector2D(0,0); }
}

void Jugador::rotar(int deltaAngulo)
{
    angulo = angulo+deltaAngulo;
}

float Jugador::getAngRad()
{
    return angulo*3.14159/180;
}

void Jugador::actualizar(float time)
{
    posicion.setX( posicion.x() + velocidad.x() * time);
    posicion.setY( posicion.y() + velocidad.y() * time);

    // QTransform transformada = QTransform().translate(velocidad.x() * time,velocidad.y() * time);
    // colisionable.setPoligono( transformada.map(colisionable.getPolyShape()) );

    velocidad.setX( (velocidad.x() / friccion) * time);
    velocidad.setY( (velocidad.y() / friccion) * time);

    if (abs(velocidad.x()) < 1e-2) { velocidad.setX(0); }
    if (abs(velocidad.y()) < 1e-2) { velocidad.setY(0); }

    timerInvencible = timerInvencible + time;
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


bool Jugador::esInvencible()
{
    if (timerInvencible <= tiempoInvencible)
    {
        return 1;
    }
    else { return 0; }
}

void Jugador::setFriccion(float newFriccion)
{
    friccion = newFriccion;
}
