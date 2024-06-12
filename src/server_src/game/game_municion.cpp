#include "game_municion.h"

#include <cstdint>

Municion::Municion(uint16_t x, uint16_t y, Direccion direccion, uint8_t tipo_bala, uint16_t id):
        posicion(x, y), direccion(direccion), tipo_bala(tipo_bala), id(id) {};

uint8_t Municion::obtener_tipo_bala() { return tipo_bala; }

uint16_t Municion::obtener_x() { return posicion.get_posicion_x(); }

uint16_t Municion::obtener_y() { return posicion.get_posicion_y(); }

Direccion Municion::obtener_direccion() { return direccion; }

void Municion::mover() {
        // Solo se puede disparar hacia izquierda o derecha
        if (direccion == Direccion::IZQUIERDA) {
                posicion.mover("izquierda");
        } else {
                posicion.mover("derecha");
        }
}

Posicion Municion::obtener_posicion() { return posicion; }

uint16_t Municion::obtener_id() { return id; }
