#ifndef PERSONAJE_H
#define PERSONAJE_H

#include<vector>
#include <iostream>
#include <netinet/in.h>

#include "Arma.h"
#include "Puntos.h"
#include "Estado.h"

class Personaje {

    private:
    Puntos puntos;
    int vidas;
    Arma arma;
    Estado estado;

    public:
    Personaje();
    ActivarEspecial();
};

class Jazz  : public Personaje {

    public:
    Jazz();  
};

class Lori  : public Personaje {
    
    public:
    Lori();
};

class Spazz  : public Personaje {
    
    public:
    Spazz();
};

#endif
