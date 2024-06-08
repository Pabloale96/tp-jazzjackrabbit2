#ifndef _GAME_MUNICION_H_
#define _GAME_MUNICION_H_

#include "game_posicion.h"

class Municion {
private:
    Posicion posicion;
    Direccion direccion;

public:
    Municion(uint16_t x, uint16_t y, Direccion direccion);
};

#endif
