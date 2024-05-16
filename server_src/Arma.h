#ifndef ARMA_H
#define ARMA_H

#include <iostream>
#include <vector>

#include <netinet/in.h>

#define MUNICION_INICIAL 0
#define VEL_DIS_INICIAL 0
#define VEL_PROY_INICIAL 0
#define DANO_INICIAL 0

class Arma {
private:
    int municion;
    float vel_dis;
    float vel_proy;
    float dano;

public:
    Arma();
};

// Arma es la clase arma Inicial, a medida que vaya ganando, pasará a tener las otras armas
Arma::Arma() {
    municion = MUNICION_INICIAL;
    vel_dis = VEL_DIS_INICIAL;
    vel_proy = VEL_PROY_INICIAL;
    dano = DANO_INICIAL;
}

class Arma1: public Arma {};

class Arma2: public Arma {};

#endif
