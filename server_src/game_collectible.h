#ifndef _GAME_COLLECTIBLE_H_
#define _GAME_COLLECTIBLE_H_

#include <iostream>
#include <vector>

#define GEMAS 100
#define MONEDAS 50

class Collectible {

private:
    uint16_t puntos;

protected:
    explicit Collectible(uint16_t puntos): puntos(puntos) {}

public:
    Collectible(): puntos(0) {}

    uint16_t obtener_puntos() const { return puntos; }
};

class Gema: public Collectible {
public:
    Gema(): Collectible(GEMAS) {}
};

class Moneda: public Collectible {
public:
    Moneda(): Collectible(MONEDAS) {}
};

#endif
