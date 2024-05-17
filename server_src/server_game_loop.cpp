#include "../server_src/server_game_loop.h"

#include <chrono>  // std::chrono()
#include <iostream>
#include <string>

#include "../common_src/common_queue.h"
#include "../server_src/server_juego_mensaje.h"

#define MAX_TAM_COLA 10
#define CINCO_LOOPS_POR_SEGUNDO 200
#define ITERACIONES_PARA_REVIVIR 15

#define MATAR 0x04
#define REVIVIR 0x05

GameLoop::GameLoop():
        client_commands(MAX_TAM_COLA), game() {}

void GameLoop::agregar_queue_server_msg_de_cliente_aceptado(Queue<std::shared_ptr<ServerJuegoMensaje>>& nueva_queue) {
    monitor_lista_de_queues_server_msg.agregar_queue(nueva_queue);
}

void GameLoop::run() {
    try {
        while (true) {
            std::shared_ptr<std::string> accion;
            while (client_commands.try_pop(accion)) {
                if (game.ejecutar_accion(accion)) {
                    broadcastear(MATAR);
                }
            }
            if (game.aumentar_iteraciones()) {
                broadcastear(REVIVIR);
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

void GameLoop::atacar() { client_commands.push(std::make_shared<std::string>("Atacar")); }

void GameLoop::broadcastear(uint8_t tipo_accion) {
    ServerJuegoMensaje mensaje(tipo_accion, game.obtener_cant_vivos(), game.obtener_cant_muertos());
    mensaje.imprimir_mensaje();
    monitor_lista_de_queues_server_msg.broadcastear(mensaje);
}

void GameLoop::dormir() {
    auto milliseconds_to_sleep = std::chrono::milliseconds(CINCO_LOOPS_POR_SEGUNDO);
    std::this_thread::sleep_for(milliseconds_to_sleep);
}

void GameLoop::borrar_queue_server_msg_de_cliente_aceptado(Queue<std::shared_ptr<ServerJuegoMensaje>>& queue) {
    monitor_lista_de_queues_server_msg.borrar_queue(queue);
}

void GameLoop::stop() {
    client_commands.close();
}

GameLoop::~GameLoop() {
}
