#include "../../include/server_src/game/gameloop_class.h"

#include <chrono>
#include <iostream>
#include <string>

#include "../../include/common_src/queue.h"
#include "../../include/server_src/game/game_state.h"

#define MAX_TAM_COLA 100
#define CINCO_LOOPS_POR_SEGUNDO 200
#define CANT_MAX_SEG_DE_PARTIDA 60  // 1 minuto TODO: agregar al yaml
#define RATE 15

GameLoop::GameLoop(uint16_t nuevo_gameloop_id, std::string& nombre_partida, uint16_t client_id,
                   std::string& personaje):
        gameloop_id(nuevo_gameloop_id),
        nombre_partida(nombre_partida),
        jugando(false),
        client_commands(MAX_TAM_COLA),
        game(nuevo_gameloop_id, client_id, personaje) {
    clients_id.push_back(client_id);
    iniciar_partida();
    broadcastear();  // Para que se vea la posicion inicial del personaje
}

std::string GameLoop::obtener_nombre_partida() { return nombre_partida; }

uint16_t GameLoop::obtener_cantidad_de_clientes() { return clients_id.size(); }

Queue<std::shared_ptr<Comando>>& GameLoop::obtener_queue_de_client_commands() {
    return client_commands;
}

void GameLoop::agregar_queue_server_msg_de_cliente_aceptado(
        Queue<std::shared_ptr<GameState>>& nueva_queue) {
    monitor_lista_de_queues_server_msg.agregar_queue(nueva_queue);
}

void GameLoop::agregar_cliente(uint16_t client_id, const std::string& personaje) {
    game.agregar_personaje(client_id, personaje);
    broadcastear();  // Para que se vea la posicion inicial del personaje
}

Game& GameLoop::obtener_game() { return game; }

void GameLoop::iniciar_partida() { jugando = true; }

void GameLoop::terminar_partida() { jugando = false; }

bool GameLoop::obtener_estado_de_partida() { return jugando; }

void GameLoop::run() {
    auto start_time = std::chrono::steady_clock::now();
    auto max_duration = std::chrono::seconds(CANT_MAX_SEG_DE_PARTIDA);

    // TODO: cambiar a 1e9 (lo dejo grande para poder hacer pruebas)
    const std::chrono::nanoseconds rate_ns(static_cast<int>(1e20 / RATE));
    auto t_0 = std::chrono::high_resolution_clock::now();

    try {
        while (true) {
            // Calculo el tiempo para ver si corto por tiempo limite
            auto current_time = std::chrono::steady_clock::now();
            if (current_time - start_time > max_duration) {
                terminar_partida();
                broadcastear();
                std::cout << "Partida " << gameloop_id
                          << " terminada por tiempo límite alcanzado.\n";
                break;
            }

            std::shared_ptr<Comando> comando;
            while (client_commands.try_pop(comando)) {
                if (comando && comando->ejecutar(this->game)) {
                    broadcastear();
                }
            }
            // TODO: Aca actualizo posiciones de enemigos:
            // game.actualizar_posiciones();
            broadcastear();

            // Calculo tiempo para mantener el rate
            auto t_final = std::chrono::high_resolution_clock::now();
            auto duracion = std::chrono::duration_cast<std::chrono::nanoseconds>(t_final - t_0);
            auto rest = rate_ns - duracion;
            if (rest.count() > 0) {
                std::this_thread::sleep_for(rest);
            }

            // Reseteo el tiempo
            t_0 = std::chrono::high_resolution_clock::now();
        }
    } catch (const ClosedQueue&) {
        std::cout << "GameLoop " << gameloop_id << " cerrado.\n";
        return;
    } catch (const std::exception& err) {
        if (!this->is_alive()) {
            return;
        } else {
            std::cerr << "Unexpected exception in juego->run: " << err.what() << "\n";
        }
    } catch (...) {
        std::cerr << "Unexpected exception in juego->run: <unknown>\n";
    }
}

void GameLoop::broadcastear() {
    GameState nuevo_gamestate(gameloop_id, obtener_estado_de_partida());
    game.crear_nuevo_gamestate(nuevo_gamestate);
    nuevo_gamestate.imprimir_mensaje();
    monitor_lista_de_queues_server_msg.broadcastear(nuevo_gamestate);
}

void GameLoop::dormir() {
    auto milliseconds_to_sleep = std::chrono::milliseconds(CINCO_LOOPS_POR_SEGUNDO);
    std::this_thread::sleep_for(milliseconds_to_sleep);
}

void GameLoop::borrar_queue_server_msg_de_cliente_aceptado(
        Queue<std::shared_ptr<GameState>>& queue) {
    monitor_lista_de_queues_server_msg.borrar_queue(queue);
}

void GameLoop::borrar_cliente(uint16_t client_id) {
    game.borrar_personaje(client_id);
    clients_id.remove(client_id);
}

void GameLoop::stop() { client_commands.close(); }

GameLoop::~GameLoop() {}
