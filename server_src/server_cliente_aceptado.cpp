#include "../server_src/server_cliente_aceptado.h"

#include <utility>  // move()
#include <vector>

#include <sys/socket.h>  // para usar el flag para hacer shutdown del socket

#include "../common_src/common_protocol_utils.h"
#include "../common_src/common_sockets.h"

#define MAX_TAM_COLA 10

ClienteAceptado::ClienteAceptado(Socket&& socket_cliente, GameloopMonitor& gameloop_monitor,
                                 std::list<uint16_t>& lista_de_gameloops_activos):
        protocolo_server(std::move(socket_cliente)),
        was_closed(false),
        lista_de_gameloops_activos(lista_de_gameloops_activos),
        server_msg(MAX_TAM_COLA),
        sender(protocolo_server, was_closed, server_msg),
        receiver(nullptr) {}

void ClienteAceptado::crear_partida(GameloopMonitor& gameloop_monitor,
                                    const std::string& nombre_partida) {
    uint16_t nuevo_gameloop_id = 0;
    nuevo_gameloop_id = gameloop_monitor.agregar_gameloop(nombre_partida);
    gameloop_monitor.obtener_gameloop(nuevo_gameloop_id)
            ->agregar_queue_server_msg_de_cliente_aceptado(server_msg);
    receiver = std::make_unique<ServerReceiver>(protocolo_server, was_closed, gameloop_monitor,
                                                nuevo_gameloop_id);
    lista_de_gameloops_activos.push_back(nuevo_gameloop_id);
    gameloop_id = nuevo_gameloop_id;
    return;
}

void ClienteAceptado::joinearse_a_una_partida(GameloopMonitor& gameloop_monitor) { return; }

void ClienteAceptado::establecer_partida(GameloopMonitor& gameloop_monitor) {
    if (protocolo_server.crear_partida(was_closed) == CREAR_PARTIDA) {
        std::string nombre_partida;
        protocolo_server.recibir_nombre_partida(nombre_partida, was_closed);
        crear_partida(gameloop_monitor, nombre_partida);
    } else {
        joinearse_a_una_partida(gameloop_monitor);
    }
}

void ClienteAceptado::start() {
    receiver->start();
    sender.start();
}

bool ClienteAceptado::is_dead() {
    if (!(receiver->is_alive()) or !(sender.is_alive())) {
        return true;
    }
    return false;
}

void ClienteAceptado::stop() {
    server_msg.close();
    if (!was_closed) {
        protocolo_server.cerrar_socket_cliente();
        was_closed = true;
    }
    sender.join();
    receiver->join();
}

// Destructor
ClienteAceptado::~ClienteAceptado() { stop(); }
