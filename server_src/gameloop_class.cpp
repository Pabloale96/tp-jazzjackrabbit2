#include "../server_src/gameloop_class.h"

#include <chrono>  // std::chrono()
#include <iostream>
#include <string>

#include "../common_src/common_queue.h"
#include "../server_src/game_state.h"

#define MAX_TAM_COLA 10
#define CINCO_LOOPS_POR_SEGUNDO 200
#define ITERACIONES_PARA_REVIVIR 15

#define MATAR 0x04
#define REVIVIR 0x05

GameLoop::GameLoop(uint16_t nuevo_gameloop_id):
        client_commands(MAX_TAM_COLA), game(nuevo_gameloop_id) {
    client_ids.push_back(nuevo_gameloop_id);
}

Queue<std::shared_ptr<Comando>>& GameLoop::obtener_queue_de_client_commands() {
    return client_commands;
}

void GameLoop::agregar_queue_server_msg_de_cliente_aceptado(
        Queue<std::shared_ptr<GameState>>& nueva_queue) {
    monitor_lista_de_queues_server_msg.agregar_queue(nueva_queue);
}

void GameLoop::run() {
    try {
        while (true) {
            std::shared_ptr<Comando> comando;
            while (client_commands.try_pop(comando)) {
                if (comando && comando->ejecutar(this->game)) {
                    broadcastear();
                }
            }
            // aca deberia actualizar el game state para pasarle al cliente para que renderise
            if (game.aumentar_iteraciones()) {
                broadcastear();
            }
            dormir();
        }
    } catch (const ClosedQueue&) {
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
    GameState mensaje(game.obtener_personaje());
    mensaje.imprimir_mensaje();
    monitor_lista_de_queues_server_msg.broadcastear(mensaje);
}

void GameLoop::dormir() {
    auto milliseconds_to_sleep = std::chrono::milliseconds(CINCO_LOOPS_POR_SEGUNDO);
    std::this_thread::sleep_for(milliseconds_to_sleep);
}

void GameLoop::borrar_queue_server_msg_de_cliente_aceptado(
        Queue<std::shared_ptr<GameState>>& queue) {
    monitor_lista_de_queues_server_msg.borrar_queue(queue);
}

void GameLoop::stop() { client_commands.close(); }

GameLoop::~GameLoop() {}
