#include "gamecontainer.h"

#include <QPainter>

gameContainer::gameContainer(QWidget* parent)
    : QWidget{parent}
{
    setFocusPolicy(Qt::StrongFocus);  // asegura que el widget reciba eventos de teclado

    juego = new Juego();

    timer.setInterval(refresco_ms);
    connect(&timer, SIGNAL(timeout()), this, SLOT(update()));
    timer.start();
    elapsedTimer.start();
}

void gameContainer::paintEvent(QPaintEvent* ev)
{
    QPainter p(this);
    p.setWindow(QRect(0,0,1500,1000));

    float x0 = 0;
    float y0 = 0;
    float x1 = this->width();
    float y1 = this->height();

    if (this->width() > this->height()*aspectRatio)
    {
        x1 = this->height()*aspectRatio;
        y1 = this->height();

        x0 = this->width()/2.0 - x1/2;
    }
    else
    {
        x1 = this->width();
        y1 = this->width()/aspectRatio;

        y0 = this->height()/2.0 - y1/2;
    }

    p.setViewport(x0,y0,x1,y1);

    float _time = elapsedTimer.restart();

    juego->actualizarEstado(_time);
    juego->dibujar(&p);
}

void gameContainer::addEvento(TipoEvento ev)
{
    lista_eventos.append(ev);
}

void gameContainer::rmvEvento(TipoEvento ev)
{
    lista_eventos.removeAt(lista_eventos.indexOf(ev));
}

Juego* gameContainer::getJuego()
{
    return juego;
}



