#ifndef ASTEROIDE_H
#define ASTEROIDE_H

#include "objetovolador.h"

class Asteroide : public ObjetoVolador
{
public:
    Asteroide(QVector2D posicion, QVector2D velocidad);

    void actualizar(float time) override;

    virtual bool hayQueDividir() = 0;
    bool esInvencible() override {return 0;}

    virtual ~Asteroide() { }

protected:
    QPolygon poligono;

};

#endif // ASTEROIDE_H
