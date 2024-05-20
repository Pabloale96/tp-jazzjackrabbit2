#ifndef POSICION_H
#define POSICION_H

#include <iostream>
#include <string>
#include <vector>

#define X_INICIAL 0
#define Y_INICIAL 0

class Posicion {

private:
    uint16_t x;
    uint16_t y;

public:
    Posicion();

    // void mover(int x, int y);

    bool mover(const std::string& direccion);

    uint16_t get_posicion_x();

    uint16_t get_posicion_y();
};

#endif
