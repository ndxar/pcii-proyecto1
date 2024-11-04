#include "colisionable.h"

Colisionable::Colisionable()
{

}

Colisionable::Colisionable(QPolygonF poligono)
{
    this->polyShape = poligono;
    this->polyATM = poligono;
}

QPolygonF Colisionable::getPoligono()
{
    return polyATM;
}

QPolygonF Colisionable::getPolyShape()
{
    return polyShape;
}

bool Colisionable::estaColisionando(Colisionable objeto)
{
    return polyATM.intersects(objeto.getPoligono());
}

void Colisionable::setPoligono(QPolygonF newPoly)
{
    polyATM = newPoly;
}

void Colisionable::setPolyShape(QPolygonF newPolyShape)
{
    polyShape = newPolyShape;
    polyATM = newPolyShape;
}
