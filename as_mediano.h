#ifndef AS_MEDIANO_H
#define AS_MEDIANO_H

#include "as_subdivisible.h"

class As_Mediano : public As_Subdivisible
{
public:
    As_Mediano(QVector2D posicion, QVector2D direccion);

    void dibujar(QPainter* p) override;

    TipoObjeto tipo() const override { return TipoObjeto::As_Mediano; }

    virtual ~As_Mediano() { }

protected:
    QTransform transformada = QTransform().translate(posicion.x(),posicion.y()).scale(4,4);
};

#endif // AS_MEDIANO_H
