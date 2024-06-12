#include "../../include/server_src/game/game_class.h"

#include <algorithm>  // find_if()
#include <memory>
#include <string>

#include "../../include/server_src/game/game_enemigo.h"
#include "../../include/server_src/game/game_state.h"

Game::Game(uint16_t partida_id, uint16_t client_id, uint8_t personaje):
        partida_id(partida_id), escenario() {
    auto personaje_ptr = crear_personaje(partida_id, client_id, personaje);
    if (personaje_ptr) {
        personajes.push_back(std::shared_ptr<Personaje>(personaje_ptr));
    } else {
        throw std::runtime_error("Tipo de personaje desconocido");
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

bool Game::disparar_municion(uint16_t client_id) {
    if (obtener_personaje(client_id).obtener_municion() == 0) {
        return false;
    } else {
        obtener_personaje(client_id).disparar();
        return true;
    }
}

bool Game::mover(const std::string& direccion, uint16_t client_id) {
    if (obtener_personaje(client_id).mover(direccion)) {
        return true;
    } else {
        return false;
    }
}

void Game::accion_especial(uint16_t client_id) { obtener_personaje(client_id).accion_especial(); }

void Game::chequear_colisiones() {
    for (auto& personaje: this->personajes) {
        for (auto& enemigo: obtener_escenario().obtener_enemigos()) {
            if (personaje->obtener_posicion() == enemigo->get_posicion_enemigo()) {
                personaje->disminuir_vida(enemigo->get_danio_al_jugador());
            }
        }
        for (auto& enemigo: obtener_escenario().obtener_enemigos()) {
            for (auto& bala: personaje->obtener_balas()) {
                if (bala.obtener_posicion() == enemigo->get_posicion_enemigo()) {
                    if (bala.obtener_tipo_bala() == (uint8_t)armas::ARMA_INICIAL) {
                        enemigo->recibir_disparo(DANO_INICIAL);
                    } else if (bala.obtener_tipo_bala() == (uint8_t)armas::ARMA_SECUNDARIA) {
                        enemigo->recibir_disparo(DANO_ARMA1);
                    }
                    personaje->eliminar_bala(bala.obtener_id());
                }
            }
        }
        for (auto& collectible: obtener_escenario().obtener_collectibles()) {
            if (personaje->obtener_posicion() == collectible->obtener_posicion()) {
                // TODO: Implementar collectibles
                std::cout << "COLLECTIBLE" << std::endl;
                // personaje->aumentar_municion();
                // personaje->aumentar_vida();
                // personaje->aumentar_puntos();
                // collectible->desaparecer();
            }
        }
    }
}

void Game::actualizar() {
    chequear_colisiones();
    actualizar_personajes();
    actualizar_escenario();
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

void Game::actualizar_escenario() { return escenario.actualizar_escenario(); }

void Game::crear_nuevo_gamestate(GameState& gamestate) {
    for (const auto& personaje: personajes) {
        if (personaje) {
            gamestate.obtener_diccionario_de_personajes().insert(
                    std::make_pair(personaje->obtener_personaje_id(), std::move(personaje)));
        } else {
            std::cerr << "ERROR en personaje de crear_nuevo_gamestate" << std::endl;
        }
    }

    for (auto& enemigo: escenario.obtener_enemigos()) {
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

GameEscenario& Game::obtener_escenario() { return escenario; }

Game::~Game() {}
