#ifndef AS_CHICO_H
#define AS_CHICO_H

#include "asteroide.h"

class As_Chico : public Asteroide
{
public:
    As_Chico(QVector2D posicion, QVector2D velocidad);
    As_Chico(QVector2D posicion, float velMagnitud = 0.3);

    // bool hayQueDividir() override {return 0;};
    void dibujar(QPainter *p) override;

    TipoObjeto tipo() const override { return TipoObjeto::As_Chico; }

protected:
    QTransform transformada = QTransform().translate(posicion.x(),posicion.y()).scale(3,3);
};

#endif // AS_CHICO_H
