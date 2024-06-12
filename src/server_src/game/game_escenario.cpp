#include "game_escenario.h"

#include <random>

#include "protocol_utils.h"

GameEscenario::GameEscenario() {
    std::cout << "Creando escenario" << std::endl;
    cargar_plataformas();
    cargar_enemigos();
    cargar_collectibles();
}

void GameEscenario::cargar_plataformas() {
    // Creo las plataformas iniciales
    // Se setea los valores del esceneario:
    // for (size_t i = 0; i < XMAX; i+=WIDTH_PLATFORM_TYPE_1/ SCALING_VALUE_PIXEL) {
    Platform plataforma_inicial(0, 0, static_cast<uint16_t>(rot_platform::ROTATE_0),
                                WIDTH_PLATFORM_TYPE_1 / SCALING_VALUE_PIXEL,
                                HEIGHT_PLATFORM_TYPE_1 / SCALING_VALUE_PIXEL,
                                static_cast<uint16_t>(platform::TYPE_1));
    //}
}

void GameEscenario::cargar_enemigos() {
    // Creo los enemigos iniciales
    for (uint16_t i = 0; i < NUMERO_INICIAL_ENEMIGOS; ++i) {
        crear_enemigo_aleatorio(i+1);
    }
}

void GameEscenario::cargar_collectibles() {
    for (size_t i = 0; i < MONEDAS_PRIMERA_PLATAFORMA; ++i) {
        Moneda moneda(i + 1, 0);
        collectibles.push_back(std::make_unique<Moneda>(moneda));
    }
    Zanahoria zanahoria(6, 0);
    collectibles.push_back(std::make_unique<Zanahoria>(zanahoria));
}

void GameEscenario::crear_enemigo_aleatorio(uint16_t id_enemigo) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 2);

    int tipoEnemigo = distrib(gen);
    std::cout << "Creando enemigo tipo " << tipoEnemigo << std::endl;
    switch (tipoEnemigo) {
        case 0:
            enemigos.push_back(std::make_unique<Enemigo1>(id_enemigo));
            return;
        case 1:
            enemigos.push_back(std::make_unique<Enemigo2>(id_enemigo));
            return;
        case 2:
            enemigos.push_back(std::make_unique<Enemigo3>(id_enemigo));
            return;
        default:
            throw std::runtime_error("Tipo de enemigo desconocido");
    }
}

void GameEscenario::actualizar_escenario() {
    actualizar_enemigos();
    actualizar_collectibles();
}

void GameEscenario::actualizar_enemigos() {
    for (auto& enemigo: enemigos) {
        if (enemigo) {
            enemigo->actualizar();
        } else {
            std::cerr << "ERROR en actualizar_enemigos" << std::endl;
        }
    }
}

bool GameEscenario::aumentar_iteraciones() {
    for (auto& enemigo: enemigos) {
        if (!enemigo->esta_vivo()) {
            enemigo->aumentar_iteraciones();
            if (enemigo->esta_vivo()) {
                return true;
            }
        }
    }
    return false;
}

void GameEscenario::actualizar_collectibles() {
    for (auto& collectible: collectibles) {
        if (collectible) {
            // collectible->actualizar();
        } else {
            std::cerr << "ERROR en actualizar_collectibles" << std::endl;
        }
    }
}

std::vector<std::shared_ptr<Enemigo>>& GameEscenario::obtener_enemigos() { return enemigos.get_vector(); }

std::vector<Platform>& GameEscenario::obtener_plataformas() { return plataformas; }

std::vector<std::shared_ptr<Collectible>>& GameEscenario::obtener_collectibles() {
    return collectibles.get_vector();
}

GameEscenario::~GameEscenario() = default;
