#include "../server_src/personaje.h"

Personaje::Personaje(): /*puntos(PUNTOS_INICIALES), vida(VIDA_INICIAL), arma(), estado(),*/ posicion() {}

bool Personaje::mover(const std::string& direccion) {
    return posicion.mover(direccion);
}
