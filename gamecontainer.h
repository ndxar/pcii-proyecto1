#ifndef GAMECONTAINER_H
#define GAMECONTAINER_H

#include <QWidget>
#include <QTimer>
#include <QKeyEvent>
#include "juego.h"
#include "jugador.h"

class gameContainer : public QWidget
{
    Q_OBJECT
public:
    explicit gameContainer(QWidget* parent = nullptr);

    void paintEvent(QPaintEvent* ev) override;

    Juego* getJuego();

protected:
    Juego* juego;
    float refresco_ms = 1;
    float aspectRatio = 3.0/2.0;

    QTimer timer;
    QElapsedTimer elapsedTimer;

};

#endif // GAMECONTAINER_H
