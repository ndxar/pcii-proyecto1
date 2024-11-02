#ifndef OVNI_H
#define OVNI_H

#include "nave.h"

class Ovni : public Nave
{
public:
    Ovni(QVector2D posicion, QVector2D velocidad);

    bool esInvencible() override {return 0; }
    int getTimeSinceLastShot() {return timeSinceLastShot; };
    int getTimeSinceLastDirChange() { return timeSinceLastDirChange;};

    void actualizar(float time) override;
    void dibujar(QPainter *p) override;
protected:
    QPolygonF poligono;
    float tamanio = 5;
    int timeSinceLastShot = 0;
    int timeSinceLastDirChange = 0;
};

#endif // OVNI_H
