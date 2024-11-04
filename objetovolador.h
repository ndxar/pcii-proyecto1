#ifndef OBJETOVOLADOR_H
#define OBJETOVOLADOR_H

#include <QVector2D>
#include "dibujable.h"
#include "tablero.h"
#include "colisionable.h"
#include "tipoObjeto.h"

class ObjetoVolador : public dibujable
{

public:
    ObjetoVolador(QVector2D posicion, QVector2D velocidad);
    ObjetoVolador();

    virtual ~ObjetoVolador() {}

    virtual void actualizar(float time) = 0;
    void checkBordes(Tablero* tablero);
    void rotar(int deltaAngulo);

    QVector2D getPosicion() {return posicion;}
    QVector2D getVelocidad() {return velocidad;}
    virtual TipoObjeto tipo() const = 0;
    virtual bool esInvencible() = 0;
    Colisionable getColisionable() {return colisionable;}

protected:
    QVector2D posicion, velocidad;
    Colisionable colisionable;

};


#endif // OBJETOVOLADOR_H
