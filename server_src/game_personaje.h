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
    int puntos;
    int vida;
    Arma arma;
    Posicion posicion;

public:
    Personaje();

    bool mover(const std::string& direccion);

    Posicion obtener_posicion();

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
