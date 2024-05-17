#ifndef POSICION_H
#define POSICION_H

#include <iostream>
#include <vector>

#define X_INICIAL 0
#define Y_INICIAL 0

class Posicion {

private:
    int x;
    int y;

public:
    Posicion();
    void mover(int x, int y);
};

Posicion::Posicion() : x(X_INICIAL), y(Y_INICIAL){}

void Posicion::mover(int x, int y) {
    this->x += x;
    this->y += y;
}

// TODO: No se si habrá que checkear los bordes del tablero


#endif
