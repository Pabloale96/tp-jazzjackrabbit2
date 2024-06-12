#ifndef _GAME_MUNICION_H_
#define _GAME_MUNICION_H_

#include "game_posicion.h"

class Municion {
private:
    Posicion posicion;
    Direccion direccion;
    uint8_t tipo_bala;
    uint16_t id;

public:
    Municion(uint16_t x,  uint16_t y, Direccion direccion, uint8_t tipo_bala, uint16_t id);

    uint8_t obtener_tipo_bala();

    uint16_t obtener_x();

    uint16_t obtener_y();

    Direccion obtener_direccion();

    Posicion obtener_posicion();

    void mover();

    uint16_t obtener_id();

};

#endif
