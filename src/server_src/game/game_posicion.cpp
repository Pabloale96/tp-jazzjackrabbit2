#include "../../include/server_src/game/game_posicion.h"

Posicion::Posicion(): x(X_INICIAL), y(Y_INICIAL) {}

void Posicion::set_posicion(uint16_t x, uint16_t y) {
    this->x = x;
    this->y = y;
}

/*
void Posicion::mover(int x, int y) {
    this->x += x;
    this->y += y;
}*/

bool Posicion::mover(const std::string& direccion) {
    // TODO: No se si habrá que checkear los bordes del tablero
    if (direccion == "derecha") {
        this->x++;
        if (x>=XMAX) x=0;
        return true;
    } else if (direccion == "derecha_rapido") {
        // TODO: Capaz habría que chequear cuánto aumenta el mover rápido
        if (x>=XMAX) x=0;
        this->x += 2;
        return true;
    } else if (direccion == "izquierda") {
        this->x--;
        if (x>=XMAX) x=XMAX;
        std::cout << "valor de x:" << x << std::endl;
        return true;
    } else if (direccion == "izquierda_rapido") {
        // TODO: Capaz habría que chequear cuánto aumenta el mover rápido
        if (x>=XMAX) x=XMAX;
        return true;
    } else if (direccion == "arriba") {
        this->y++;
        if (y>=YMAX) y=YMAX;
        return true;
    } else if (direccion == "abajo") {
        this->y--;
        if (y>=YMAX) y=YMAX;
        return true;
    } else if (direccion == "saltar") {
        // TODO: Capaz habria que chequear cuánto aumenta el saltar
        this->y += 2;
        if (y>=YMAX) y=YMAX;
        return true;
    }
    return false;
}

uint16_t Posicion::get_posicion_x() { return this->x; }

uint16_t Posicion::get_posicion_y() { return this->y; }
