#include "as_grande.h"

As_Grande::As_Grande(QVector2D posicion, QVector2D velocidad):
    As_Subdivisible(posicion,velocidad)
{
    QPolygon poly;
    poly << QPoint(0,-10) << QPoint(6,-8) << QPoint(6,-6) << QPoint(10,0) << QPoint(6,8) << QPoint(2,8) << QPoint(0,10) << QPoint(-2,8) << QPoint(-6,8) << QPoint(-8,6) << QPoint(-8,2) << QPoint(-10,0) << QPoint(-4,-8) << QPoint(-6,-8) << QPoint(-4,-8);
    this->poligono = poly;
    this->colisionable.setPolyShape(poly);
    this->colisionable.setPoligono( transformada.map(colisionable.getPolyShape()) );
}

As_Grande::As_Grande(QVector2D posicion, float velMagnitud ) :
    As_Subdivisible(posicion,velMagnitud)
{
    QPolygon poly;
    poly << QPoint(0,-10) << QPoint(6,-8) << QPoint(6,-6) << QPoint(10,0) << QPoint(6,8) << QPoint(2,8) << QPoint(0,10) << QPoint(-2,8) << QPoint(-6,8) << QPoint(-8,6) << QPoint(-8,2) << QPoint(-10,0) << QPoint(-4,-8) << QPoint(-6,-8) << QPoint(-4,-8);
    this->poligono = poly;
    this->colisionable.setPolyShape(poly);
    this->colisionable.setPoligono( transformada.map(colisionable.getPolyShape()) );
}

void As_Grande::dibujar(QPainter* p)
{
    p->setPen(QPen(Qt::white));
    transformada = QTransform().translate(posicion.x(),posicion.y()).scale(9,9);
    QPolygonF colisionableTrans = transformada.map( colisionable.getPolyShape() );
    colisionable.setPoligono(colisionableTrans);

    p->drawPolygon(transformada.map(poligono));

    // p->drawPolygon(colisionable.getPoligono());
}

