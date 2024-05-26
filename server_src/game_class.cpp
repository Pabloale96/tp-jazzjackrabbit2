#include "../server_src/game_class.h"

#include <memory>
#include <string>

#include "../server_src/game_enemigo.h"
#include "../server_src/game_state.h"

Game::Game(uint16_t client_id): enemigos(NUMERO_INICIAL_ENEMIGOS) {
    personajes.push_back(Personaje(client_id));
}

std::vector<Personaje> Game::obtener_vector_de_personajes() { return personajes; }

Personaje& Game::obtener_personaje(uint16_t client_id) {
    for (auto& personaje: personajes) {
        if (personaje.obtener_personaje_id() == client_id) {
            return personaje;
        }
    }
    throw std::runtime_error("No se encontro el personaje");
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
    std::vector<Personaje> personajes = obtener_vector_de_personajes();
    for (auto& personaje: personajes) {
        gamestate.obtener_diccionario_de_personajes().insert(
                std::make_pair(personaje.obtener_personaje_id(), personaje));
    }
    /*
    for (auto& enemigo: enemigos) {
        gamestate.obtener_diccionario_de_personajes().insert(
                std::make_pair(enemigo.obtener_enemigo_id(), enemigo));
    }*/

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

Game::~Game() {}
