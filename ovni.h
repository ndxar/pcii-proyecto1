#ifndef OVNI_H
#define OVNI_H

#include "nave.h"

class Ovni : public Nave
{
public:
    Ovni(QVector2D posicion, QVector2D velocidad);

    bool esInvencible() override {return 0;}

    void actualizar(float time) override;
protected:
    QPolygonF poligono;
};

#endif // OVNI_H
