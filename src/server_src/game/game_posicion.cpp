#include "../../include/server_src/game/game_posicion.h"

Posicion::Posicion(): x(X_INICIAL), y(Y_INICIAL) {}

void Posicion::set_posicion(float x, float y) {
    this->x = x;
    this->y = y;
}

void Posicion::set_posicion_en_x(float x) { this->x = x; }
void Posicion::set_posicion_en_y(float y) { this->y = y; }

void Posicion::mover(const Velocidad& velocidad) {
    // std::cout << "ANTES DE MOVER: (" << x << " ," << y << " )" << std::endl;

    // std::cout << "Velocidad EN MOVER: " << velocidad.obtener_velocidad_x() << "  || " <<
    // velocidad.obtener_velocidad_y() << std::endl;

    this->x += velocidad.obtener_velocidad_x();
    if (x >= XMAX) {
        x = XMAX;
    }
    if (x < 0) {
        x = 0;
    }

    this->y += velocidad.obtener_velocidad_y();
    if (y >= YMAX) {
        y = YMAX;
    }
    if (y < 0) {
        y = 0;
    }

    // std::cout << "DESPUES DE MOVER: (" << x << " ," << y << " )" << std::endl;
}

float Posicion::get_posicion_x() const { return this->x; }

float Posicion::get_posicion_y() const { return this->y; }

bool Posicion::operator==(const Posicion& otro) const {
    return this->x == otro.x && this->y == otro.y;
}
