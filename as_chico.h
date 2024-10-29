#ifndef AS_CHICO_H
#define AS_CHICO_H

#include "asteroide.h"

class As_Chico : public Asteroide
{
public:
    As_Chico();

    bool hayQueDividir() override {return 0;};

    TipoObjeto tipo() const override { return TipoObjeto::As_Chico; }
};

#endif // AS_CHICO_H
