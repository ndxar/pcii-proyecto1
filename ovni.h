#ifndef OVNI_H
#define OVNI_H

#include "nave.h"

class Ovni : public Nave
{
public:
    Ovni(QVector2D posicion, QVector2D velocidad);
    virtual ~Ovni() {}

    bool esInvencible() override {return 0; }
    bool shouldMove();

    void actualizar(float time) override;
    void dibujar(QPainter *p) override;
protected:
    QPolygonF poligono;
    float tamanio = 5;
    int timeSinceLastDirChange = 0;
    QTransform transformada;
};

#endif // OVNI_H
