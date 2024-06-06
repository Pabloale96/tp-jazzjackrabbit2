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
    uint8_t nombre_arma;
    uint16_t municion;
    float vel_dis;
    float vel_proy;
    float dano;

public:
    Arma();
    Arma(uint16_t municion, uint16_t nombre) {
        this->municion = municion;
        this->nombre_arma = nombre;
        switch (nombre) {
            case 1:
                this->vel_dis = VEL_DIS_ARMA1;
                this->vel_proy = VEL_PROY_ARMA1;
                this->dano = DANO_ARMA1;
                break;
            case 2:
                this->vel_dis = VEL_DIS_ARMA2;
                this->vel_proy = VEL_PROY_ARMA2;
                this->dano = DANO_ARMA2;
                break;
            default:
                this->vel_dis = VEL_DIS_INICIAL;
                this->vel_proy = VEL_PROY_INICIAL;
                this->dano = DANO_INICIAL;
                break;
        }
    }

    uint8_t obtener_nombre_arma() const { return nombre_arma; }

    uint16_t obtener_municion() const { return municion; }

    void disminuir_municion() {
        if (nombre_arma == 0) {
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
