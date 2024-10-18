#ifndef TABLERO_H
#define TABLERO_H

#include "dibujable.h"
#include <QVector2D>

class Tablero : public dibujable
{
public:
    Tablero(QVector2D p1, QVector2D p2);

    void dibujar(QPainter* p) override;

    QVector2D getP1() {return p1;};
    QVector2D getP2() {return p2;};

protected:
    QVector2D p1, p2;

};

#endif // TABLERO_H
