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

    // As_Mediano* as1 = new As_Mediano(QVector2D(500,500), QVector2D(0.1,0.1));
    // addObjeto(as1);
    As_Grande* as2 = new As_Grande(QVector2D(100,500));
    addObjeto(as2);
    As_Chico* as3 = new As_Chico(QVector2D(1000,0));
    addObjeto(as3);

    jugador = new Jugador(tablero->getCentro(),0);
    addObjeto(jugador);

    Ovni* ov1 = new Ov_Chico(tablero->getCentro());
    Ovni* ov2 = new Ov_Grande(QVector2D(500,500));
    addObjeto(ov1);
    addObjeto(ov2);
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
    // ACTUALIZAR JUGADORES
    //////////////////////////////////////////////////////////////////////////////////////////////////////////
    for (int i=0; i<lista_jugadores.length(); i++)
    {
        lista_jugadores[i]->actualizar(time);
        lista_jugadores[i]->checkBordes(tablero);
    }

    //ACTUALIZAR PROYECTILES
    //////////////////////////////////////////////////////////////////////////////////////////////////////////
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

    //ACTUALIZAR OVNIS
    //////////////////////////////////////////////////////////////////////////////////////////////////////////
    for (int i=0;i<lista_ovnis.length();i++)
    {
        lista_ovnis[i]->actualizar(time);
        lista_ovnis[i]->checkBordes(tablero);
    }

    //ACTUALIZAR ASTEROIDES Y CHEQUEAR SUS COLISIONES CON JUG., OVNI, PROYEC.
    //NOTA: el chequeo de colisiones quizá convenga pasarlo a su propio lado, ya que si, p.ej., un jugador
    //      colisiona con con powerup u ovni, no lo estaría detectando :(
    //PD:   qué es un powerup??? :$
    //PPD:  convendría chequear el resto de colisiones en un iterador de cada objeto O un iterador de todos los colisionables?
    //////////////////////////////////////////////////////////////////////////////////////////////////////////
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
                        break;      // facilmente ampliable a más cosas TipoObjeto en un futuro, como powerups.

                    case TipoObjeto::Jugador:
                        addObjeto( new Jugador(tablero->getCentro(), 3000) );     //creo jugador nuevo con 3segundos de invencibilidad

                    case TipoObjeto::Ov_Chico:

                    case TipoObjeto::Ov_Grande:

                    case TipoObjeto::Proyectil:
                        switch ( lista_asteroides[i]->tipo() )
                        {
                            default:
                                break;
                            case TipoObjeto::As_Grande:
                                {
                                addObjeto( new As_Mediano(lista_asteroides[i]->getPosicion()) );
                                addObjeto( new As_Mediano(lista_asteroides[i]->getPosicion()) );
                                break;
                                }

                            case TipoObjeto::As_Mediano:
                                {
                                addObjeto( new As_Chico(lista_asteroides[i]->getPosicion()) );
                                addObjeto( new As_Chico(lista_asteroides[i]->getPosicion()) );
                                break;
                                }
                        }


                        qDebug() << "a";
                        rmvObjeto(lista_colisionables[j]);      //remuevo objeto que colisiono
                        qDebug() << "b";
                        rmvObjeto(lista_asteroides[i]);         //remuevo asteroide
                        qDebug() << "c";

                        break;
                }
            }
            if (i > (lista_asteroides.length() - 1)) { break; } //NO es buena práctica, pero cuando saco el último elemento
                                                                //puedo irme del indice, y con esto me aseguro de quedarme
                                                                //dentro del rango
        }

    }

    //chquear si hay <= 3 asteroides y spawnear un ovni

}

void Juego::dibujar(QPainter* p) {

    for (int i = 0; i<lista_dibujables.length(); i++)
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

        {
        case TipoObjeto::Ov_Chico:

        case TipoObjeto::Ov_Grande:
            Ovni* newOvni = dynamic_cast <Ovni*>(newObjeto);
            lista_ovnis.append(newOvni);
            lista_colisionables.append(newObjeto);
            lista_dibujables.append(newObjeto);
        }
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
            break;

        case TipoObjeto::Ov_Chico:
            qDebug() << "ovc";

        case TipoObjeto::Ov_Grande:
            qDebug() << "ovg";
            lista_ovnis.remove(lista_ovnis.indexOf(objeto));
            qDebug() << "1";
            lista_colisionables.remove(lista_colisionables.indexOf(objeto));
            qDebug() << "2";
            lista_dibujables.remove(lista_dibujables.indexOf(objeto));
            qDebug() << "3";
            delete objeto;
            qDebug() << "4";
            break;
    }

}
