#include "game_escenario.h"

#include <random>

#include "protocol_utils.h"

GameEscenario::GameEscenario(): enemigos(NUMERO_INICIAL_ENEMIGOS) {

    // Creo los enemigos iniciales
    for (size_t i = 0; i < NUMERO_INICIAL_ENEMIGOS; ++i) {
        enemigos[i] = crear_enemigo_aleatorio();
        enemigos[i]->set_enemigo_id(i + 1);
    }

    // Agrego 5 monedas y 1 zanahoria en la primera plataforma
    for (size_t i = 0; i < MONEDAS_PRIMERA_PLATAFORMA; ++i) {
        Moneda moneda(i + 1, 0);
        collectibles.push_back(std::make_unique<Moneda>(moneda));
    }
    Zanahoria zanahoria(6, 0);
    collectibles.push_back(std::make_unique<Zanahoria>(zanahoria));


    // Creo las plataformas iniciales
    // Se setea los valores del esceneario:

    for (size_t i = 0; i < XMAX; i+=WIDTH_PLATFORM_TYPE_1 / SCALING_VALUE_PIXEL_X) {
        Platform plataforma_inicial(i, 0, static_cast<uint16_t>(rot_platform::ROTATE_0),
                                WIDTH_PLATFORM_TYPE_1 / SCALING_VALUE_PIXEL_X,
                                HEIGHT_PLATFORM_TYPE_1 / SCALING_VALUE_PIXEL_Y,
                                static_cast<uint16_t>(platform::TYPE_1), false);
        plataformas.push_back(plataforma_inicial);
    }
    std::vector<int> x_plataforma_horizontales = {20,20,60,100,130,170,180,180};
    std::vector<int> y_plataforma_horizontales = {3,8,11,5,11,1,8,11};

    for (size_t i = 0; i<  x_plataforma_horizontales.size(); i++)
    {      
        Platform plataforma(x_plataforma_horizontales[i], y_plataforma_horizontales[i], static_cast<uint16_t>(rot_platform::ROTATE_0),
                                WIDTH_PLATFORM_TYPE_1 / SCALING_VALUE_PIXEL_X,
                                HEIGHT_PLATFORM_TYPE_1 / SCALING_VALUE_PIXEL_Y,
                                static_cast<uint16_t>(platform::TYPE_1),false);
        plataformas.push_back(plataforma);
    }

    std::vector<int> x_plataforma_diagonales = {80,160};
    std::vector<int> y_plataforma_diagonales = {6,9};

    for (size_t i = 0; i<  x_plataforma_horizontales.size(); i++)
    {      
        Platform plataforma(x_plataforma_horizontales[i], y_plataforma_horizontales[i], static_cast<uint16_t>(rot_platform::ROTATE_45),
                                WIDTH_PLATFORM_TYPE_1 / SCALING_VALUE_PIXEL_X,
                                HEIGHT_PLATFORM_TYPE_1 / SCALING_VALUE_PIXEL_Y,
                                static_cast<uint16_t>(platform::TYPE_1),false);
        plataformas.push_back(plataforma);
    }

}

std::unique_ptr<Enemigo> GameEscenario::crear_enemigo_aleatorio() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 2);

    int tipoEnemigo = distrib(gen);
    switch (tipoEnemigo) {
        case 0:
            return std::make_unique<Enemigo1>();
        case 1:
            return std::make_unique<Enemigo2>();
        case 2:
            return std::make_unique<Enemigo3>();
        default:
            throw std::runtime_error("Tipo de enemigo desconocido");
    }
}

bool GameEscenario::atacar_enemigo(uint16_t id_enemigo) {
    for (auto& enemigo: enemigos) {
        if (enemigo->get_id_enemigo() == id_enemigo) {
            enemigo->recibir_disparo();
            return true;
        }
    }
    return false;
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

std::vector<std::unique_ptr<Enemigo>>& GameEscenario::obtener_enemigos() { return enemigos; }

std::vector<Platform>& GameEscenario::obtener_plataformas() { return plataformas; }

std::vector<std::unique_ptr<Collectible>>& GameEscenario::obtener_collectibles() {
    return collectibles;
}

GameEscenario::~GameEscenario() = default;
