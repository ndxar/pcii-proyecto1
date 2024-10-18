#include "objetovolador.h"

ObjetoVolador::ObjetoVolador(QVector2D posicion) :
    posicion(posicion),
    velocidad(QVector2D(0, 0))
{

}

ObjetoVolador::ObjetoVolador(QVector2D posicion, QVector2D velocidad) :
    posicion(posicion),
    velocidad(velocidad)
{

}

void ObjetoVolador::actualizar(float time)
{

}
