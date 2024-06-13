#include "../../include/server_src/game/game_posicion.h"

Posicion::Posicion(): x(X_INICIAL), y(Y_INICIAL) {}

void Posicion::set_posicion(uint16_t x, uint16_t y) {
    this->x = x;
    this->y = y;
}

void Posicion::mover(const Velocidad& velocidad) {
    //std::cout << "ANTES DE MOVER: (" << x << " ," << y << " )" << std::endl;

    //std::cout << "Velocidad EN MOVER: " << velocidad.obtener_velocidad_x() << "  || " << velocidad.obtener_velocidad_y() << std::endl;

    this->x += velocidad.obtener_velocidad_x();
    if (x >= XMAX) {
        // Si llegó al borde derecho, vuelve al borde izquierdo
        x = 0;
    }

    this->y += velocidad.obtener_velocidad_y();
    if (y >= YMAX) {
        // Si llegó al borde superior, vuelve al borde inferior
        y = 0;
    }

    //std::cout << "DESPUES DE MOVER: (" << x << " ," << y << " )" << std::endl;
}

uint16_t Posicion::get_posicion_x() { return this->x; }

uint16_t Posicion::get_posicion_y() { return this->y; }

bool Posicion::operator==(const Posicion& otro) const {
    return this->x == otro.x && this->y == otro.y;
}
