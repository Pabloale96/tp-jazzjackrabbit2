#ifndef ARMA_H
#define ARMA_H

#include<vector>
#include <iostream>
#include <netinet/in.h>

class Arma {

    private:
    int municion;
    float vel_dis;
    float vel_proy;
    float dano;

    public:
    Arma();
};

class Arma1  : public Arma {

};

class Arma2  : public Arma {

};

class Arma3  : public Arma {
    
};

#endif
