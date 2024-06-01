#ifndef _GAME_ARMA_H_
#define _GAME_ARMA_H_

#include <iostream>
#include <string>
#include <vector>

#define MUNICION_ARMA_INICIAL_INFINITA 10000
#define VEL_DIS_INICIAL 0
#define VEL_PROY_INICIAL 0
#define DANO_INICIAL 0

#define MUNICION_ARMA1 10
#define VEL_DIS_ARMA1 10
#define VEL_PROY_ARMA1 10
#define DANO_ARMA1 10

#define MUNICION_ARMA2 20
#define VEL_DIS_ARMA2 20
#define VEL_PROY_ARMA2 20
#define DANO_ARMA2 20

class Arma {
protected:
    std::string nombre_arma;
    uint16_t municion;
    float vel_dis;
    float vel_proy;
    float dano;

public:
    Arma();

    std::string obtener_nombre_arma() const { return nombre_arma; }

    uint16_t obtener_municion() const { return municion; }

    void disminuir_municion() {
        if (nombre_arma == "Inicial") {
            // El arma inicial tiene municion infinita
            return;
        } else {
            municion--;
        }
    }

    virtual ~Arma() = default;
};

class Arma1: public Arma {
public:
    Arma1();
};

class Arma2: public Arma {
public:
    Arma2();
};

#endif
