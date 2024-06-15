#ifndef _GAME_COLLECTIBLE_H_
#define _GAME_COLLECTIBLE_H_

#include <iostream>
#include <vector>

#include "../../include/server_src/yaml_config.h"

#include "game_posicion.h"

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
    Gema(uint16_t x, uint16_t y): Collectible(x, y), puntos(YAMLConfig::getConfig().puntos_gemas) {}

    uint16_t obtener_puntos() const { return puntos; }
};

class Moneda: public Collectible {
private:
    uint16_t puntos;

public:
    Moneda(uint16_t x, uint16_t y):
            Collectible(x, y), puntos(YAMLConfig::getConfig().puntos_monedas) {}

    uint16_t obtener_puntos() const { return puntos; }
};

class Zanahoria: public Collectible {
private:
    uint16_t vidas;

public:
    Zanahoria(uint16_t x, uint16_t y):
            Collectible(x, y), vidas(YAMLConfig::getConfig().vidas_zanahorias) {}

    uint16_t obtener_vidas() const { return vidas; }
};

#endif
