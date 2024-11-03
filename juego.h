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
#include "as_mediano.h"
#include "as_subdivisible.h"
#include "as_chico.h"
#include "ov_chico.h"
#include "ov_grande.h"
#include "tipoEvento.h"

class Juego : public dibujable
{
public:
    Juego();

    ~Juego();

    void dibujar(QPainter* p) override;
    void actualizarEstado(float time);
    void addProyectil(Proyectil* newBala);
    void rmvProyectil(Proyectil* bala);
    void addAsteroide(Asteroide* newAsteroide);
    void rmvAsteroide(Asteroide* asteroide);
    void addObjeto(ObjetoVolador* newObjeto);
    void rmvObjeto(ObjetoVolador* objeto);
    void resetTimeOvniDeath();
    void addEvento(TipoEvento evento);
    void manejarEvento(TipoEvento evento, int time);
    void resetTimeShoot();

    bool shouldSpawnOvni(int time, int cooldownOvni = 7000);
    bool shouldShoot(int time, int cooldownShot = 200);
    QList<Jugador*> getJugadores();

    void rmvEvento(TipoEvento evento);
protected:
    Tablero* tablero;
    Jugador* jugador;

    int timeSinceOvniDeath = 0;
    int timeSinceLastShot = 0;
    int puntos = 0;

    QList<dibujable*> lista_dibujables;
    QList<Proyectil*> lista_proyectiles;
    QList<Asteroide*> lista_asteroides;
    QList<ObjetoVolador*> lista_colisionables;
    QList<Jugador*> lista_jugadores;
    QList<Ovni*> lista_ovnis;
    QList<TipoEvento> lista_eventos;

};

#endif // JUEGO_H
