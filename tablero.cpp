#include "tablero.h"

Tablero::Tablero(QVector2D p1, QVector2D p2) :
    p1(p1),
    p2(p2)
{

}

void Tablero::dibujar(QPainter* p)
{
    // p->resetTransform();
    p->drawRect(p1.x(), p1.y(), p2.x()-p1.x(), p2.y()-p1.y());
}

QVector2D Tablero::getCentro()
{
    return QVector2D((p2.x()-p1.x())/2 ,(p2.y()-p1.y())/2);
}
