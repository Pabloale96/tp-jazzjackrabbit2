#ifndef _GAME_COLLECTIBLE_H_
#define _GAME_COLLECTIBLE_H_

#include <iostream>
#include <vector>

#define PUNTOS_GEMAS 100
#define PUNTOS_MONEDAS 50

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
    Gema(): Collectible(PUNTOS_GEMAS) {}
};

class Moneda: public Collectible {
public:
    Moneda(): Collectible(PUNTOS_MONEDAS) {}
};

#endif
