#include "../../include/server_src/cliente_aceptado.h"

#include <utility>  // move()
#include <vector>

#include <sys/socket.h>  // para usar el flag para hacer shutdown del socket

#include "../../include/common_src/catedra/sockets.h"
#include "../../include/common_src/protocol_utils.h"

#define MAX_TAM_COLA 10000
#define PARTIDA_NO_ASIGNADA 0

ClienteAceptado::ClienteAceptado(Socket&& socket_cliente, GameloopMonitor& monitor_de_partidas):
        id_cliente(monitor_de_partidas.crear_nuevo_id_cliente()),
        protocolo_server(std::move(socket_cliente)),
        was_closed(false),
        server_msg(MAX_TAM_COLA),
        sender(protocolo_server, id_cliente, was_closed, server_msg),
        receiver(nullptr),
        gameloop_id(PARTIDA_NO_ASIGNADA),
        lobby(protocolo_server, was_closed, monitor_de_partidas, gameloop_id, id_cliente,
              server_msg, receiver) {
    std::cout << "** NUEVO JUGADOR INGRESO AL SERVER - ID: " << std::to_string(id_cliente) << " **"
              << std::endl;
}

void ClienteAceptado::start(GameloopMonitor& gameloop_monitor) {
    lobby.start();
    sender.start();
}

bool ClienteAceptado::is_dead() {
    if ((!receiver->is_alive()) || !sender.is_alive()) {
        return true;
    }
    return false;
}

void ClienteAceptado::stop() {
    try {
        lobby.stop();
        lobby.join();
        std::cout << "El cliente " << id_cliente << " se detiene" << std::endl;
        server_msg.close();
        if (!was_closed) {
            protocolo_server.cerrar_socket_cliente();
            was_closed = true;
        }
        sender.join();
        receiver->join();
    } catch (const std::exception& e) {
        std::cerr << "Error al detener el cliente: " << e.what() << std::endl;
    }
}

// Destructor
ClienteAceptado::~ClienteAceptado() { stop(); }
