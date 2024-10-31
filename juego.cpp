#include "juego.h"

Juego::Juego()
{
    tablero = new Tablero(QVector2D(0, 0), QVector2D(500, 700));
    lista_dibujables.append(tablero);

    jugador = new Jugador(tablero->getCentro(),0.985);
    lista_colisionables.append(jugador);
    lista_dibujables.append(jugador);

    As_Grande* as1 = new As_Grande(QVector2D(500,500), QVector2D(0.1,0.1));

    addObjeto(as1);
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
            rmvObjeto(lista_proyectiles[i]);
        }
    }

    for (int i=0; i<lista_asteroides.length(); i++)
    {
        lista_asteroides[i]->checkBordes(tablero);
        lista_asteroides[i]->actualizar(time);

        for (int j=0; j<lista_colisionables.length(); j++)
        {
            if (lista_colisionables[j]->getColisionable().estaColisionando(lista_asteroides[i]->getColisionable()))
            {
                switch (lista_colisionables[j]->tipo())
                {
                default:        // si colisiono con algo que no sea proyectil, jugador, ovni chico o grande, ignoro, no hago anda
                    break;
                case TipoObjeto::Proyectil:
                    rmvObjeto(lista_colisionables[j]);      //remuevo proyectil
                    rmvObjeto(lista_asteroides[i]);         //remuevo asteroide
                    qDebug() << "dos nuevos proyectiles medianos";
                    break;
                case TipoObjeto::Jugador:
                    rmvObjeto(lista_colisionables[j]);
                    rmvObjeto(lista_asteroides[i]);
                    qDebug() << "colision con jugador";
                    break;
                case TipoObjeto::Ov_Chico:
                    qDebug() << "colision con ov chico";
                    break;
                case TipoObjeto::Ov_Grande:
                    qDebug() << "colision con ov grande";
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

Jugador* Juego::getJugador()
{
    return jugador;
}

void Juego::addObjeto(ObjetoVolador* newObjeto)
{
    switch (newObjeto->tipo())
    {
    default:
        break;

    case TipoObjeto::Proyectil:
    {
        Proyectil* newProyectil = dynamic_cast <Proyectil*>(newObjeto);
        lista_proyectiles.append(newProyectil);
        lista_dibujables.append(newObjeto);
        lista_colisionables.append(newObjeto);
        break;
    }

    case TipoObjeto::As_Chico:{

    case TipoObjeto::As_Mediano:

    case TipoObjeto::As_Grande:
        Asteroide* newAsteroide = dynamic_cast <Asteroide*>(newObjeto);
        lista_asteroides.append(newAsteroide);
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
    }

}
