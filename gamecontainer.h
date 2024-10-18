#ifndef GAMECONTAINER_H
#define GAMECONTAINER_H

#include <QWidget>
#include <QTimer>
#include <QKeyEvent>
#include "juego.h"

class gameContainer : public QWidget
{
    Q_OBJECT
public:
    explicit gameContainer(QWidget* parent = nullptr);

    void keyPressEvent(QKeyEvent* event) override;      //sobreescribo la funcion interna de QT para detectar cuando presiono una tecla

    void paintEvent(QPaintEvent* ev) override;

protected:
    Juego* juego;
    float refresco_ms = 10;

    QTimer timer;

};

#endif // GAMECONTAINER_H
