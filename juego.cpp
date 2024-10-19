#include "juego.h"

Juego::Juego()
{
    tablero = new Tablero(QVector2D(0, 0), QVector2D(500, 500));
    lista_dibujables.append(tablero);

    jugador = new Jugador(0.985);
    lista_dibujables.append(jugador);
}


Juego::~Juego()
{
    delete tablero;
}

void Juego::actualizarEstado(float time)
{
    jugador->actualizar(time);
}

void Juego::dibujar(QPainter * p) {

    for (int i =0; i<lista_dibujables.length(); i++)
        lista_dibujables[i]->dibujar(p);

}

Jugador* Juego::getJugador()
{
    return jugador;
}
