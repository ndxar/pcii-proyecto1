#ifndef JUEGO_H
#define JUEGO_H

#include "Dibujable.h"
#include "tablero.h"
#include "nave.h"
#include "jugador.h"
#include "objetovolador.h"

class Juego : public dibujable
{
public:
    Juego();

    ~Juego();

    void dibujar(QPainter* p) override;
    void actualizarEstado(float time);

    Jugador* getJugador();

protected:
    Tablero* tablero;
    Jugador* jugador;

    QList<dibujable*> lista_dibujables;
    // QList<asteroide*> lista_asteroides;

};

#endif // JUEGO_H
