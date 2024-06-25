#include "../../include/server_src/game/game_class.h"

#include <algorithm>  // find_if()
#include <memory>
#include <string>

#include "../../include/server_src/game/game_enemigo.h"
#include "../../include/server_src/game/game_state.h"
#include "../../include/server_src/yaml_config.h"

Game::Game(uint16_t partida_id, uint16_t client_id, uint8_t personaje):
        partida_id(partida_id), escenario() {
    auto personaje_ptr = crear_personaje(
            partida_id, client_id, personaje,
            std::chrono::seconds((YAMLConfig::getConfig().minutos_de_partida) * 60));
    if (personaje_ptr) {
        personajes.push_back(std::shared_ptr<Personaje>(personaje_ptr));
    } else {
        throw std::runtime_error("Tipo de personaje desconocido");
    }
}

std::vector<std::shared_ptr<Personaje>>& Game::obtener_vector_de_personajes() {
    return personajes.get_vector();
}

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

size_t Game::obtener_cantidad_de_personajes() { return personajes.size(); }

bool Game::disparar_municion(uint16_t client_id) {
    if (obtener_personaje(client_id).obtener_municion() == 0) {
        return false;
    } else {
        obtener_personaje(client_id).disparar();
        return true;
    }
}

size_t Game::obtener_cantidad_de_colecionables() { return escenario.obtener_collectibles().size(); }

void Game::chequear_colisiones() {
    for (auto& personaje: this->personajes) {
        chequear_colisiones_personaje_con_enemigo(*personaje);
        chequear_colisiones_balas_con_enemigos(*personaje);
        chequear_colisiones_personaje_con_collectible(*personaje);
    }
}

bool Game::posiciones_estan_en_zona_de_choque(const Posicion& colisionable_uno,
                                              const Posicion& colisionable_dos) {
    const float MARGEN = 0.2f;

    float colisionable_uno_x = colisionable_uno.get_posicion_x();
    float colisionable_uno_y = colisionable_uno.get_posicion_y();

    float colisionable_dos_x = colisionable_dos.get_posicion_x();
    float colisionable_dos_y = colisionable_dos.get_posicion_y();

    // Defino rectángulos alrededor de las posiciones
    float colisionable_uno_min_x = colisionable_uno_x - MARGEN;
    float colisionable_uno_max_x = colisionable_uno_x + MARGEN;
    float colisionable_uno_min_y = colisionable_uno_y - MARGEN;
    float colisionable_uno_max_y = colisionable_uno_y + MARGEN;

    float colisionable_dos_min_x = colisionable_dos_x - MARGEN;
    float colisionable_dos_max_x = colisionable_dos_x + MARGEN;
    float colisionable_dos_min_y = colisionable_dos_y - MARGEN;
    float colisionable_dos_max_y = colisionable_dos_y + MARGEN;

    // Verifico si los rectángulos se superponen
    bool colision_x = colisionable_uno_max_x >= colisionable_dos_min_x &&
                      colisionable_uno_min_x <= colisionable_dos_max_x;
    bool colision_y = colisionable_uno_max_y >= colisionable_dos_min_y &&
                      colisionable_uno_min_y <= colisionable_dos_max_y;

    // Si se superponen en ambos ejes, hay colisión
    return colision_x && colision_y;
}

void Game::chequear_colisiones_personaje_con_enemigo(Personaje& personaje) {
    for (auto& enemigo: obtener_escenario().obtener_enemigos()) {
        if (enemigo->esta_vivo()) {
            if (posiciones_estan_en_zona_de_choque(personaje.obtener_posicion(),
                                                   enemigo->get_posicion_enemigo())) {
                if (personaje.obtener_estado_actual() == (uint8_t)efectos::ACCION_ESPECIAL) {
                    // Todas las acciones especalies causan la muerte del enemigo al tocarlo
                    enemigo->matar();
                    if (enemigo->get_vidas() == 0) {
                        personaje.aumentar_puntos(enemigo->get_puntos());
                    }
                } else {
                    personaje.disminuir_vida(enemigo->get_danio_al_jugador());
                }
            }
        }
    }
}

