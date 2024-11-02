#ifndef OV_GRANDE_H
#define OV_GRANDE_H

#include "ovni.h"

class Ov_Grande : public Ovni
{
public:
    Ov_Grande(QVector2D posicion);

    TipoObjeto tipo() const override { return TipoObjeto::Ov_Grande; }
    void dibujar(QPainter *p) override;
};

#endif // OV_GRANDE_H
