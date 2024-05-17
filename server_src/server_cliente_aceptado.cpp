#include "../server_src/server_cliente_aceptado.h"

#include <utility>  // move()
#include <vector>

#include <sys/socket.h>  // para usar el flag para hacer shutdown del socket

#include "../common_src/common_sockets.h"

#define MAX_TAM_COLA 10

ClienteAceptado::ClienteAceptado(Socket&& socket_cliente, GameLoop& juego):
        protocolo_server(std::move(socket_cliente)),
        was_closed(false),
        server_msg(MAX_TAM_COLA),
        juego(juego),
        sender(protocolo_server, was_closed, juego, server_msg),
        receiver(protocolo_server, was_closed, juego) {
    juego.agregar_queue_server_msg_de_cliente_aceptado(server_msg);
}

void ClienteAceptado::start() {
    receiver.start();
    sender.start();
}

bool ClienteAceptado::is_dead() {
    if (!(receiver.is_alive()) or !(sender.is_alive())) {
        return true;
    }
    return false;
}

void ClienteAceptado::stop() {
    server_msg.close();
    juego.borrar_queue_server_msg_de_cliente_aceptado(server_msg);
    if (!was_closed) {
        protocolo_server.cerrar_socket_cliente();
        was_closed = true;
    }
    sender.join();
    receiver.join();
}

// Destructor
ClienteAceptado::~ClienteAceptado() { stop(); }
