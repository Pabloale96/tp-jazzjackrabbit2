#ifndef YAML_CONFIG_H
#define YAML_CONFIG_H

#include <iostream>
#include <string>
#include <vector>

#include <yaml-cpp/yaml.h>

struct ArmaConfig {
    uint16_t municion;
    float vel_dis;
    float vel_proy;
    uint16_t dano;
};

struct EnemigoConfig {
    uint16_t pos_x;
    uint16_t pos_y;
    uint16_t vidas;
    uint16_t danio;
    uint16_t puntos;
};

struct GameConfig {
    int minutos_de_partida;
    ArmaConfig arma_inicial;
    ArmaConfig arma1;
    ArmaConfig arma2;
    uint16_t puntos_gemas;
    uint16_t puntos_monedas;
    int numero_inicial_enemigos;
    std::vector<EnemigoConfig> enemigos;
    uint16_t puntos_iniciales;
    uint16_t vida_inicial;
    uint16_t x_inicial;
    uint16_t y_inicial;
};

class YAMLConfig {
public:
    explicit YAMLConfig(const std::string& filename);
    void loadConfig();
    GameConfig getConfig() const;

private:
    std::string filename;
    GameConfig config;
};


#endif
