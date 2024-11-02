#include "ovni.h"

Ovni::Ovni(QVector2D posicion, QVector2D velocidad):
    Nave(posicion, velocidad)
{

}

void Ovni::actualizar(float time)
{
    posicion.setX( posicion.x() + velocidad.x() * time);
    posicion.setY( posicion.y() + velocidad.y() * time);
}

void Ovni::dibujar(QPainter* p)
{
    QTransform transformada = QTransform().translate(posicion.x(),posicion.y()).scale(tamanio,tamanio).rotate(180);

    //transformo el colisionable
    QPolygonF colisionableTrans = transformada.map( colisionable.getPolyShape() );
    colisionable.setPoligono( colisionableTrans );

    //dibuja el poligono del colisionable
    // p->drawPolygon(colisionable.getPoligono());

    //dibuja el poligono del modelo que ve el usuario
    p->drawPolygon(transformada.map(poligono));
}
