#ifndef DIBUJABLE_H
#define DIBUJABLE_H

#include <QPainter>

class dibujable
{
public:
    virtual void dibujar(QPainter* p) = 0;
};

#endif // DIBUJABLE_H
