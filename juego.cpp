#include "juego.h"
#include <QRandomGenerator>

Juego::Juego()
{
    tablero = new Tablero(QVector2D(0, 0), QVector2D(1500, 1000));
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
    //MANEJAR EL TEMA DE EVENTOS
    shouldShoot(time);

    for (int i=0; i<lista_eventos.length(); i++)
    {
        manejarEvento(lista_eventos[i],time);
    }

    // ACTUALIZAR JUGADORES
    //////////////////////////////////////////////////////////////////////////////////////////////////////////
    for (int i=0; i<lista_jugadores.length(); i++)
    {
        lista_jugadores[i]->actualizar(time);
        lista_jugadores[i]->checkBordes(tablero);                                   //chequeo de bordes deberia devolver un bool y yo elegir que hacer acá

        for (int j=0; j<lista_colisionables.length(); j++)
        {
            if (lista_colisionables[j]->getColisionable().estaColisionando(lista_jugadores[i]->getColisionable())
                && lista_colisionables[j]->esInvencible() == 0
                && lista_jugadores[i]->esInvencible() == 0)
            {
                switch (lista_colisionables[j]->tipo())
                {
                    default:
                        break;

                    case TipoObjeto::Proyectil:
                    {
                        Proyectil* proyectil = dynamic_cast<Proyectil*>(lista_colisionables[j]);
                        if (proyectil->getAutor() == lista_jugadores[i])
                        {
                            break;
                        }
                        else
                        {
                            qDebug() << "a";
                            rmvObjeto(lista_colisionables[j]);
                            qDebug() << "b";
                            rmvObjeto(lista_jugadores[i]);
                            qDebug() << "c";
                            addObjeto( new Jugador(tablero->getCentro(), 3000) );
                            qDebug() << "d";
                            break;
                        }
                    }
                }
            }

            if (i > (lista_jugadores.length() - 1)) { break; }
        }
        if (i > (lista_jugadores.length() - 1)) { break; }
    }

    //ACTUALIZAR PROYECTILES
    //////////////////////////////////////////////////////////////////////////////////////////////////////////
    for (int i=0; i<lista_proyectiles.length(); i++)
    {
        if (lista_proyectiles[i]->isAlive(1000))                                     //proyectiles duran 500ms
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
        for (int j=0; j<lista_colisionables.length(); j++)
        {
            if (lista_colisionables[j]->getColisionable().estaColisionando(lista_ovnis[i]->getColisionable())
                && lista_colisionables[j]->esInvencible() == 0)
            {
                switch (lista_colisionables[j]->tipo())
                {
                    default:                                                //no preciso chequear asteroides ya que lo hago en los asteroides
                        break;                                              //quiero que ovnis no colisionen entre si

                    case TipoObjeto::Jugador:
                        addObjeto( new Jugador(tablero->getCentro(), 3000) );
                        rmvObjeto(lista_colisionables[j]);                  //remuevo objeto que colisiono
                        rmvObjeto(lista_ovnis[i]);                          //remuevo ovni
                        break;

                    case TipoObjeto::Proyectil:
                    {
                        Proyectil* proyectil = dynamic_cast<Proyectil*>(lista_colisionables[j]);
                        if (proyectil->getAutor() == lista_ovnis[i])
                        {
                            break;
                        }
                    }
                        rmvObjeto(lista_colisionables[j]);                  //remuevo objeto que colisiono
                        rmvObjeto(lista_ovnis[i]);                          //remuevo ovni
                        break;
                }
            }
            if (i > (lista_ovnis.length() - 1)) { break; } //NO es buena práctica, pero cuando saco el último elemento
                                                                //puedo irme del indice, y con esto me aseguro de quedarme
                                                                //dentro del rango
        }
        if (i > (lista_ovnis.length() - 1)) { break; }



                                                                                                    //mover el ovni en direccion random
        if (lista_ovnis[i]->shouldMove(time))
        {
            QVector2D direccion;
            int nroRandom = QRandomGenerator::global()->bounded(0,5);
            qDebug() << nroRandom;
            switch (nroRandom)
            {
                default:
                    direccion = QVector2D(1,0);
                    break;
                case 0:
                    direccion = QVector2D(1,1);
                    break;
                case 1:
                    direccion = QVector2D(-1,1);
                    break;
                case 2:
                    direccion = QVector2D(-1,-1);
                    break;
                case 3:
                    direccion = QVector2D(1,-1);
                    break;
            }

            lista_ovnis[i]->setVelocidad(0.2,direccion);
            lista_ovnis[i]->resetMoveTimer();
        }

                                                                                                    // disparar
        if (lista_ovnis[i]->puedoDisparar(time, 3000))
        {
            switch (lista_ovnis[i]->tipo())
            {
                default:
                    break;

                case TipoObjeto::Ov_Chico:
                {
                    float x = lista_jugadores[0]->getPosicion().x() - lista_ovnis[i]->getPosicion().x();
                    float y = lista_jugadores[0]->getPosicion().y() - lista_ovnis[i]->getPosicion().y();
                    QVector2D direccion = QVector2D(x,y).normalized();
                    addObjeto( new Proyectil(lista_ovnis[i],lista_ovnis[i]->getPosicion(),direccion,0.9,5));
                    break;
                }

                case TipoObjeto::Ov_Grande:
                    float x = QRandomGenerator::global()->bounded(-100,100);
                    float y = QRandomGenerator::global()->bounded(-100,100);
                    QVector2D direccion = QVector2D(x,y).normalized();
                    addObjeto( new Proyectil(lista_ovnis[i],lista_ovnis[i]->getPosicion(),direccion,0.9,3));
                    break;
            }
            lista_ovnis[i]->resetShotTimer();
        }

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
                                puntos += 20;
                                break;
                                }

                            case TipoObjeto::As_Mediano:
                                {
                                addObjeto( new As_Chico(lista_asteroides[i]->getPosicion()) );
                                addObjeto( new As_Chico(lista_asteroides[i]->getPosicion()) );
                                puntos += 50;
                                break;
                                }
                            case TipoObjeto::As_Chico:
                                puntos += 100;
                                break;
                        }

                        rmvObjeto(lista_colisionables[j]);      //remuevo objeto que colisiono
                        rmvObjeto(lista_asteroides[i]);         //remuevo asteroide

                        break;
                }
            }
            if (i > (lista_asteroides.length() - 1)) { break; } //NO es buena práctica, pero cuando saco el último elemento
                                                                //puedo irme del indice, y con esto me aseguro de quedarme
                                                                //dentro del rango
        }

    }


    //chquear si hay <= 3 asteroides y spawnear un ovni grande
    if (shouldSpawnOvni(time) && lista_asteroides.length() <= 3 && lista_ovnis.length() <= 0)
    {
        float posX;
        float posY;
        if (QRandomGenerator::global()->bounded(0,2)) { posX = tablero->getP1().x(); }        //elijo al azar uno de los bordes laterales
        else { posX = tablero->getP2().x(); }

        posY = QRandomGenerator::global()->bounded( (int)tablero->getP2().y() );             //elijo al azar un lugar en todo el borde lateral
        qDebug() << "aaaaaaaaaa" << posX << posY;

        addObjeto( new Ov_Chico(QVector2D(posX,posY)) );
    }


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

        case TipoObjeto::Ov_Grande:
            lista_ovnis.remove(lista_ovnis.indexOf(objeto));
            lista_colisionables.remove(lista_colisionables.indexOf(objeto));
            lista_dibujables.remove(lista_dibujables.indexOf(objeto));
            delete objeto;
            resetTimeOvniDeath();
            break;
    }

}

