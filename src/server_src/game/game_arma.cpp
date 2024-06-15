#include "../../include/server_src/game/game_arma.h"
#include "../../include/server_src/yaml_config.h"

// Arma es la clase arma Inicial, a medida que vaya ganando, pasará a tener las otras armas
Arma::Arma():
        nombre_arma(0x01),
        cant_municiones(YAMLConfig::getConfig().arma_inicial.municion),
        vel_dis(YAMLConfig::getConfig().arma_inicial.vel_dis),
        vel_proy(YAMLConfig::getConfig().arma_inicial.vel_proy),
        dano(YAMLConfig::getConfig().arma_inicial.dano) {}

Arma1::Arma1() {
    nombre_arma = 0x02;
    cant_municiones = YAMLConfig::getConfig().arma1.municion;
    vel_dis = YAMLConfig::getConfig().arma_inicial.vel_dis;
    vel_proy = YAMLConfig::getConfig().arma_inicial.vel_proy;
    dano = YAMLConfig::getConfig().arma_inicial.dano;
}

Arma2::Arma2() {
    nombre_arma = 0x03;
    cant_municiones = YAMLConfig::getConfig().arma2.municion;
    vel_dis = YAMLConfig::getConfig().arma2.vel_dis;
    vel_proy = YAMLConfig::getConfig().arma2.vel_proy;
    dano = YAMLConfig::getConfig().arma2.dano;
}
