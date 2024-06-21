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
            std::chrono::seconds((YAMLConfig::getConfig().minutos_de_partida)) * 60);
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

void Game::chequear_colisiones() {
    for (auto& personaje: this->personajes) {
        chequear_colisiones_personaje_con_plataforma(*personaje);
        chequear_colisiones_personaje_con_enemigo(*personaje);
        chequear_colisiones_balas_con_enemigos(*personaje);
        chequear_colisiones_personaje_con_collectible(*personaje);
    }
}

void Game::chequear_colisiones_personaje_con_plataforma(Personaje& personaje) {
    for (const auto& plataforma: obtener_escenario().obtener_plataformas_server()) {
        bool colision = false;
        switch (plataforma.obtener_tipo_plataforma()) {
            case platform::HORIZONTAL:
                colision = colision_horizontal(personaje, plataforma);
                if (colision) {
                    std::cout << "COLISION HORIZONTAL" << std::endl;
                    personaje.setear_posicion_en_y(
                            plataforma.obtener_vertice_izq_arriba().get_posicion_y());
                    personaje.obtener_velocidad().setear_velocidad_y(0);
                }
                break;

            case platform::VERTICAL:
                if (personaje.obtener_velocidad().obtener_velocidad_x() > 0) {
                    colision = colision_vertical_por_izquierda(personaje, plataforma);
                    if (colision) {
                        std::cout << "COLISION VERTICAL IZQUIERDA "
                                  << personaje.obtener_posicion().get_posicion_x() << std::endl;
                        personaje.setear_posicion_en_x(
                                personaje.obtener_posicion().get_posicion_x() - 0.1);
                    }
                } else {
                    colision = colision_vertical_por_derecha(personaje, plataforma);
                    if (colision) {
                        std::cout << "COLISION VERTICAL DERECHA" << std::endl;
                        personaje.setear_posicion_en_x(
                                personaje.obtener_posicion().get_posicion_x() + 0.5);
                    }
                }
                personaje.obtener_velocidad().setear_velocidad_x(0);
                break;

            case platform::DIAGONAL:
                colision = colision_diagonal(personaje, plataforma);
                if (colision) {
                    std::cout << "COLISION DIAGONAL" << std::endl;
                    personaje.setear_posicion_en_y(
                            plataforma.obtener_vertice_izq_arriba().get_posicion_y());
                    personaje.obtener_velocidad().setear_velocidad_x(0);
                    personaje.obtener_velocidad().setear_velocidad_y(0);
                }
                break;
        }
    }
}

bool Game::colision_horizontal(const Personaje& personaje, const Plataforma& plataforma) {
    return personaje.getRight() > plataforma.obtener_vertice_izq_abajo().get_posicion_x() &&
           personaje.getLeft() < plataforma.obtener_vertice_der_abajo().get_posicion_x() &&
           personaje.getBottom() >= plataforma.obtener_vertice_izq_arriba().get_posicion_y() &&
           personaje.getTop() <= plataforma.obtener_vertice_izq_abajo().get_posicion_y();
}

bool Game::colision_vertical_por_izquierda(const Personaje& personaje,
                                           const Plataforma& plataforma) {
    if (personaje.getBottom() >= plataforma.obtener_vertice_izq_abajo().get_posicion_y() &&
        personaje.getTop() <= plataforma.obtener_vertice_izq_arriba().get_posicion_y()) {
        // Estoy entre la altura de la plataforma
        if (personaje.getRight() >= plataforma.obtener_vertice_izq_abajo().get_posicion_x()) {
            return true;
        }
    }
    return false;
}

bool Game::colision_vertical_por_derecha(const Personaje& personaje, const Plataforma& plataforma) {
    if (personaje.getBottom() >= plataforma.obtener_vertice_der_abajo().get_posicion_y() &&
        personaje.getTop() <= plataforma.obtener_vertice_der_arriba().get_posicion_y()) {
        if (plataforma.obtener_vertice_der_abajo().get_posicion_x() + 1 <= personaje.getLeft()) {
            return true;
        }
    }
    return false;
}

bool Game::colision_diagonal(const Personaje& personaje, const Plataforma& plataforma) {
    float personajeCenterX = personaje.getLeft() + personaje.obtener_ancho() / 2;
    float personajeBottomY = personaje.getBottom();

    float plataformaStartX = plataforma.obtener_vertice_izq_abajo().get_posicion_x();
    float plataformaEndX = plataforma.obtener_vertice_der_abajo().get_posicion_x();
    float plataformaStartY = plataforma.obtener_vertice_izq_abajo().get_posicion_y();
    float plataformaEndY = plataforma.obtener_vertice_der_arriba().get_posicion_y();

    float m = (plataformaEndY - plataformaStartY) / (plataformaEndX - plataformaStartX);
    float b = plataformaStartY - m * plataformaStartX;

    float plataformaYatJugadorX = m * personajeCenterX + b;

    bool interseca = personajeBottomY >= plataformaYatJugadorX &&
                     personajeBottomY <= plataformaYatJugadorX + 1 &&
                     personajeCenterX >= plataformaStartX && personajeCenterX <= plataformaEndX;

    return interseca;
}


void Game::chequear_colisiones_personaje_con_enemigo(Personaje& personaje) {
    for (auto& enemigo: obtener_escenario().obtener_enemigos()) {
        if (personaje.obtener_posicion() == enemigo->get_posicion_enemigo()) {
            if (personaje.obtener_estado_actual() == (uint8_t)efectos::ACCION_ESPECIAL) {
                // Todas las acciones especalies causan la muerte del enemigo al tocarlo
                enemigo->matar();
            } else {
                personaje.disminuir_vida(enemigo->get_danio_al_jugador());
            }
        }
    }
}

void Game::chequear_colisiones_balas_con_enemigos(Personaje& personaje) {
    for (auto& enemigo: obtener_escenario().obtener_enemigos()) {
        for (auto& bala: personaje.obtener_balas()) {
            if (bala.obtener_posicion() == enemigo->get_posicion_enemigo()) {
                if (bala.obtener_tipo_bala() == (uint8_t)armas::ARMA_INICIAL) {
                    enemigo->recibir_disparo(YAMLConfig::getConfig().arma_inicial.dano);
                } else if (bala.obtener_tipo_bala() == (uint8_t)armas::ARMA_1) {
                    enemigo->recibir_disparo(YAMLConfig::getConfig().arma1.dano);
                }
                personaje.eliminar_bala(bala.obtener_id());
            }
        }
    }
}

void Game::chequear_colisiones_personaje_con_collectible(Personaje& personaje) {
    for (auto& collectible: obtener_escenario().obtener_collectibles()) {
        if (personaje.obtener_posicion() == collectible->obtener_posicion()) {
            // TODO: Implementar collectibles
            // std::cout << "COLLECTIBLE" << std::endl;
            // personaje->aumentar_municion();
            // personaje->aumentar_vida();
            // personaje->aumentar_puntos();
            // collectible->desaparecer();
        }
    }
}

void Game::actualizar(std::chrono::seconds tiempo_restante_de_partida) {
    actualizar_personajes(tiempo_restante_de_partida);
    // chequear_colisiones();
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
