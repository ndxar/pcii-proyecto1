#include "gamecontainer.h"

#include <QPainter>
#include <QDebug>


gameContainer::gameContainer(QWidget* parent)
    : QWidget{parent}
{
    setFocusPolicy(Qt::StrongFocus);  // asegura que el widget reciba eventos de teclado

    juego = new Juego();

    timer.setInterval(refresco_ms);
    connect(&timer, SIGNAL(timeout()), this, SLOT(update()));
    timer.start();
}

void gameContainer::paintEvent(QPaintEvent* ev)
{
    QPainter p(this);
    p.setWindow(QRect(0,0,1500,1000));


    if (this->width() > this->height()*aspectRatio)
    {
        float x1 = this->height()*aspectRatio;
        float y1 = this->height();
        p.setViewport(0,0,x1,y1);
    }
    else
    {
        float x1 = this->width();
        float y1 = this->width()/aspectRatio;
        p.setViewport(0,0,x1,y1);
    }

    juego->actualizarEstado(refresco_ms);

    juego->dibujar(&p);
}


void gameContainer::keyPressEvent(QKeyEvent* event) {
    // se usa case para detectar las teclas presionadas ya que van a ser varias y es la forma más fácil
    switch(event->key())
    {
        case Qt::Key_Up :
            // qDebug() << "aprete arriba :D CASE";
            juego->getJugadores()[0]->setVelocidad(0.3);
            break;

        case Qt::Key_Down :
            // qDebug() << "aprete abajo D: CASE";
            break;

        case Qt::Key_Right :
            // qDebug() << "aprete der CASE";
            juego->getJugadores()[0]->rotar(5);
            break;

        case Qt::Key_Left :
            // qDebug() << "aprete izq CASE";
            juego->getJugadores()[0]->rotar(-5);
            break;

        case Qt::Key_Space :
            // qDebug() << "aprete space CASE";
            juego->addObjeto( juego->getJugadores()[0]->disparar() );
            break;

        case Qt::Key_E :
            // qDebug() << "Easter egg :O";
            break;

    }
}


