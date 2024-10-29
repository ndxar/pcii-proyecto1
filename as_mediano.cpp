#include "as_mediano.h"

As_Mediano::As_Mediano(QVector2D posicion, QVector2D velocidad)
{
    this->posicion = posicion;
    this->velocidad = velocidad;
    this->poligono << QPoint(0,-10) << QPoint(6,-8) << QPoint(6,-6) << QPoint(10,0) << QPoint(6,8) << QPoint(2,8) << QPoint(0,10) << QPoint(-2,8) << QPoint(-6,8) << QPoint(-8,6) << QPoint(-8,2) << QPoint(-10,0) << QPoint(-4,-8) << QPoint(-6,-8) << QPoint(-4,-8);
}

void As_Mediano::dibujar(QPainter* p)
{
    // QPolygon Poligono;
    // Poligono << QPoint(0,-10) << QPoint(6,-8) << QPoint(6,-6) << QPoint(10,0) << QPoint(6,8) << QPoint(2,8) << QPoint(0,10) << QPoint(-2,8) << QPoint(-6,8) << QPoint(-8,6) << QPoint(-8,2) << QPoint(-10,0) << QPoint(-4,-8) << QPoint(-6,-8) << QPoint(-4,-8);
    QTransform transformada = QTransform().translate(posicion.x(),posicion.y()).scale(4,4);
    p->drawPolygon(transformada.map(poligono));
}


void As_Mediano::subdividir()
{

}
