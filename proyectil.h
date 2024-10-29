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
    virtual ~Proyectil() {}

    void dibujar(QPainter *p) override;
    void actualizar(float time) override;

    bool isAlive(float tiempoDeVida);
    TipoObjeto tipo() const override { return TipoObjeto::Proyectil; }


protected:
    float tiempoProyectil = 0;
    Nave* autor;
    // const float tiempoDeVida;
};

#endif // PROYECTIL_H
