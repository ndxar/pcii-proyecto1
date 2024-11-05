#ifndef AS_SUBDIVISIBLE_H
#define AS_SUBDIVISIBLE_H

#include "asteroide.h"

class As_Subdivisible : public Asteroide
{
public:
    As_Subdivisible(QVector2D posicion, QVector2D velocidad);
    As_Subdivisible(QVector2D posicion, float velMagnitud);

    // bool hayQueDividir() override {return 1;};

    virtual ~As_Subdivisible() { }

protected:
};

#endif // AS_SUBDIVISIBLE_H
