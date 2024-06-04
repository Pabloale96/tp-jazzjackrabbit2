#include "../../include/server_src/game/game_arma.h"

// Arma es la clase arma Inicial, a medida que vaya ganando, pasará a tener las otras armas
Arma::Arma():
        nombre_arma(0x01),
        municion(MUNICION_ARMA_INICIAL_INFINITA),
        vel_dis(VEL_DIS_INICIAL),
        vel_proy(VEL_PROY_INICIAL),
        dano(DANO_INICIAL) {}

Arma1::Arma1() {
    nombre_arma = 0x02;
    municion = MUNICION_ARMA1;
    vel_dis = VEL_DIS_ARMA1;
    vel_proy = VEL_PROY_ARMA1;
    dano = DANO_ARMA1;
}

Arma2::Arma2() {
    nombre_arma = 0x03;
    municion = MUNICION_ARMA2;
    vel_dis = VEL_DIS_ARMA2;
    vel_proy = VEL_PROY_ARMA2;
    dano = DANO_ARMA2;
}