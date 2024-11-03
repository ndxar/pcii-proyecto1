#include "nave.h"
#include <QDebug>

Nave::Nave(QVector2D posicion, QVector2D velocidad):
    ObjetoVolador(posicion, velocidad)
{

}

bool Nave::puedoDisparar(int time, int cooldownDisparo)
{
    timeSinceLastShot += time;

    if (timeSinceLastShot > cooldownDisparo)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void Nave::resetShotTimer()
{
    timeSinceLastShot = 0;
}
