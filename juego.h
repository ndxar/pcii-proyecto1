#ifndef JUEGO_H
#define JUEGO_H

#include "Dibujable.h"
#include "tablero.h"
#include "objetovolador.h"

class Juego : public dibujable
{
public:
    Juego();

    ~Juego();

    void dibujar(QPainter* p) override;
    void actualizarEstado(float time);

protected:
    Tablero* tablero;

    QList<dibujable *> lista_dibujables;

};

#endif // JUEGO_H
