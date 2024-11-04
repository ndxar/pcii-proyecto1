#ifndef OV_GRANDE_H
#define OV_GRANDE_H

#include "ovni.h"

class Ov_Grande : public Ovni
{
public:
    Ov_Grande(QVector2D posicion);

    virtual ~Ov_Grande() {}

    TipoObjeto tipo() const override { return TipoObjeto::Ov_Grande; }
};

#endif // OV_GRANDE_H
