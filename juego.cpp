#include "juego.h"

Juego::Juego()
{
    tablero = new Tablero(QVector2D(0, 0), QVector2D(500, 500));

    lista_dibujables.append(tablero);
}


Juego::~Juego()
{
    delete tablero;
}

void Juego::actualizarEstado(float time)
{
    //ObjetoVolador->
}

void Juego::dibujar(QPainter * p) {

    for (int i =0; i<lista_dibujables.length(); i++)
        lista_dibujables[i]->dibujar(p);

}
