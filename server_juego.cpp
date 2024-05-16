#include "server_juego.h"

#include <chrono>  // std::chrono()
#include <iostream>
#include <string>

#include "common_queue.h"
#include "server_juego_mensaje.h"

#define MAX_TAM_COLA 10
#define CINCO_LOOPS_POR_SEGUNDO 200
#define ITERACIONES_PARA_REVIVIR 15
#define NUMERO_INICIAL_ENEMIGOS 5

#define MATAR 0x04
#define REVIVIR 0x05

Juego::Juego():
        client_commands(new Queue<std::string>(MAX_TAM_COLA)), enemigos(NUMERO_INICIAL_ENEMIGOS) {}

void Juego::agregar_queue_server_msg_de_cliente_aceptado(Queue<ServerJuegoMensaje>* nueva_queue) {
    monitor_lista_de_queues_server_msg.agregar_queue(nueva_queue);
}

void Juego::run() {
    try {
        while (true) {
            std::string accion;
            while (client_commands->try_pop(accion)) {
                if (accion == "Atacar") {
                    if (matar_enemigo()) {
                        broadcastear(MATAR);
                    }
                }
            }
            if (aumentar_iteraciones()) {
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

void Juego::atacar() { client_commands->push("Atacar"); }

bool Juego::matar_enemigo() {
    for (auto& enemigo: enemigos) {
        if (enemigo.esta_vivo()) {
            enemigo.matar_enemigo();
            return true;
        }
    }
    return false;
}

bool Juego::aumentar_iteraciones() {
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

uint16_t Juego::obtener_cant_vivos() {
    uint16_t cant_vivos = 0;
    for (auto& enemigo: enemigos) {
        if (enemigo.esta_vivo()) {
            cant_vivos++;
        }
    }
    return cant_vivos;
}

uint16_t Juego::obtener_cant_muertos() {
    uint16_t cant_muertos = 0;
    for (auto& enemigo: enemigos) {
        if (!enemigo.esta_vivo()) {
            cant_muertos++;
        }
    }
    return cant_muertos;
}

void Juego::broadcastear(uint8_t tipo_accion) {
    ServerJuegoMensaje mensaje(tipo_accion, obtener_cant_vivos(), obtener_cant_muertos());
    mensaje.imprimir_mensaje();
    monitor_lista_de_queues_server_msg.broadcastear(mensaje);
}

void Juego::dormir() {
    auto milliseconds_to_sleep = std::chrono::milliseconds(CINCO_LOOPS_POR_SEGUNDO);
    std::this_thread::sleep_for(milliseconds_to_sleep);
}

void Juego::borrar_queue_server_msg_de_cliente_aceptado(Queue<ServerJuegoMensaje>* queue) {
    monitor_lista_de_queues_server_msg.borrar_queue(queue);
}

void Juego::stop() {
    if (client_commands) {
        client_commands->close();
    }
}

Juego::~Juego() {
    if (client_commands) {
        delete client_commands;
    }
}
