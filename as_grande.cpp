#include "as_grande.h"
#include <QDebug>

As_Grande::As_Grande(QVector2D posicion, QVector2D velocidad)
{
    this->posicion = posicion;
    this->velocidad = velocidad;
}

void As_Grande::dibujar(QPainter* p)
{
    QPolygon Poligono;
    Poligono << QPoint(0,-10) << QPoint(6,-8) << QPoint(6,-6) << QPoint(10,0) << QPoint(6,8) << QPoint(2,8) << QPoint(0,10) << QPoint(-2,8) << QPoint(-6,8) << QPoint(-8,6) << QPoint(-8,2) << QPoint(-10,0) << QPoint(-4,-8) << QPoint(-6,-8) << QPoint(-4,-8);
    QTransform transformada = QTransform().translate(posicion.x(),posicion.y()).scale(5,5);
    p->drawPolygon(transformada.map(Poligono));
}


void As_Grande::subdividir()
{

}
