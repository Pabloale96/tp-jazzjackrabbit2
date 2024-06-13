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
    uint16_t x;
    uint16_t y;

public:
    Posicion();
    Posicion(uint16_t x, uint16_t y): x(x), y(y) {}

    void set_posicion(uint16_t x, uint16_t y);

    void mover(const Velocidad& velocidad);

    uint16_t get_posicion_x();

    uint16_t get_posicion_y();

    bool operator==(const Posicion& otro) const;
};

#endif
