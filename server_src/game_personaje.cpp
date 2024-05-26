#include "../server_src/game_personaje.h"

#include <iostream>

Personaje::Personaje(uint16_t client_id):
        client_id(client_id), puntos(PUNTOS_INICIALES), vida(VIDA_INICIAL), arma(), posicion() {}

bool Personaje::mover(const std::string& direccion) { return posicion.mover(direccion); }

Posicion Personaje::obtener_posicion() const { return posicion; }

uint16_t Personaje::obtener_personaje_id() const { return client_id; }
