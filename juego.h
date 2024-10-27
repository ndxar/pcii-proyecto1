#ifndef JUEGO_H
#define JUEGO_H

#include "Dibujable.h"
#include "tablero.h"
#include "nave.h"
#include "jugador.h"
#include "objetovolador.h"
#include "proyectil.h"
#include "asteroide.h"
#include "as_grande.h"

class Juego : public dibujable
{
public:
    Juego();

    ~Juego();

    void dibujar(QPainter* p) override;
    void actualizarEstado(float time);
    void addProyectil(Proyectil* newBala);
    void rmvProyectil(Proyectil* bala);

    Jugador* getJugador();

protected:
    Tablero* tablero;
    Jugador* jugador;

    QList<dibujable*> lista_dibujables;
    QList<Proyectil*> lista_proyectiles;
    QList<Asteroide*> lista_asteroides;
    QList<ObjetoVolador*> lista_colisionables;

};

#endif // JUEGO_H
