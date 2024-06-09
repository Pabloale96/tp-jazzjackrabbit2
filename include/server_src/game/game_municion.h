#ifndef _GAME_MUNICION_H_
#define _GAME_MUNICION_H_

#include "game_posicion.h"

class Municion {
private:
    Posicion posicion;
    Direccion direccion;
    uint8_t tipo_bala = 0;

public:
    Municion(uint16_t x, uint16_t y, Direccion direccion);

    uint8_t obtener_tipo_bala() { return tipo_bala; }

    uint16_t obtener_x() { return posicion.get_posicion_x(); }

    uint16_t obtener_y() { return posicion.get_posicion_y(); }
};

#endif
