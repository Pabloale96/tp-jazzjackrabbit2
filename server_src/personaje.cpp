#include "../server_src/personaje.h"

#include <iostream>

Personaje::Personaje(): puntos(PUNTOS_INICIALES), vida(VIDA_INICIAL), arma(), posicion() {}

bool Personaje::mover(const std::string& direccion) { return posicion.mover(direccion); }

Posicion Personaje::obtener_posicion() { return posicion; }
