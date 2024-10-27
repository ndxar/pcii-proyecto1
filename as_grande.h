#ifndef AS_GRANDE_H
#define AS_GRANDE_H

#include "as_subdivisible.h"

class As_Grande : public As_Subdivisible
{
public:
    As_Grande(QVector2D posicion, QVector2D direccion);

    void dibujar(QPainter* p) override;

    void subdividir() override;

protected:

};

#endif // AS_GRANDE_H
