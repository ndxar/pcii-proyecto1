#include "ov_chico.h"

Ov_Chico::Ov_Chico(QVector2D posicion) :
    Ovni(posicion, QVector2D(0,0))
{
    QPolygonF bottom;
    QPolygonF top;
    QPolygonF outline;
    bottom << QPointF(-8,0) << QPointF(-6,-2) << QPointF(6,-2) << QPointF(8,0) << QPointF(4,2) << QPointF(-4,2);
    top << QPointF(-4,2) << QPointF(-2,4) << QPointF(2,4) << QPointF(4,2);
    outline << QPointF(-8,0) << QPointF(-6,-2) << QPointF(6,-2) << QPointF(8,0) << QPointF(4,2) << QPointF(2,4) << QPointF(-2,4) << QPointF(-4,2);
    this->poligono = top.united(bottom);

    QTransform transformada = QTransform().translate(posicion.x(),posicion.y()).scale(5,5).rotate(180);
    this->colisionable.setPolyShape(outline);
    this->colisionable.setPoligono( transformada.map(colisionable.getPolyShape()) );

}

