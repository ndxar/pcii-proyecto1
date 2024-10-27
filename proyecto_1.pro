QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    as_chico.cpp \
    as_grande.cpp \
    as_mediano.cpp \
    as_subdivisible.cpp \
    asteroide.cpp \
    colisionable.cpp \
    gamecontainer.cpp \
    juego.cpp \
    jugador.cpp \
    main.cpp \
    mainwindow.cpp \
    nave.cpp \
    objetovolador.cpp \
    ov_chico.cpp \
    ov_grande.cpp \
    ovni.cpp \
    proyectil.cpp \
    tablero.cpp

HEADERS += \
    as_chico.h \
    as_grande.h \
    as_mediano.h \
    as_subdivisible.h \
    asteroide.h \
    colisionable.h \
    dibujable.h \
    gamecontainer.h \
    juego.h \
    jugador.h \
    mainwindow.h \
    nave.h \
    objetovolador.h \
    ov_chico.h \
    ov_grande.h \
    ovni.h \
    proyectil.h \
    tablero.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
