#include "as_subdivisible.h"

As_Subdivisible::As_Subdivisible(QVector2D posicion, QVector2D velocidad):
Asteroide(posicion, velocidad)
{

}

As_Subdivisible::As_Subdivisible(QVector2D posicion, float velMagnitud ) :
    Asteroide(posicion,velMagnitud)
{

}
