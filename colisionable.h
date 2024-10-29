#ifndef COLISIONABLE_H
#define COLISIONABLE_H

#include <QVector2D>
#include <QPainter>

class Colisionable
{
public:
    Colisionable();
    Colisionable(QPolygon poligono);

    bool estaColisionando(Colisionable objeto);
    QPolygon getPoligono();
    QPolygon getPolyShape();

    void setPoligono(QPolygon newPoly);         //setea solo polyATM, usado para actualizar la posicion
    void setPolyShape(QPolygon newPolyShape);   //setea polyShape y polyATM, recibe un poligono centrado en el origen

protected:
    QPolygon polyATM;   //poligono que se mueve en el tablero
    QPolygon polyShape; //poligono centrado en el origen, el "modelo"
};

#endif // COLISIONABLE_H
