#ifndef JUGADOR_H
#define JUGADOR_H

#include "nave.h"
#include "proyectil.h"

class Jugador : public Nave
{
public:
    Jugador(QVector2D posicion, int tiempoInvencible = 0, float friccion = 1000);

    Proyectil* disparar();
    void dibujar(QPainter* p) override;
    void actualizar(float time) override;

    void rotar(float deltaAngulo, float time);
    void setVelocidad(float magnitud, QVector2D direccion = QVector2D(0,0)) override;
    void setFriccion(float newFriccion);

    QVector2D getPosicion();
    QVector2D getVelocidad();
    QVector2D getDireccion();
    float getAngRad();
    TipoObjeto tipo() const override { return TipoObjeto::Jugador; }
    bool esInvencible() override;

private:
    // QVector2D posicion;
    // QVector2D velocidad;
    float friccion;
    QPolygonF poligono;
    int tiempoInvencible;
    int timerInvencible = 0;
    float angulo = 180;
    QTransform transformada;

};

#endif // JUGADOR_H
