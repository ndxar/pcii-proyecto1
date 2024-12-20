#ifndef OV_CHICO_H
#define OV_CHICO_H

#include "ovni.h"

class Ov_Chico : public Ovni
{
public:
    Ov_Chico(QVector2D posicion);

    virtual ~Ov_Chico() {}

    TipoObjeto tipo() const override { return TipoObjeto::Ov_Chico; }
};

#endif // OV_CHICO_H
