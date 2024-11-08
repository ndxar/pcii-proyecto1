#ifndef AS_GRANDE_H
#define AS_GRANDE_H

#include "as_subdivisible.h"

class As_Grande : public As_Subdivisible
{
public:
    As_Grande(QVector2D posicion, QVector2D velocidad);
    As_Grande(QVector2D posicion, float velMagnitud = 0.1);

    void dibujar(QPainter* p) override;

    TipoObjeto tipo() const override { return TipoObjeto::As_Grande; }

    ~As_Grande() {}

protected:
    QTransform transformada = QTransform().translate(posicion.x(),posicion.y()).scale(5,5);
};

#endif // AS_GRANDE_H
