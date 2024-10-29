#ifndef AS_SUBDIVISIBLE_H
#define AS_SUBDIVISIBLE_H

#include "asteroide.h"

class As_Subdivisible : public Asteroide
{
public:
    As_Subdivisible();

    // void dibujar(QPainter* p) override;

    virtual void subdividir() = 0;

    bool hayQueDividir() override {return 1;};

    virtual ~As_Subdivisible() { }

protected:
};

#endif // AS_SUBDIVISIBLE_H
