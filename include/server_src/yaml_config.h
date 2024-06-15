#ifndef YAML_CONFIG_H
#define YAML_CONFIG_H

#include <iostream>
#include <string>
#include <vector>

#include <yaml-cpp/yaml.h>

struct ArmaConfig {
    uint16_t municion;
    int vel_dis;
    int vel_proy;
    uint16_t dano;
};

struct EnemigoConfig {
    uint16_t vidas;
    uint16_t danio;
    uint16_t puntos;
    float proba_droppear_municion;
    float proba_droppear_vida;
    uint8_t segundos_para_revivir;
};

struct PersonajeConfig {
    uint16_t pos_x;
    uint16_t pos_y;
    uint16_t vidas;
    uint16_t puntos;
    uint8_t segundos_para_revivir;
};

struct GameConfig {
    int minutos_de_partida;
    ArmaConfig arma_inicial;
    ArmaConfig arma1;
    ArmaConfig arma2;
    uint16_t puntos_gemas;
    uint16_t puntos_monedas;
    uint16_t vidas_zanahorias;
    EnemigoConfig enemigo_1;
    EnemigoConfig enemigo_2;
    EnemigoConfig enemigo_3;
    PersonajeConfig personaje;
};

class YAMLConfig {
private:
    std::string filename;
    static GameConfig config;

    explicit YAMLConfig(const std::string& filename);
    YAMLConfig(const YAMLConfig&) = delete;
    YAMLConfig& operator=(const YAMLConfig&) = delete;

public:
    static YAMLConfig& getInstance(const std::string& filename);
    void loadConfig();
    static GameConfig& getConfig();
};

#endif
