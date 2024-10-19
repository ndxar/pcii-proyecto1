#ifndef JUGADOR_H
#define JUGADOR_H

#include "nave.h"

class Jugador : public Nave
{
public:
    Jugador(QVector2D posicion, float friccion);

    void disparar();
    void dibujar(QPainter* p) override;
    void actualizar(float time) override;

    void rotar(int deltaAngulo);
    void setVelocidad(float newVelocidad);

    QVector2D getPosicion();
    QVector2D getVelocidad();
    float getAngRad();

private:
    // QVector2D posicion;
    // QVector2D velocidad;
    int angulo;
    float friccion;
};

#endif // JUGADOR_H
