#ifndef _GAME_VELOCIDAD_H_
#define _GAME_VELOCIDAD_H_

#include <cstdint>

#define VELOCIDAD_NORMAL 1
#define VELOCIDAD_RAPIDA 2

class Velocidad {
private:
    int velocidad_x;
    int velocidad_y;

public:
    Velocidad();

    Velocidad(int velocidad_x, int velocidad_y);

    uint8_t obtener_velocidad_x() const;

    uint8_t obtener_velocidad_y() const;

    void setear_velocidad_x(uint8_t velocidad_x);

    void setear_velocidad_y(uint8_t velocidad_y);

    void idle();

    void correrDerecha();

    void correrDerechaRapido();

    void correrIzquierda();

    void correrIzquierdaRapido();

    void saltar();

    void caer();

    ~Velocidad();
};

#endif
