#ifndef ARMA_H
#define ARMA_H

#include <iostream>
#include <vector>

class Enemigos {

private:
    int vida;
    float dano;
    float puntos;
    float time_revive;
    float prob_municion;
    float prob_vida;

public:
    Enemigos();
};

class Enemigos1: public Enemigos {};

class Enemigos2: public Enemigos {};

class Enemigos3: public Enemigos {};

#endif
