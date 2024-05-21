#include "game_arma.h"

// Arma es la clase arma Inicial, a medida que vaya ganando, pasará a tener las otras armas
Arma::Arma():
        municion(MUNICION_INICIAL),
        vel_dis(VEL_DIS_INICIAL),
        vel_proy(VEL_PROY_INICIAL),
        dano(DANO_INICIAL) {}

Arma1::Arma1() {
    municion = MUNICION_ARMA1;
    vel_dis = VEL_DIS_ARMA1;
    vel_proy = VEL_PROY_ARMA1;
    dano = DANO_ARMA1;
}

Arma2::Arma2() {
    municion = MUNICION_ARMA2;
    vel_dis = VEL_DIS_ARMA2;
    vel_proy = VEL_PROY_ARMA2;
    dano = DANO_ARMA2;
}