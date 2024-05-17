#ifndef ARMA_H
#define ARMA_H

#include <iostream>
#include <vector>

#define VIDA_INICIAL 10
#define DANO_INICIAL 1
#define PUNTOS_INICIAL 1
#define TIME_REVIVE_INICIAL 50

class Enemigos {

protected:
    int vida;
    int dano;
    int puntos;
    int time_revive;
    float prob_municion;
    float prob_vida;

public:
    Enemigos();
    virtual ~Enemigos() = default;
};

Enemigos::Enemigos():
        vida(VIDA_INICIAL),
        dano(DANO_INICIAL),
        puntos(PUNTOS_INICIAL),
        time_revive(TIME_REVIVE_INICIAL),
        prob_municion(0.0f),
        prob_vida(0.0f) {}


class Enemigos1: public Enemigos {
public:
    Enemigos1();
};

Enemigos1::Enemigos1() {}


class Enemigos2: public Enemigos {
public:
    Enemigos2();
};

Enemigos2::Enemigos2() {}


class Enemigos3: public Enemigos {
public:
    Enemigos3();
};

Enemigos3::Enemigos3() {}

#endif
