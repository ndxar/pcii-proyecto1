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
    void addEvento(TipoEvento ev);
    void rmvEvento(TipoEvento ev);
    void doEventos();

    Juego* getJuego();

protected:
    Juego* juego;
    float refresco_ms = 1;
    float aspectRatio = 3.0/2.0;
    QList<TipoEvento> lista_eventos;

    QTimer timer;
    QElapsedTimer elapsedTimer;

};

#endif // GAMECONTAINER_H
