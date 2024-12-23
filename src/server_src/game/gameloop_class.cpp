#include "../../include/server_src/game/gameloop_class.h"

#include <chrono>
#include <iostream>
#include <string>

#include "../../include/common_src/catedra/queue.h"
#include "../../include/server_src/game/game_state.h"

#define MAX_TAM_COLA 10000
#define RATE 200
#define SCALE_TIME 1e9

GameLoop::GameLoop(uint16_t nuevo_gameloop_id, std::string& nombre_partida, uint16_t client_id,
                   uint8_t personaje):
        gameloop_id(nuevo_gameloop_id),
        nombre_partida(nombre_partida),
        jugando(false),
        client_commands(MAX_TAM_COLA),
        game(nuevo_gameloop_id, client_id, personaje),
        start_time(std::chrono::high_resolution_clock::now()) {
    iniciar_partida();
}

uint16_t GameLoop::obtener_gameloop_id() { return gameloop_id; }

std::string GameLoop::obtener_nombre_partida() { return nombre_partida; }

Queue<std::shared_ptr<Comando>>& GameLoop::obtener_queue_de_client_commands() {
    return client_commands;
}

void GameLoop::agregar_queue_server_msg_de_cliente_aceptado(
        Queue<std::shared_ptr<GameState>>& nueva_queue) {
    monitor_lista_de_queues_server_msg.agregar_queue(nueva_queue);
}

void GameLoop::agregar_cliente(uint16_t client_id, uint8_t personaje) {
    game.agregar_personaje(client_id, personaje, obtener_tiempo_restante());
}

Game& GameLoop::obtener_game() { return game; }

void GameLoop::iniciar_partida() { jugando = true; }

void GameLoop::terminar_partida() { jugando = false; }

bool GameLoop::obtener_estado_de_partida() { return jugando; }

void GameLoop::run() {
    const std::chrono::nanoseconds rate_ns(static_cast<int>(SCALE_TIME / RATE));
    auto t_0 = std::chrono::high_resolution_clock::now();

    try {
        std::shared_ptr<Comando> comando;
        while (true) {
            // Calculo el tiempo para ver si corto por tiempo limite
            if (obtener_tiempo_restante().count() <= 0) {
                terminar_partida();
                broadcastear();
                std::cout << "Partida " << gameloop_id
                          << " terminada por tiempo límite alcanzado.\n";
                break;
            }

            while (client_commands.try_pop(comando)) {
                if (comando) {
                    comando->ejecutar(game);
                }
            }

            game.actualizar(obtener_tiempo_restante());
            broadcastear();

            // Calculo tiempo para mantener el rate
            auto t_final = std::chrono::high_resolution_clock::now();
            auto duracion = std::chrono::duration_cast<std::chrono::nanoseconds>(t_final - t_0);
            auto rest = rate_ns - duracion;
            if (rest.count() < 0) {
                auto behind = -rest;
                auto lost = behind - behind % rate_ns;
                t_0 += lost;
            }
            std::this_thread::sleep_for(rest);
            t_0 += rate_ns;
        }
    } catch (const ClosedQueue&) {
        return;
    } catch (const std::exception& err) {
        if (!this->is_alive()) {
            return;
        } else {
            std::cerr << "Unexpected exception in GameLoop->run: " << err.what() << "\n";
        }
    } catch (...) {
        std::cerr << "Unexpected exception in GameLoop->run: <unknown>\n";
    }
}

std::chrono::seconds GameLoop::obtener_tiempo_restante() {
    auto current_time = std::chrono::high_resolution_clock::now();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::seconds>(current_time - start_time);
    return std::chrono::seconds((YAMLConfig::getConfig().minutos_de_partida) * 60) - elapsed_time;
}

void GameLoop::broadcastear() {
    if (cantidad_de_clientes() == 0) {
        return;
    }
    GameState nuevo_gamestate(gameloop_id, obtener_estado_de_partida());
    game.crear_nuevo_gamestate(nuevo_gamestate);
    nuevo_gamestate.imprimir_mensaje();
    monitor_lista_de_queues_server_msg.broadcastear(nuevo_gamestate);
}

void GameLoop::borrar_queue_server_msg_de_cliente_aceptado(
        Queue<std::shared_ptr<GameState>>& queue) {
    monitor_lista_de_queues_server_msg.borrar_queue(queue);
}

void GameLoop::borrar_cliente(uint16_t client_id) {
    std::unique_ptr<Comando> comando = std::make_unique<EliminarPersonaje>(client_id, true);
    client_commands.push(
            std::shared_ptr<Comando>(std::move(comando)));  // Como use unique_ptr por la herencia,
                                                            // tengo q convertirlo a shared_ptr
    // game.borrar_personaje(client_id);
}

size_t GameLoop::cantidad_de_clientes() { return game.obtener_cantidad_de_personajes(); }

void GameLoop::stop() { client_commands.close(); }

GameLoop::~GameLoop() {}
