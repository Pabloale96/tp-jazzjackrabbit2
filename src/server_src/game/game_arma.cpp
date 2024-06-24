#include "../../include/server_src/game/game_arma.h"

#include "../../include/common_src/protocol_utils.h"
#include "../../include/server_src/yaml_config.h"

Arma::Arma(uint16_t municion, uint8_t nombre, float vel_dis, float vel_proy, uint16_t dano):
        nombre_arma(nombre),
        cant_municiones(municion),
        vel_dis(vel_dis),
        vel_proy(vel_proy),
        dano(dano) {}

uint8_t Arma::obtener_nombre_arma() const { return nombre_arma; }

uint16_t Arma::obtener_municion() const { return cant_municiones; }

void Arma::set_municion(uint16_t municion) { cant_municiones = municion; }

float Arma::obtener_vel_dis() const { return vel_dis; }

float Arma::obtener_vel_proy() const { return vel_proy; }

void Arma::disminuir_municion() {
    if (nombre_arma != 0) {
        cant_municiones--;
    }
}

std::unique_ptr<Arma> Arma::crear_arma(uint16_t municion, uint8_t nombre) {
    switch (nombre) {
        case 1:
            return std::make_unique<Arma1>(municion);
        case 2:
            return std::make_unique<Arma2>(municion);
        default:
            return std::make_unique<ArmaInicial>(municion);
    }
}

ArmaInicial::ArmaInicial():
        Arma(YAMLConfig::getConfig().arma_inicial.municion, (uint8_t)armas::ARMA_INICIAL,
             YAMLConfig::getConfig().arma_inicial.vel_dis,
             YAMLConfig::getConfig().arma_inicial.vel_proy,
             YAMLConfig::getConfig().arma_inicial.dano) {
                std::cout << "ArmaInicial::ArmaInicial()" << std::endl;
                std::cout << "municion: " << YAMLConfig::getConfig().arma_inicial.municion << std::endl;
                std::cout << "vel_dis: " << YAMLConfig::getConfig().arma_inicial.vel_dis << std::endl;
                std::cout << "vel_proy: " << YAMLConfig::getConfig().arma_inicial.vel_proy << std::endl;
             }

ArmaInicial::ArmaInicial(uint16_t municion): ArmaInicial() { set_municion(municion); }

Arma1::Arma1():
        Arma(YAMLConfig::getConfig().arma1.municion, (uint8_t)armas::ARMA_1,
             YAMLConfig::getConfig().arma1.vel_dis, YAMLConfig::getConfig().arma1.vel_proy,
             YAMLConfig::getConfig().arma1.dano) {
                std::cout << "Arma1::Arma1()" << std::endl;
                std::cout << "municion: " << YAMLConfig::getConfig().arma_inicial.municion << std::endl;
                std::cout << "vel_dis: " << YAMLConfig::getConfig().arma_inicial.vel_dis << std::endl;
                std::cout << "vel_proy: " << YAMLConfig::getConfig().arma_inicial.vel_proy << std::endl;
             }

Arma1::Arma1(uint16_t municion): Arma1() { set_municion(municion); }

Arma2::Arma2():
        Arma(YAMLConfig::getConfig().arma2.municion, (uint8_t)armas::ARMA_2,
             YAMLConfig::getConfig().arma2.vel_dis, YAMLConfig::getConfig().arma2.vel_proy,
             YAMLConfig::getConfig().arma2.dano) {}

Arma2::Arma2(uint16_t municion): Arma2() { set_municion(municion); }
