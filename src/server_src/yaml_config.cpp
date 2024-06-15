#include "../server_src/yaml_config.h"

// Inicializo la variable estatica
GameConfig YAMLConfig::config;

YAMLConfig::YAMLConfig(const std::string& filename): filename(filename) {}

YAMLConfig& YAMLConfig::getInstance(const std::string& filename) {
    static YAMLConfig instance(filename);
    return instance;
}

void YAMLConfig::loadConfig() {
    try {
        YAML::Node configNode = YAML::LoadFile(filename);

        // **** Configuracion del juego ****
        config.minutos_de_partida = configNode["MINUTOS_DE_PARTIDA"].as<int>();


        // **** Configuracion de las armas ****
        // **** Configuracion del arma Inicial ****
        config.arma_inicial.municion = configNode["MUNICION_ARMA_INICIAL_INFINITA"].as<uint16_t>();
        config.arma_inicial.vel_dis = configNode["VEL_DIS_INICIAL"].as<int>();
        config.arma_inicial.vel_proy = configNode["VEL_PROY_INICIAL"].as<int>();
        config.arma_inicial.dano = configNode["DANO_INICIAL"].as<uint16_t>();

        // **** Configuracion del arma 1 ****
        config.arma1.municion = configNode["MUNICION_ARMA1"].as<uint16_t>();
        config.arma1.vel_dis = configNode["VEL_DIS_ARMA1"].as<int>();
        config.arma1.vel_proy = configNode["VEL_PROY_ARMA1"].as<int>();
        config.arma1.dano = configNode["DANO_ARMA1"].as<uint16_t>();

        // **** Configuracion del arma 2 ****
        config.arma2.municion = configNode["MUNICION_ARMA2"].as<uint16_t>();
        config.arma2.vel_dis = configNode["VEL_DIS_ARMA2"].as<int>();
        config.arma2.vel_proy = configNode["VEL_PROY_ARMA2"].as<int>();
        config.arma2.dano = configNode["DANO_ARMA2"].as<uint16_t>();


        // **** Configuracion de los coleccionables ****
        config.puntos_gemas = configNode["PUNTOS_GEMAS"].as<uint16_t>();
        config.puntos_monedas = configNode["PUNTOS_MONEDAS"].as<uint16_t>();
        config.vidas_zanahorias = configNode["VIDAS_ZANAHORIAS"].as<uint16_t>();


        // **** Configuracion de los enemigos ****
        // **** Configuracion del enemigo 1 ****
        config.enemigo_1.vidas = configNode["VIDAS_ENEMIGO_1"].as<uint16_t>();
        config.enemigo_1.danio = configNode["DANIO_ENEMIGO_1"].as<uint16_t>();
        config.enemigo_1.puntos = configNode["PUNTOS_ENEMIGO_1"].as<uint16_t>();
        config.enemigo_1.proba_droppear_municion =
                configNode["PROBA_DROPPEAR_MUNICION_ENEMIGO_1"].as<float>();
        config.enemigo_1.proba_droppear_vida =
                configNode["PROBA_DROPPEAR_VIDA_ENEMIGO_1"].as<float>();
        config.enemigo_1.segundos_para_revivir =
                configNode["SEGUNDOS_PARA_REVIVIR_ENEMIGO_1"].as<uint8_t>();

        // **** Configuracion del enemigo 2 ****
        config.enemigo_2.vidas = configNode["VIDAS_ENEMIGO_2"].as<uint16_t>();
        config.enemigo_2.danio = configNode["DANIO_ENEMIGO_2"].as<uint16_t>();
        config.enemigo_2.puntos = configNode["PUNTOS_ENEMIGO_2"].as<uint16_t>();
        config.enemigo_2.proba_droppear_municion =
                configNode["PROBA_DROPPEAR_MUNICION_ENEMIGO_2"].as<float>();
        config.enemigo_2.proba_droppear_vida =
                configNode["PROBA_DROPPEAR_VIDA_ENEMIGO_2"].as<float>();
        config.enemigo_2.segundos_para_revivir =
                configNode["SEGUNDOS_PARA_REVIVIR_ENEMIGO_2"].as<uint8_t>();

        // **** Configuracion del enemigo 3 ****
        config.enemigo_3.vidas = configNode["VIDAS_ENEMIGO_3"].as<uint16_t>();
        config.enemigo_3.danio = configNode["DANIO_ENEMIGO_3"].as<uint16_t>();
        config.enemigo_3.puntos = configNode["PUNTOS_ENEMIGO_3"].as<uint16_t>();
        config.enemigo_3.proba_droppear_municion =
                configNode["PROBA_DROPPEAR_MUNICION_ENEMIGO_3"].as<float>();
        config.enemigo_3.proba_droppear_vida =
                configNode["PROBA_DROPPEAR_VIDA_ENEMIGO_3"].as<float>();
        config.enemigo_3.segundos_para_revivir =
                configNode["SEGUNDOS_PARA_REVIVIR_ENEMIGO_3"].as<uint8_t>();


        // **** Configuracion del personaje ****
        config.personaje.puntos = configNode["PUNTOS_INICIALES"].as<uint16_t>();
        config.personaje.vidas = configNode["VIDA_INICIAL"].as<uint16_t>();
        config.personaje.pos_x = configNode["X_INICIAL"].as<uint16_t>();
        config.personaje.pos_y = configNode["Y_INICIAL"].as<uint16_t>();
        config.personaje.segundos_para_revivir =
                configNode["SEGUNDOS_PARA_REVIVIR_PERSONAJE"].as<uint8_t>();

    } catch (const YAML::Exception& e) {
        std::cerr << "Error loading YAML configuration: " << e.what() << std::endl;
        throw;
    }
}

GameConfig& YAMLConfig::getConfig() { return config; }
