#include "ovni.h"

Ovni::Ovni(QVector2D posicion, QVector2D velocidad):
    Nave(posicion, velocidad)
{

}

void Ovni::actualizar(float time)
{
    posicion.setX( posicion.x() + velocidad.x() * time);
    posicion.setY( posicion.y() + velocidad.y() * time);

    transformada = QTransform().translate(posicion.x(),posicion.y()).scale(tamanio,tamanio).rotate(180);
    //transformo el colisionable
    QPolygonF colisionableTrans = transformada.map( colisionable.getPolyShape() );
    colisionable.setPoligono( colisionableTrans );
}

void Ovni::dibujar(QPainter* p)
{
    p->setPen(QPen(Qt::white));
    //dibuja el poligono del modelo que ve el usuario
    p->drawPolygon(transformada.map(poligono));

    //dibuja el poligono del colisionable
    // p->drawPolygon(colisionable.getPoligono());
}

bool Ovni::shouldMove(float time, float cooldownDirChange)
{
    timeSinceLastDirChange += time;

    if (timeSinceLastDirChange > cooldownDirChange)
    {
        return 1;
    }
    else{ return 0; }
}

void Ovni::resetMoveTimer()
{
    timeSinceLastDirChange = 0;
}

void Ovni::setVelocidad(float magnitud, QVector2D direccion)
{
    this->velocidad = direccion.normalized() * magnitud;
}
