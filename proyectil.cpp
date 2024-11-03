#include "proyectil.h"

Proyectil::Proyectil(Nave* autor, QVector2D posicionDisparo, QVector2D direccionDisparo, float velocidad, int size) :
    ObjetoVolador(posicionDisparo, direccionDisparo * velocidad)
{
    this->autor = autor;
    this->size = size;

    QPolygonF polyColi;
    polyColi << QPointF(0,-1) << QPointF(0.6,-0.8) << QPointF(0.8,-0.6) << QPointF(1,0) << QPointF(0.8,0.6) << QPointF(0.6,0.8) << QPointF(0,1) << QPointF(-0.6,0.8) << QPointF(-0.8,0.6) << QPointF(-1,0) << QPointF(-0.8,-0.6) << QPointF(-0.6,-0.8);


    this->colisionable.setPolyShape(polyColi);
    this->colisionable.setPoligono( transformada.map(colisionable.getPolyShape()) );
}

void Proyectil::dibujar(QPainter* p)
{
    p->setPen(QPen(Qt::white));
    p->drawEllipse(QPointF(posicion.x(), posicion.y()), size, size);
    // p->drawPolygon(colisionable.getPoligono());
}

void Proyectil::actualizar(float time)
{
    posicion.setX( posicion.x() + velocidad.x() * time );
    posicion.setY( posicion.y() + velocidad.y() * time );

    tiempoProyectil = tiempoProyectil+time;

    transformada = QTransform().translate(posicion.x(),posicion.y()).scale(size,size);
    QPolygonF polyTrans = transformada.map(colisionable.getPolyShape());
    colisionable.setPoligono(polyTrans);
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

// Proyectil::~Proyectil() {}
