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
    //void mover(int x, int y);
    bool mover(const std::string& direccion);
};

#endif
