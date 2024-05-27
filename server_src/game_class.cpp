#include "../server_src/game_class.h"

#include <algorithm>  // find_if()
#include <memory>
#include <string>

#include "../server_src/game_enemigo.h"
#include "../server_src/game_state.h"

Game::Game(uint16_t partida_id, uint16_t client_id, const std::string& personaje):
        partida_id(partida_id), enemigos(NUMERO_INICIAL_ENEMIGOS) {
    auto personaje_ptr = crear_personaje(partida_id, client_id, personaje);
    if (personaje_ptr) {
        personajes.push_back(std::unique_ptr<Personaje>(personaje_ptr));
    } else {
        throw std::runtime_error("Tipo de personaje desconocido");
    }
}

std::vector<std::unique_ptr<Personaje>>& Game::obtener_vector_de_personajes() { return personajes; }

Personaje& Game::obtener_personaje(uint16_t client_id) {
    auto it = std::find_if(personajes.begin(), personajes.end(),
                           [client_id](const std::unique_ptr<Personaje>& personaje) {
                               return personaje->obtener_personaje_id() == client_id;
                           });

    if (it != personajes.end()) {
        return **it;
    } else {
        throw std::runtime_error("No se encontro el personaje en game");
    }
}

bool Game::matar_enemigo() {
    for (auto& enemigo: enemigos) {
        if (enemigo.esta_vivo()) {
            enemigo.matar_enemigo();
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

void Game::crear_nuevo_gamestate(GameState& gamestate) {
    for (const auto& personaje: personajes) {
        gamestate.obtener_diccionario_de_personajes().insert(
                std::make_pair(personaje->obtener_personaje_id(), *personaje));
    }
    /*
    for (auto& enemigo: enemigos) {
        gamestate.obtener_diccionario_de_personajes().insert(
                std::make_pair(enemigo.obtener_enemigo_id(), enemigo));
    }*/
}

void Game::agregar_personaje(uint16_t client_id, const std::string& personaje) {
    auto personaje_ptr = crear_personaje(partida_id, client_id, personaje);
    if (personaje_ptr) {
        personajes.push_back(std::unique_ptr<Personaje>(personaje_ptr));
    } else {
        throw std::runtime_error("Tipo de personaje desconocido");
    }
}

bool Game::aumentar_iteraciones() {
    for (auto& enemigo: enemigos) {
        if (!enemigo.esta_vivo()) {
            enemigo.aumentar_iteraciones();
            if (enemigo.esta_vivo()) {
                return true;
            }
        }
    }
    return false;
}

uint16_t Game::obtener_cant_vivos() {
    uint16_t cant_vivos = 0;
    for (auto& enemigo: enemigos) {
        if (enemigo.esta_vivo()) {
            cant_vivos++;
        }
    }
    return cant_vivos;
}

uint16_t Game::obtener_cant_muertos() {
    uint16_t cant_muertos = 0;
    for (auto& enemigo: enemigos) {
        if (!enemigo.esta_vivo()) {
            cant_muertos++;
        }
    }
    return cant_muertos;
}

void Game::borrar_personaje(uint16_t client_id) {
    auto it = std::find_if(personajes.begin(), personajes.end(),
                           [client_id](const std::unique_ptr<Personaje>& personaje) {
                               return personaje->obtener_personaje_id() == client_id;
                           });

    if (it != personajes.end()) {
        personajes.erase(it);
        std::cout << "El personaje con client ID " << client_id << " se ha borrado" << std::endl;
    } else {
        throw std::runtime_error("No se encontro el personaje en game");
    }
}

Game::~Game() {}
