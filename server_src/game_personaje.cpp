#include "../server_src/game_personaje.h"

#include <iostream>

Personaje::Personaje(uint16_t nuevo_gameloop_id):
        personaje_id(nuevo_gameloop_id),
        puntos(PUNTOS_INICIALES),
        vida(VIDA_INICIAL),
        arma(),
        posicion() {}

bool Personaje::mover(const std::string& direccion) { return posicion.mover(direccion); }

Posicion Personaje::obtener_posicion() { return posicion; }

uint16_t Personaje::obtener_personaje_id() { return personaje_id; }
