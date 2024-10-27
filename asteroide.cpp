#include "asteroide.h"

Asteroide::Asteroide()
{

}

void Asteroide::actualizar(float time)
{
    posicion.setX( posicion.x() + velocidad.x() * time );
    posicion.setY( posicion.y() + velocidad.y() * time );
}
