#include "as_grande.h"
#include <QDebug>

As_Grande::As_Grande(QVector2D posicion, QVector2D velocidad)
{
    this->posicion = posicion;
    this->velocidad = velocidad;
    QPolygon poly;
    poly << QPoint(0,-10) << QPoint(6,-8) << QPoint(6,-6) << QPoint(10,0) << QPoint(6,8) << QPoint(2,8) << QPoint(0,10) << QPoint(-2,8) << QPoint(-6,8) << QPoint(-8,6) << QPoint(-8,2) << QPoint(-10,0) << QPoint(-4,-8) << QPoint(-6,-8) << QPoint(-4,-8);
    this->poligono = poly;
    this->colisionable.setPolyShape(poly);
    this->colisionable.setPoligono( transformada.map(colisionable.getPolyShape()) );
}

void As_Grande::dibujar(QPainter* p)
{
    // QPolygon Poligono;
    // Poligono << QPoint(0,-10) << QPoint(6,-8) << QPoint(6,-6) << QPoint(10,0) << QPoint(6,8) << QPoint(2,8) << QPoint(0,10) << QPoint(-2,8) << QPoint(-6,8) << QPoint(-8,6) << QPoint(-8,2) << QPoint(-10,0) << QPoint(-4,-8) << QPoint(-6,-8) << QPoint(-4,-8);

    transformada = QTransform().translate(posicion.x(),posicion.y()).scale(5,5);
    QPolygon colisionableTrans = transformada.map( colisionable.getPolyShape() );
    colisionable.setPoligono(colisionableTrans);

    // p->drawPolygon(transformada.map(poligono));

    p->drawPolygon(colisionable.getPoligono());
}


void As_Grande::subdividir()
{
    qDebug() << "Se llama a subdividir el asteroide grande";
}