void Game::chequear_colisiones_balas_con_enemigos(Personaje& personaje) {
    for (auto& enemigo: obtener_escenario().obtener_enemigos()) {
        if (enemigo->esta_vivo()) {
            for (auto& bala: personaje.obtener_balas()) {
                if (posiciones_estan_en_zona_de_choque(bala.obtener_posicion(),
                                                       enemigo->get_posicion_enemigo())) {
                    if (bala.obtener_tipo_bala() == (uint8_t)armas::ARMA_INICIAL) {
                        enemigo->recibir_disparo(YAMLConfig::getConfig().arma_inicial.dano);
                        if (enemigo->get_vidas() == 0) {
                            personaje.aumentar_puntos(enemigo->get_puntos());
                        }
                    } else if (bala.obtener_tipo_bala() == (uint8_t)armas::ARMA_1) {
                        enemigo->recibir_disparo(YAMLConfig::getConfig().arma1.dano);
                        if (enemigo->get_vidas() == 0) {
                            personaje.aumentar_puntos(enemigo->get_puntos());
                        }
                    }
                    personaje.eliminar_bala(bala.obtener_id());
                }
            }
        }
    }
}

void Game::chequear_colisiones_personaje_con_collectible(Personaje& personaje) {
    for (auto& collectible: obtener_escenario().obtener_collectibles()) {
        if (collectible->esta_activo()) {
            if (posiciones_estan_en_zona_de_choque(personaje.obtener_posicion(),
                                                collectible->obtener_posicion())) {
                if (collectible->obtener_tipo_coleccionable() == coleccionables::ZANAHORIA_TIPO) {
                    personaje.aumentar_vida(collectible->obtener_premio());
                } else if (collectible->obtener_tipo_coleccionable() == coleccionables::GEMAS_TIPO) {
                    personaje.aumentar_puntos(collectible->obtener_premio());
                } else if (collectible->obtener_tipo_coleccionable() == coleccionables::MONEDA_TIPO) {
                    personaje.aumentar_puntos(collectible->obtener_premio());
                }

            }
        }
    }
}

void Game::actualizar(std::chrono::seconds tiempo_restante_de_partida) {
    actualizar_personajes(tiempo_restante_de_partida);
    chequear_colisiones();
    actualizar_escenario();
}

void Game::actualizar_personajes(std::chrono::seconds tiempo_restante_de_partida) {
    std::lock_guard<std::mutex> lock(m);
    for (auto& personaje: personajes) {
        if (personaje) {
            personaje->actualizar(tiempo_restante_de_partida,
                                  obtener_escenario().obtener_plataformas_server());
        } else {
            std::cerr << "ERROR en actualizar_personajes" << std::endl;
        }
    }
}

void Game::actualizar_escenario() { return escenario.actualizar_escenario(); }

void Game::crear_nuevo_gamestate(GameState& gamestate) {
    for (const auto& personaje: personajes) {
        if (personaje) {
            auto personaje_id = personaje->obtener_personaje_id();
            gamestate.obtener_diccionario_de_personajes().insert(
                    std::make_pair(personaje_id, std::move(personaje)));
        } else {
            std::cerr << "ERROR en personaje de crear_nuevo_gamestate" << std::endl;
        }
    }

    for (const auto& enemigo: escenario.obtener_enemigos()) {
        if (enemigo->esta_vivo()) {
            auto enemigo_id = enemigo->get_id_enemigo();
            gamestate.obtener_diccionario_de_enemigos().insert(
                    std::make_pair(enemigo_id, std::move(enemigo)));
        } else {
            std::cerr << "ERROR en enemigo de crear_nuevo_gamestate" << std::endl;
        }
    }

    for (const auto& collectible: escenario.obtener_collectibles()) {
        if (collectible->esta_activo()) {
            auto collectible_id = collectible->obtener_id();
            gamestate.obtener_diccionario_de_collectibles().insert(
                    std::make_pair(collectible_id, std::move(collectible)));
        } else {
            std::cerr << "ERROR en collectible de crear_nuevo_gamestate" << std::endl;
        }
    }
}

void Game::agregar_personaje(uint16_t client_id, uint8_t personaje,
                             std::chrono::seconds tiempo_restante_de_partida) {
    std::lock_guard<std::mutex> lock(m);
    auto personaje_ptr =
            crear_personaje(partida_id, client_id, personaje, tiempo_restante_de_partida);
    if (personaje_ptr) {
        personajes.push_back(std::shared_ptr<Personaje>(personaje_ptr));
    } else {
        throw std::runtime_error("Tipo de personaje desconocido");
    }
}

void Game::borrar_personaje(uint16_t client_id) {
    std::lock_guard<std::mutex> lock(m);
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

void Game::cheat_matar_todos_los_enemigos() {
    for (auto& enemigo: escenario.obtener_enemigos()) {
        enemigo->matar();
    }
}

Game::~Game() {}
