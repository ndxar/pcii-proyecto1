#include "as_chico.h"

As_Chico::As_Chico(QVector2D posicion, QVector2D velocidad):
Asteroide(posicion, velocidad)
{

}

void As_Chico::dibujar(QPainter* p)
{
    QPolygonF colisionableTrans = transformada.map( colisionable.getPolyShape() );
    colisionable.setPoligono(colisionableTrans);

    p->drawPolygon(transformada.map(poligono));

    // p->drawPolygon(colisionable.getPoligono());
}
