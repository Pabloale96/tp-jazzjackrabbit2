#ifndef _GAME_VELOCIDAD_H_
#define _GAME_VELOCIDAD_H_

#include <cstdint>

const float VELOCIDAD_NORMAL = 0.1f;
const float VELOCIDAD_RAPIDA = 0.2f;

class Velocidad {
private:
    float velocidad_x;
    float velocidad_y;

public:
    Velocidad();

    Velocidad(float velocidad_x, float velocidad_y);

    float obtener_velocidad_x() const;

    float obtener_velocidad_y() const;

    void setear_velocidad_x(float velocidad_x);

    void setear_velocidad_y(float velocidad_y);

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
