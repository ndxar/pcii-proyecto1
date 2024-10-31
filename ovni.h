#ifndef OVNI_H
#define OVNI_H

#include "nave.h"

class Ovni : public Nave
{
public:
    Ovni(QVector2D posicion, QVector2D velocidad);

    bool esInvencible() override {return 0;}
};

#endif // OVNI_H
