#include "juego.h"

Juego::Juego()
{
    tablero = new Tablero(QVector2D(0, 0), QVector2D(500, 700));
    lista_dibujables.append(tablero);

    jugador = new Jugador(tablero->getCentro(),0.985);
    lista_dibujables.append(jugador);

    As_Grande* as1 = new As_Grande(QVector2D(100,100), QVector2D(0.1,0.1));

    lista_asteroides.append( as1 );
    lista_dibujables.append( as1 );
}


Juego::~Juego()
{
    delete tablero;
    delete jugador;
}

void Juego::actualizarEstado(float time)
{
    jugador->actualizar(time);
    jugador->checkBordes(tablero);


    for (int i=0; i<lista_proyectiles.length(); i++)
    {
        if (lista_proyectiles[i]->isAlive(500))
        {
            lista_proyectiles[i]->checkBordes(tablero);
            lista_proyectiles[i]->actualizar(time);
        }
        else
        {
            rmvProyectil(lista_proyectiles[i]);
            // delete lista_proyectiles[i];
        }
    }

    for (int i=0; i<lista_asteroides.length(); i++)
    {
        lista_asteroides[i]->checkBordes(tablero);
        lista_asteroides[i]->actualizar(time);
    }
}

void Juego::dibujar(QPainter* p) {

    for (int i =0; i<lista_dibujables.length(); i++)
    {
        lista_dibujables[i]->dibujar(p);
    }
}

Jugador* Juego::getJugador()
{
    return jugador;
}

void Juego::addProyectil(Proyectil* newBala)
{
    lista_proyectiles.append(newBala);
    lista_dibujables.append(newBala);
}

void Juego::rmvProyectil(Proyectil* bala)
{
    lista_proyectiles.remove(lista_proyectiles.indexOf(bala));
    lista_dibujables.remove(lista_dibujables.indexOf(bala));
    delete bala;
}
