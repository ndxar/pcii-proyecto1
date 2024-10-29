#ifndef AS_MEDIANO_H
#define AS_MEDIANO_H

#include "as_subdivisible.h"

class As_Mediano : public As_Subdivisible
{
public:
    As_Mediano(QVector2D posicion, QVector2D direccion);

    void dibujar(QPainter* p) override;

    void subdividir() override;

    bool esGrande() override {return 0;}
    TipoObjeto tipo() const override { return TipoObjeto::As_Mediano; }

    virtual ~As_Mediano() { }
};

#endif // AS_MEDIANO_H
