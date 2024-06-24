#ifndef YAML_CONFIG_H
#define YAML_CONFIG_H

#include <iostream>
#include <string>
#include <vector>

#include <yaml-cpp/yaml.h>

struct ArmaConfig {
    // cppcheck-suppress unusedStructMember
    uint16_t municion;
    // cppcheck-suppress unusedStructMember
    float vel_dis;
    // cppcheck-suppress unusedStructMember
    float vel_proy;
    // cppcheck-suppress unusedStructMember
    uint16_t dano;
};

struct EnemigoConfig {
    // cppcheck-suppress unusedStructMember
    uint16_t vidas;
    // cppcheck-suppress unusedStructMember
    uint16_t danio;
    // cppcheck-suppress unusedStructMember
    uint16_t puntos;
    // cppcheck-suppress unusedStructMember
    float proba_droppear_municion;
    // cppcheck-suppress unusedStructMember
    float proba_droppear_vida;
    // cppcheck-suppress unusedStructMember
    uint8_t segundos_para_revivir;
};

struct PersonajeConfig {
    // cppcheck-suppress unusedStructMember
    uint16_t pos_x;
    // cppcheck-suppress unusedStructMember
    uint16_t pos_y;
    // cppcheck-suppress unusedStructMember
    uint16_t vidas;
    // cppcheck-suppress unusedStructMember
    uint16_t puntos;
    // cppcheck-suppress unusedStructMember
    uint8_t segundos_para_revivir;
};

struct GameConfig {
    // cppcheck-suppress unusedStructMember
    int minutos_de_partida;
    ArmaConfig arma_inicial;
    ArmaConfig arma1;
    ArmaConfig arma2;
    // cppcheck-suppress unusedStructMember
    uint16_t puntos_gemas;
    // cppcheck-suppress unusedStructMember
    uint16_t puntos_monedas;
    // cppcheck-suppress unusedStructMember
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
