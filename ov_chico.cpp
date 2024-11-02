#include "ov_chico.h"

Ov_Chico::Ov_Chico(QVector2D posicion) :
    Ovni(posicion, QVector2D(0,0))
{

}

void Ov_Chico::dibujar(QPainter* p)
{
    // poligono << QPoint(-40,-20) << QPoint(40,-20) << QPoint(40,-10) << QPoint(10,10) << QPoint(0,50) << QPoint(-10,10) << QPoint(-40,-10);
    QTransform transformada = QTransform().translate(posicion.x(),posicion.y());

    //transformo el colisionable
    QPolygonF colisionableTrans = transformada.map( colisionable.getPolyShape() );
    colisionable.setPoligono( colisionableTrans );

    //dibuja el poligono del colisionable
    // p->drawPolygon(colisionable.getPoligono());



    //dibuja el poligono del modelo que ve el usuario
    p->drawPolygon(transformada.map(poligono));


}
