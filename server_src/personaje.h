#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <vector>
#include <iostream>
#include <netinet/in.h>

#include "Arma.h"
#include "Puntos.h"
#include "Estado.h"
#include "Acciones.h"
#include "posicion.h"

#define PUNTOS_INICIALES 0
#define VIDA_INICIAL 10

class Personaje {

    private:
    int puntos;
    int vida;
    Arma arma;
    Estado estado;
    Acciones acciones;
    Posicion posicion; // para meterlo en un tablero?

    public:
    explicit Personaje();
    virtual void activarEspecial();
};

class Jazz  : public Personaje {
    public:
    Jazz();
    void activarEspecial() override;  
};

class Lori  : public Personaje {
    
    public:
    Lori();
    void activarEspecial() override;  
};

class Spazz  : public Personaje {
    
    public:
    Spazz();
    void activarEspecial() override;  
};

#endif
