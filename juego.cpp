#include "juego.h"

Juego::Juego()
{
    tablero = new Tablero(QVector2D(0, 0), QVector2D(700, 900));
    lista_dibujables.append(tablero);

    // As_Grande* as1 = new As_Grande(QVector2D(500,500), QVector2D(1,0.1));
    // addObjeto(as1);
    // As_Grande* as2 = new As_Grande(QVector2D(100,500), QVector2D(-0.1,0.1));
    // addObjeto(as2);
    // As_Grande* as3 = new As_Grande(QVector2D(500,0), QVector2D(0.5,-0.1));
    // addObjeto(as3);

    As_Mediano* as1 = new As_Mediano(QVector2D(500,500), QVector2D(0.1,0.1));
    addObjeto(as1);
    As_Grande* as2 = new As_Grande(QVector2D(100,500), QVector2D(-0.1,0.1));
    addObjeto(as2);
    As_Chico* as3 = new As_Chico(QVector2D(500,0), QVector2D(0.5,-0.1));
    addObjeto(as3);

    jugador = new Jugador(tablero->getCentro(),0.985,0);
    addObjeto(jugador);

}


Juego::~Juego()
{
    delete tablero;
    for (int i=0; i<lista_jugadores.length(); i++)
    {
        rmvObjeto(lista_jugadores[i]);
    }
}

void Juego::actualizarEstado(float time)
{
    for (int i=0; i<lista_jugadores.length(); i++)
    {
        lista_jugadores[i]->actualizar(time);
        lista_jugadores[i]->checkBordes(tablero);
    }
    // jugador->actualizar(time);
    // jugador->checkBordes(tablero);


    for (int i=0; i<lista_proyectiles.length(); i++)
    {
        if (lista_proyectiles[i]->isAlive(500))                                     //proyectiles duran 500ms
        {
            lista_proyectiles[i]->checkBordes(tablero);
            lista_proyectiles[i]->actualizar(time);
        }
        else
        {
            rmvObjeto(lista_proyectiles[i]);
        }
    }

    for (int i=0; i<lista_asteroides.length(); i++)
    {
        lista_asteroides[i]->checkBordes(tablero);
        lista_asteroides[i]->actualizar(time);

        for (int j=0; j<lista_colisionables.length(); j++)
        {
            if (lista_colisionables[j]->getColisionable().estaColisionando(lista_asteroides[i]->getColisionable())
                && lista_colisionables[j]->esInvencible() == 0)
            {
                switch (lista_colisionables[j]->tipo())
                {
                default:        // si colisiono con algo que no sea proyectil, jugador, ovni chico o grande, ignoro, no hago anda
                    break;

                case TipoObjeto::Jugador:
                    addObjeto( new Jugador(tablero->getCentro(),0.985, 3000) );     //creo jugador nuevo con 3segundos de invencibilidad

                case TipoObjeto::Ov_Chico:

                case TipoObjeto::Ov_Grande:

                case TipoObjeto::Proyectil:
                    rmvObjeto(lista_colisionables[j]);      //remuevo objeto que colisiono
                    rmvObjeto(lista_asteroides[i]);         //remuevo asteroide
                    break;
                }


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

QList<Jugador*> Juego::getJugadores()
{
    return lista_jugadores;
}

void Juego::addObjeto(ObjetoVolador* newObjeto)
{
    switch (newObjeto->tipo())
    {
    default:
        break;

    case TipoObjeto::Jugador:
    {
        Jugador* newJugador = dynamic_cast <Jugador*>(newObjeto);
        lista_colisionables.append(newObjeto);
        lista_dibujables.append(newObjeto);
        lista_jugadores.append(newJugador);
        break;
    }

    case TipoObjeto::Proyectil:
    {
        Proyectil* newProyectil = dynamic_cast <Proyectil*>(newObjeto);
        lista_proyectiles.append(newProyectil);
        lista_dibujables.append(newObjeto);
        lista_colisionables.append(newObjeto);
        break;
    }

    {
    case TipoObjeto::As_Chico:

    case TipoObjeto::As_Mediano:

    case TipoObjeto::As_Grande:
        Asteroide* newAsteroide = dynamic_cast <Asteroide*>(newObjeto);
        lista_asteroides.append(newAsteroide);
        lista_colisionables.append(newObjeto);
        lista_dibujables.append(newObjeto);
    }
    break;
    }

}

void Juego::rmvObjeto(ObjetoVolador* objeto)
{
    switch (objeto->tipo())
    {
    default:
        break;

    case TipoObjeto::Jugador:
        lista_jugadores.remove(lista_jugadores.indexOf(objeto));
        lista_dibujables.remove(lista_dibujables.indexOf(objeto));
        lista_colisionables.remove(lista_colisionables.indexOf(objeto));
        delete objeto;
        break;

    case TipoObjeto::Proyectil:
        lista_proyectiles.remove(lista_proyectiles.indexOf(objeto));
        lista_dibujables.remove(lista_dibujables.indexOf(objeto));
        lista_colisionables.remove(lista_colisionables.indexOf(objeto));
        delete objeto;
        break;

    case TipoObjeto::As_Chico:

    case TipoObjeto::As_Mediano:

    case TipoObjeto::As_Grande:
        lista_asteroides.remove(lista_asteroides.indexOf(objeto));
        lista_colisionables.remove(lista_colisionables.indexOf(objeto));
        lista_dibujables.remove(lista_dibujables.indexOf(objeto));
        delete objeto;
        qDebug() << "borre chico";
        break;
    }

}
