#include "juego.h"

Juego::Juego()
{
    tablero = new Tablero(QVector2D(0, 0), QVector2D(500, 700));
    lista_dibujables.append(tablero);

    jugador = new Jugador(tablero->getCentro(),0.985);
    lista_colisionables.append(jugador);
    lista_dibujables.append(jugador);

    As_Grande* as1 = new As_Grande(QVector2D(500,500), QVector2D(0.1,0.1));

    lista_asteroides.append(as1);
    lista_colisionables.append(as1);
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
        }
    }

    for (int i=0; i<lista_asteroides.length(); i++)
    {
        lista_asteroides[i]->checkBordes(tablero);
        lista_asteroides[i]->actualizar(time);

        for (int j=0; j<lista_colisionables.length(); j++)
        {


            //chequeo que no sea el mismo objeto (o asteroide en general deberia ser)
            if ((lista_colisionables[j] != lista_asteroides[i]) && (lista_colisionables[j]->getColisionable().estaColisionando(lista_asteroides[i]->getColisionable())) )
            {
                if (lista_asteroides[i]->hayQueDividir())
                {
                    if (lista_asteroides[i]->esGrande())
                    {
                        qDebug() << "divido el grande en medianos";
                        As_Mediano asMed1 = new As_Mediano(lista_asteroides[i]->getPosicion()+,  );
                    }
                    else
                    {
                        qDebug() << "divido el mediano en chicos";
                    }
                }
                qDebug() << "remuevo asteroide";
                rmvAsteroide(lista_asteroides[i]);
            }
        }



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

void Juego::addAsteroide(Asteroide* newAsteroide)
{
    lista_asteroides.append(newAsteroide);
    lista_colisionables.append(newAsteroide);
    lista_dibujables.append(newAsteroide);
}


void Juego::rmvAsteroide(Asteroide* asteroide)
{
    lista_asteroides.remove(lista_asteroides.indexOf(asteroide));
    lista_colisionables.remove(lista_colisionables.indexOf(asteroide));
    lista_dibujables.remove(lista_dibujables.indexOf(asteroide));
    delete asteroide;
}
