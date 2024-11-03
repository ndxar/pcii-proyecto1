#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent* event) {
    // se usa case para detectar las teclas presionadas ya que van a ser varias y es la forma más fácil
    switch(event->key())
    {
    case Qt::Key_Up :
        ui->widget->getJuego()->addEvento(TipoEvento::Avanzar);
        break;

    case Qt::Key_Right :
        ui->widget->getJuego()->addEvento(TipoEvento::Derecha);
        break;

    case Qt::Key_Left :
        ui->widget->getJuego()->addEvento(TipoEvento::Izquierda);
        break;

    case Qt::Key_Space :
        ui->widget->getJuego()->addEvento(TipoEvento::Disparo);
        break;

    case Qt::Key_E :
        qDebug() << "Easter egg :O";
        break;

    }
}

void MainWindow::keyReleaseEvent(QKeyEvent* event) {
    // se usa case para detectar las teclas presionadas ya que van a ser varias y es la forma más fácil
    switch(event->key())
    {
    case Qt::Key_Up :
        ui->widget->getJuego()->rmvEvento(TipoEvento::Avanzar);
        break;

    case Qt::Key_Right :
        ui->widget->getJuego()->rmvEvento(TipoEvento::Derecha);
        break;

    case Qt::Key_Left :
        ui->widget->getJuego()->rmvEvento(TipoEvento::Izquierda);
        break;

    case Qt::Key_Space :
        ui->widget->getJuego()->rmvEvento(TipoEvento::Disparo);
        break;

    case Qt::Key_E :
        qDebug() << "Easter egg :O";
        break;

    }
}
