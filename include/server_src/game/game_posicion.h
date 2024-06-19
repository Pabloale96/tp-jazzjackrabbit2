#ifndef _GAME_POSICION_H_
#define _GAME_POSICION_H_

#include <iostream>
#include <string>
#include <vector>

#include "../../common_src/defines_msg.h"
#include "../../server_src/game/game_velocidad.h"

#define X_INICIAL 0
#define Y_INICIAL 0

enum class Direccion {
    DERECHA,
    IZQUIERDA,
    ARRIBA,
    ABAJO,
    CENTRO  // seria como idle
};

class Posicion {

private:
    float x;
    float y;

public:
    Posicion();
    Posicion(float x, float y): x(x), y(y) {}

    void set_posicion(float x, float y);
    void set_posicion_en_x(float x);
    void set_posicion_en_y(float y);

    void mover(const Velocidad& velocidad);

    float get_posicion_x() const;

    float get_posicion_y() const;

    bool operator==(const Posicion& otro) const;
};

#endif
