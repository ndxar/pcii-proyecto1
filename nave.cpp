#include "nave.h"
#include <QDebug>

Nave::Nave(QVector2D posicion, QVector2D velocidad):
    ObjetoVolador(posicion, velocidad)
{

}

bool Nave::puedoDisparar(int time, int cooldownDisparo)
{
    if (timeSinceLastShot > cooldownDisparo)
    {
        return 0;
    }
    else
    {
        return 1;
    }

    timeSinceLastShot += time;
}


