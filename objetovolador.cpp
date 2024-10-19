#include "objetovolador.h"

// ObjetoVolador::ObjetoVolador(QVector2D posicion) :
//     posicion(posicion),
//     velocidad(QVector2D(0, 0))
// {

// }

// ObjetoVolador::ObjetoVolador(QVector2D posicion, QVector2D velocidad) :
//     posicion(posicion),
//     velocidad(velocidad)
// {

// }

ObjetoVolador::ObjetoVolador() {}

void ObjetoVolador::checkBordes(Tablero* tablero)
{
    if (posicion.x() > tablero->getP2().x())
    {
        posicion.setX( tablero->getP1().x() );
    }
    if (posicion.x() < tablero->getP1().x())
    {
        posicion.setX( tablero->getP2().x() );
    }
    if (posicion.y() > tablero->getP2().y())
    {
        posicion.setY( tablero->getP1().y() );
    }
    if (posicion.y() < tablero->getP1().y())
    {
        posicion.setY( tablero->getP2().x() );
    }
}
