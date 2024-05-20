#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <iostream>
#include <vector>

// #include "Accion.h"
// #include "Estado.h"
// #include "Puntos.h"
// #include "arma.h"
#include "posicion.h"

#define PUNTOS_INICIALES 0
#define VIDA_INICIAL 10

class Personaje {

private:
    // int puntos;
    // int vida;
    // Arma arma;
    // Estado estado;
    // Accion accion;
    Posicion posicion;

public:
    Personaje();

    bool mover(const std::string& direccion);

    // virtual void activarEspecial() = 0;

    // virtual ~Personaje() = default;
};

#endif

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
