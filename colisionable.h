#ifndef COLISIONABLE_H
#define COLISIONABLE_H

#include <QVector2D>
#include <QPainter>

class Colisionable
{
public:
    Colisionable();
    Colisionable(QPolygonF poligono);

    bool estaColisionando(Colisionable objeto);
    QPolygonF getPoligono();
    QPolygonF getPolyShape();

    void setPoligono(QPolygonF newPoly);         //setea solo polyATM, usado para actualizar la posicion
    void setPolyShape(QPolygonF newPolyShape);   //setea polyShape y polyATM, recibe un poligono centrado en el origen

protected:
    QPolygonF polyATM;   //poligono que se mueve en el tablero
    QPolygonF polyShape; //poligono centrado en el origen, el "modelo"
};

#endif // COLISIONABLE_H
