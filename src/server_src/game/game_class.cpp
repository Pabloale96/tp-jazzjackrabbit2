#include "../../include/server_src/game/game_class.h"

#include <algorithm>  // find_if()
#include <memory>
#include <random>
#include <string>

#include "../../include/server_src/game/game_enemigo.h"
#include "../../include/server_src/game/game_state.h"

Game::Game(uint16_t partida_id, uint16_t client_id, uint8_t personaje):
        partida_id(partida_id), enemigos(NUMERO_INICIAL_ENEMIGOS) {
    auto personaje_ptr = crear_personaje(partida_id, client_id, personaje);
    if (personaje_ptr) {
        personajes.push_back(std::shared_ptr<Personaje>(personaje_ptr));
    } else {
        throw std::runtime_error("Tipo de personaje desconocido");
    }

    for (size_t i = 0; i < NUMERO_INICIAL_ENEMIGOS; ++i) {
        enemigos[i] = crear_enemigo_aleatorio();
        enemigos[i]->set_enemigo_id(i + 1);
    }

    // Se setea los valores del esceneario: 

    for (size_t i = 0; i < XMAX; i++)
    {
        Platform plataforma_inicial(i*WIDTH_PLATFORM_TYPE_1/SCALING_VALUE_PIXEL, 0, static_cast<uint16_t>(rot_platform::ROTATE_0),
                WIDTH_PLATFORM_TYPE_1/SCALING_VALUE_PIXEL, HEIGHT_PLATFORM_TYPE_1/SCALING_VALUE_PIXEL, static_cast<uint16_t>(platform::TYPE_1));
        plataformas.push_back(plataforma_inicial);
    }

    Platform plataforma0(70, 40, static_cast<uint16_t>(rot_platform::ROTATE_0),
            WIDTH_PLATFORM_TYPE_1/SCALING_VALUE_PIXEL, HEIGHT_PLATFORM_TYPE_1/SCALING_VALUE_PIXEL, static_cast<uint16_t>(platform::TYPE_1));
    plataformas.push_back(plataforma0);

    Platform platadorma45(70, 40, static_cast<uint16_t>(rot_platform::ROTATE_45),
            WIDTH_PLATFORM_TYPE_1/SCALING_VALUE_PIXEL, HEIGHT_PLATFORM_TYPE_1/SCALING_VALUE_PIXEL, static_cast<uint16_t>(platform::TYPE_1));
    plataformas.push_back(platadorma45);

    Platform plataforma90(70, 40, static_cast<uint16_t>(rot_platform::ROTATE_90),
            WIDTH_PLATFORM_TYPE_1/SCALING_VALUE_PIXEL, HEIGHT_PLATFORM_TYPE_1/SCALING_VALUE_PIXEL, static_cast<uint16_t>(platform::TYPE_1));
    plataformas.push_back(plataforma90);

}

std::unique_ptr<Enemigo> Game::crear_enemigo_aleatorio() {
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

std::vector<std::shared_ptr<Personaje>>& Game::obtener_vector_de_personajes() { return personajes; }

Personaje& Game::obtener_personaje(uint16_t client_id) {
    auto it = std::find_if(personajes.begin(), personajes.end(),
                           [client_id](const std::shared_ptr<Personaje>& personaje) {
                               return personaje->obtener_personaje_id() == client_id;
                           });

    if (it != personajes.end()) {
        return **it;
    } else {
        throw std::runtime_error("No se encontro el personaje en game");
    }
}

bool Game::atacar_enemigo(uint16_t client_id) {
    if (obtener_personaje(client_id).obtener_municion() == 0) {
        return false;
    }
    for (auto& enemigo: enemigos) {
        if (enemigo->esta_vivo()) {
            enemigo->recibir_disparo();
            obtener_personaje(client_id).disminuir_municion();
            return true;
        }
    }
    return false;
}

bool Game::mover(const std::string& direccion, uint16_t client_id) {
    if (obtener_personaje(client_id).mover(direccion)) {
        return true;
    } else {
        return false;
    }
}

void Game::accion_especial(uint16_t client_id) {
    obtener_personaje(client_id).accion_especial();
}


void Game::actualizar_posiciones() {
    actualizar_personajes();
    actualizar_enemigos();
}

void Game::actualizar_personajes() {
    for (auto& personaje: personajes) {
        if (personaje) {
            personaje->actualizar();
        } else {
            std::cerr << "ERROR en actualizar_personajes" << std::endl;
        }
    }
}

void Game::actualizar_enemigos() {
    for (auto& enemigo: enemigos) {
        if (enemigo) {
            enemigo->actualizar();
        } else {
            std::cerr << "ERROR en actualizar_enemigos" << std::endl;
        }
    }
}

void Game::crear_nuevo_gamestate(GameState& gamestate) {
    for (const auto& personaje: personajes) {
        if (personaje) {
            gamestate.obtener_diccionario_de_personajes().insert(
                    std::make_pair(personaje->obtener_personaje_id(), std::move(personaje)));
        } else {
            std::cerr << "ERROR en personaje de crear_nuevo_gamestate" << std::endl;
        }
    }

    for (auto& enemigo: enemigos) {
        if (enemigo) {
            gamestate.obtener_diccionario_de_enemigos().insert(
                    std::make_pair(enemigo->get_id_enemigo(), *enemigo));
        } else {
            std::cerr << "ERROR en enemigo de crear_nuevo_gamestate" << std::endl;
        }
    }
}

void Game::agregar_personaje(uint16_t client_id, uint8_t personaje) {
    auto personaje_ptr = crear_personaje(partida_id, client_id, personaje);
    if (personaje_ptr) {
        personajes.push_back(std::shared_ptr<Personaje>(personaje_ptr));
    } else {
        throw std::runtime_error("Tipo de personaje desconocido");
    }
}

bool Game::aumentar_iteraciones() {
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

void Game::borrar_personaje(uint16_t client_id) {
    auto it = std::find_if(personajes.begin(), personajes.end(),
                           [client_id](const std::shared_ptr<Personaje>& personaje) {
                               return personaje->obtener_personaje_id() == client_id;
                           });

    if (it != personajes.end()) {
        personajes.erase(it);
        std::cout << "El personaje con client ID " << client_id << " se ha borrado" << std::endl;
    } else {
        throw std::runtime_error("No se encontro el personaje en game");
    }
}

std::vector<Platform> Game::obtener_plataformas() { return plataformas; }

Game::~Game() {}
