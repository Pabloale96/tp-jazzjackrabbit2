#ifndef PERSONAJE_H
#define PERSONAJE_H

#include<vector>
#include <iostream>
#include <netinet/in.h>

#include "Arma.h"
#include "Puntos.h"
#include "Estado.h"
#include "Acciones.h"
#include "posicion.h"

class Personaje {

    private:
    int puntos =0;
    int vida =10;
    Arma arma={ArmaInicial};
    Estado estado={Normal};
    Acciones acciones={Acciones};
    Posicion posicion; // para meterlo en un tablero?

    public:
    Personaje();
    ActivarEspecial();
};

class Jazz  : public Personaje {
    public:
    Jazz();
    void ActivarEspecial() override;  
};

class Lori  : public Personaje {
    
    public:
    Lori();
    void ActivarEspecial() override;  
};

class Spazz  : public Personaje {
    
    public:
    Spazz();
    void ActivarEspecial() override;  
};

#endif