void Juego::resetTimeOvniDeath()
{
    timeSinceOvniDeath = 0;
}

void Juego::addEvento(TipoEvento evento)
{
    lista_eventos.append(evento);
}

void Juego::rmvEvento(TipoEvento evento)
{
    lista_eventos.remove(lista_eventos.indexOf(evento));
}

void Juego::manejarEvento(TipoEvento evento, int time)
{
        switch (evento)
        {
            case TipoEvento::Avanzar:
                lista_jugadores[0]->setVelocidad(0.3);
                break;

            case TipoEvento::Derecha:
                lista_jugadores[0]->rotar(0.5);
                break;

            case TipoEvento::Izquierda:
                lista_jugadores[0]->rotar(-0.5);
                break;

            case TipoEvento::Disparo:
                if (shouldShoot(time, 500))
                {
                    addObjeto( new Proyectil(lista_jugadores[0],lista_jugadores[0]->getPosicion(), lista_jugadores[0]->getDireccion(), 0.9) );
                    resetTimeShoot();
                }
                break;
        }
}

void Juego::resetTimeShoot()
{
    timeSinceLastShot = 0;
}

bool Juego::shouldSpawnOvni(int time, int cooldownOvni)
{
    timeSinceOvniDeath += time;
    if (timeSinceOvniDeath > cooldownOvni)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

bool Juego::shouldShoot(int time, int cooldownShot)
{
    timeSinceLastShot += time;
    if (timeSinceLastShot > cooldownShot)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
