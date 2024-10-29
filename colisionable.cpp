#include "colisionable.h"
#include "QDebug"

Colisionable::Colisionable()
{

}

Colisionable::Colisionable(QPolygon poligono)
{
    this->polyShape = poligono;
    this->polyATM = poligono;
}

QPolygon Colisionable::getPoligono()
{
    return polyATM;
}

QPolygon Colisionable::getPolyShape()
{
    return polyShape;
}

bool Colisionable::estaColisionando(Colisionable objeto)
{
    return polyATM.intersects(objeto.getPoligono());
}

void Colisionable::setPoligono(QPolygon newPoly)
{
    polyATM = newPoly;
}

void Colisionable::setPolyShape(QPolygon newPolyShape)
{
    polyShape = newPolyShape;
    polyATM = newPolyShape;
}
