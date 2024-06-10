#ifndef _GAME_COLLECTIBLE_H_
#define _GAME_COLLECTIBLE_H_

#include <iostream>
#include <vector>

#include "game_posicion.h"

#define PUNTOS_GEMAS 100
#define PUNTOS_MONEDAS 50
#define VIDAS_ZANAHORIA 5

class Collectible {
private:
    Posicion posicion;

public:
    Collectible(uint16_t x, uint16_t y): posicion(x, y) {}

    // void actualizar();

    void set_posicion(uint16_t x, uint16_t y) { posicion.set_posicion(x, y); }

    Posicion obtener_posicion() const { return posicion; }

    virtual ~Collectible() {}
};

class Gema: public Collectible {
private:
    uint16_t puntos;

public:
    Gema(uint16_t x, uint16_t y): Collectible(x, y), puntos(PUNTOS_GEMAS) {}

    uint16_t obtener_puntos() const { return puntos; }
};

class Moneda: public Collectible {
private:
    uint16_t puntos;

public:
    Moneda(uint16_t x, uint16_t y): Collectible(x, y), puntos(PUNTOS_MONEDAS) {}

    uint16_t obtener_puntos() const { return puntos; }
};

class Zanahoria: public Collectible {
private:
    uint16_t vidas;

public:
    Zanahoria(uint16_t x, uint16_t y): Collectible(x, y), vidas(VIDAS_ZANAHORIA) {}

    uint16_t obtener_vidas() const { return vidas; }
};

#endif
