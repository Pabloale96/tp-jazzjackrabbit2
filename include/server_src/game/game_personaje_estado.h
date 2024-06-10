#ifndef _GAME_PERSONAJE_ESTADO_H
#define _GAME_PERSONAJE_ESTADO_H

#include <iostream>
#include <vector>

class EstadoPersonaje {
private:
    bool idle;
    bool corriendo;
    bool corriendo_muy_rapido;
    bool saltando;
    bool cayendo;
    bool disparando;
    bool accion_especial;

    bool recibiendo_danio;
    bool muerto;

    bool intoxicado;

public:
    EstadoPersonaje(/* args */);
    ~EstadoPersonaje();
};
