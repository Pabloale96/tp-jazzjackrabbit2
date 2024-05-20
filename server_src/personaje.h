#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <iostream>
#include <vector>

#include "arma.h"
#include "posicion.h"

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
    
    //virtual void activarEspecial() = 0;

    //virtual ~Personaje() = default;
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
