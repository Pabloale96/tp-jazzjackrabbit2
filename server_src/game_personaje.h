#ifndef _GAME_PERSONAJE_H_
#define _GAME_PERSONAJE_H_

#include <iostream>
#include <string>
#include <vector>

#include "game_arma.h"
#include "game_posicion.h"

#define PUNTOS_INICIALES 0
#define VIDA_INICIAL 10

class Personaje {

private:
    uint16_t personaje_id;
    int puntos;
    int vida;
    Arma arma;
    Posicion posicion;

public:
    explicit Personaje(uint16_t nuevo_gameloop_id);

    bool mover(const std::string& direccion);

    Posicion obtener_posicion();

    uint16_t obtener_personaje_id();

    // virtual void activarEspecial() = 0;

    // virtual ~Personaje() = default;
};

/*
class Jazz: public Personaje {
public:
    void activarEspecial() override;
};

class Lori: public Personaje {

public:
    void activarEspecial() override;
};

class Spazz: public Personaje {

public:
    void activarEspecial() override;
};
*/

#endif
