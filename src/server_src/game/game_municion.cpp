#include "game_municion.h"

#include <cstdint>

Municion::Municion(uint16_t x, uint16_t y, int velocidad_x, uint8_t tipo_bala, uint16_t id):
        // Se asume que las balas salen en linea recta (es decir, y=0)
        posicion(x, y),
        velocidad(velocidad_x, 0),
        tipo_bala(tipo_bala),
        id(id) {}

uint8_t Municion::obtener_tipo_bala() { return tipo_bala; }

uint16_t Municion::obtener_x() { return posicion.get_posicion_x(); }

uint16_t Municion::obtener_y() { return posicion.get_posicion_y(); }

Velocidad Municion::obtener_velocidad() { return velocidad; }

void Municion::mover() { posicion.mover(velocidad); }

Posicion Municion::obtener_posicion() { return posicion; }

uint16_t Municion::obtener_id() { return id; }
