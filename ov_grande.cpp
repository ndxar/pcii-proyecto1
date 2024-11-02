#include "ov_grande.h"

Ov_Grande::Ov_Grande(QVector2D posicion) :
    Ovni(posicion, QVector2D(0,0))
{
    QPolygonF bottom;
    QPolygonF middle;
    QPolygonF top;
    QPolygonF outline;
    bottom << QPointF(-10,0) << QPointF(-6,-2) << QPointF(6,-2) << QPointF(10,0) << QPointF(-10,0);
    middle << QPointF(-10,0) << QPointF(10,0) << QPointF(4,2) << QPointF(-4,2) << QPointF(-10,0);
    top << QPointF(-4,2) << QPointF(4,2) << QPointF(0,4) << QPointF(-4,2);
    outline << QPointF(-10,0) << QPointF(-6,-2) << QPointF(6,-2) << QPointF(10,0) << QPointF(4,2) << QPointF(0,4) << QPointF(-4,2) << QPointF(-10,0);
    this->poligono = bottom.united(middle).united(top);
    // this->poligono = outline;

    QTransform transformada = QTransform().translate(posicion.x(),posicion.y()).scale(5,5).rotate(180);
    this->colisionable.setPolyShape(outline);
    this->colisionable.setPoligono( transformada.map(colisionable.getPolyShape()) );
}
