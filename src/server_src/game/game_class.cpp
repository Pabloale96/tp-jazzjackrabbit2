#include "../../include/server_src/game/game_class.h"

#include <algorithm>  // find_if()
#include <memory>
#include <string>

#include "../../include/server_src/game/game_enemigo.h"
#include "../../include/server_src/game/game_state.h"

Game::Game(uint16_t partida_id, uint16_t client_id, uint8_t personaje,
           std::chrono::seconds duracion_de_la_partida):
        partida_id(partida_id), escenario() {
    auto personaje_ptr = crear_personaje(partida_id, client_id, personaje, duracion_de_la_partida);
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
    for (const auto& plataforma: obtener_escenario().obtener_plataformas()) {
        bool colision = false;
        switch (plataforma.obtener_tipo()) {
            case (uint16_t)platform::HORIZONTAL:
                colision = colision_horizontal(personaje, plataforma);
                if (colision) {
                    personaje.obtener_posicion().set_posicion_en_y(plataforma.getTop());
                    personaje.obtener_velocidad().setear_velocidad_y(0);
                }
                break;

            case (uint16_t)platform::VERTICAL:
                colision = colision_vertical(personaje, plataforma);
                if (colision) {
                    if (personaje.obtener_velocidad().obtener_velocidad_x() > 0) {
                        // estaba corriendo hacia la derecha
                        personaje.obtener_posicion().set_posicion_en_x(plataforma.getRight());
                    } else {
                        // estaba corriendo hacia la izquierda
                        personaje.obtener_posicion().set_posicion_en_x(plataforma.getLeft());
                    }
                    personaje.obtener_velocidad().setear_velocidad_x(0);
                }
                break;

            case (uint16_t)platform::DIAGONAL:
                colision = colision_diagonal(personaje, plataforma);
                if (colision) {
                    // Si toca la plataforma diagonal, me muevo hacia arriba
                    // TODO: Implementar movimiento diagonal
                    personaje.obtener_posicion().set_posicion_en_y(plataforma.getTop());
                    personaje.obtener_velocidad().setear_velocidad_y(0);
                }
                break;
        }
    }
}

bool Game::colision_horizontal(const Personaje& personaje, const Platform& plataforma) {
    return personaje.getRight() > plataforma.getLeft() &&
           personaje.getLeft() < plataforma.getRight() &&
           personaje.getBottom() > plataforma.getTop() &&
           personaje.getTop() < plataforma.getBottom();
}

bool Game::colision_vertical(const Personaje& personaje, const Platform& plataforma) {
    return personaje.getRight() > plataforma.getLeft() &&
           personaje.getLeft() < plataforma.getRight() &&
           personaje.getBottom() > plataforma.getTop() &&
           personaje.getTop() < plataforma.getBottom();
}

bool Game::colision_diagonal(const Personaje& personaje, const Platform& plataforma) {
    float personajeCenterX = personaje.getLeft() + personaje.obtener_ancho() / 2;
    float personajeCenterY = personaje.getBottom();
    float plataformaStartX = plataforma.getLeft();
    float plataformaEndX = plataforma.getRight();
    float plataformaStartY = plataforma.getTop();
    float plataformaEndY = plataforma.getBottom();

    // y = mx + b; m = (endY - startY) / (endX - startX)
    float m = (plataformaEndY - plataformaStartY) / (plataformaEndX - plataformaStartX);
    float b = plataformaStartY - m * plataformaStartX;

    // Chequeo si el bottom center del personaje intersecta con la linea diagonal
    float plataformaYatJugadorX = m * personajeCenterX + b;
    return personajeCenterY >= plataformaYatJugadorX && personaje.getBottom() <= plataformaEndY &&
           personaje.getRight() > plataforma.getLeft() &&
           personaje.getLeft() < plataforma.getRight();
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
                    enemigo->recibir_disparo(DANO_INICIAL);
                } else if (bala.obtener_tipo_bala() == (uint8_t)armas::ARMA_SECUNDARIA) {
                    enemigo->recibir_disparo(DANO_ARMA1);
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
            std::cout << "COLLECTIBLE" << std::endl;
            // personaje->aumentar_municion();
            // personaje->aumentar_vida();
            // personaje->aumentar_puntos();
            // collectible->desaparecer();
        }
    }
}

void Game::actualizar(std::chrono::seconds tiempo_restante_de_partida) {
    actualizar_personajes(tiempo_restante_de_partida);
    chequear_colisiones();
    actualizar_escenario();
}

void Game::actualizar_personajes(std::chrono::seconds tiempo_restante_de_partida) {
    for (auto& personaje: personajes) {
        if (personaje) {
            personaje->actualizar(tiempo_restante_de_partida);
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
    auto personaje_ptr =
            crear_personaje(partida_id, client_id, personaje, tiempo_restante_de_partida);
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

void Game::cheat_matar_todos_los_enemigos() {
    for (auto& enemigo: escenario.obtener_enemigos()) {
        enemigo->matar();
    }
}

Game::~Game() {}
