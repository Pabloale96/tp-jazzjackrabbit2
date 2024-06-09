#include "../server_src/yaml_config.h"

YAMLConfig::YAMLConfig(const std::string& filename) : filename(filename) {}

void YAMLConfig::loadConfig() {
    YAML::Node configNode = YAML::LoadFile(filename);

    config.minutos_de_partida = configNode["MINUTOS_DE_PARTIDA"].as<int>();
    std::cout << "Minutos de partida: " << config.minutos_de_partida << std::endl;
    
    config.arma_inicial.municion = configNode["MUNICION_ARMA_INICIAL_INFINITA"].as<uint16_t>();
    config.arma_inicial.vel_dis = configNode["VEL_DIS_INICIAL"].as<float>();
    config.arma_inicial.vel_proy = configNode["VEL_PROY_INICIAL"].as<float>();
    config.arma_inicial.dano = configNode["DANO_INICIAL"].as<uint16_t>();

    config.arma1.municion = configNode["MUNICION_ARMA1"].as<uint16_t>();
    config.arma1.vel_dis = configNode["VEL_DIS_ARMA1"].as<uint16_t>();
    config.arma1.vel_proy = configNode["VEL_PROY_ARMA1"].as<uint16_t>();
    config.arma1.dano = configNode["DANO_ARMA1"].as<uint16_t>();

    config.arma2.municion = configNode["MUNICION_ARMA2"].as<uint16_t>();
    config.arma2.vel_dis = configNode["VEL_DIS_ARMA2"].as<uint16_t>();
    config.arma2.vel_proy = configNode["VEL_PROY_ARMA2"].as<uint16_t>();
    config.arma2.dano = configNode["DANO_ARMA2"].as<uint16_t>();

    config.puntos_gemas = configNode["PUNTOS_GEMAS"].as<uint16_t>();
    config.puntos_monedas = configNode["PUNTOS_MONEDAS"].as<uint16_t>();
    config.numero_inicial_enemigos = configNode["NUMERO_INICIAL_ENEMIGOS"].as<int>();

    for (int i = 1; i <= config.numero_inicial_enemigos; ++i) {
        EnemigoConfig enemigo;
        enemigo.pos_x = configNode["POS_x_INICIAL_ENEMIGO_" + std::to_string(i)].as<uint16_t>();
        enemigo.pos_y = configNode["POS_y_INICIAL_ENEMIGO_" + std::to_string(i)].as<uint16_t>();
        enemigo.vidas = configNode["VIDAS_ENEMIGO_" + std::to_string(i)].as<uint16_t>();
        enemigo.danio = configNode["DANIO_ENEMIGO_" + std::to_string(i)].as<uint16_t>();
        enemigo.puntos = configNode["PUNTOS_ENEMIGO_" + std::to_string(i)].as<uint16_t>();
        config.enemigos.push_back(enemigo);
    }

    config.puntos_iniciales = configNode["PUNTOS_INICIALES"].as<uint16_t>();
    config.vida_inicial = configNode["VIDA_INICIAL"].as<uint16_t>();
    config.x_inicial = configNode["X_INICIAL"].as<uint16_t>();
    config.y_inicial = configNode["Y_INICIAL"].as<uint16_t>();
}

GameConfig YAMLConfig::getConfig() const {
    return config;
}
