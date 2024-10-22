#ifndef PROYECTIL_H
#define PROYECTIL_H

#include <QDebug>

#include "objetovolador.h"
#include "nave.h"
#include "dibujable.h"
// #include "juego.h"

class Proyectil : public ObjetoVolador
{
public:
    Proyectil(Nave* autor, QVector2D posicionDisparo, QVector2D direccionDisparo, float velocidad);

    void dibujar(QPainter *p) override;
    void actualizar(float time) override;


protected:
    float tiempoProyectil = 0;
    Nave* autor;
    const float tiempoDeVida = 500;
};

#endif // PROYECTIL_H
