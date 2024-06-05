#include "../../include/server_src/cliente_aceptado.h"

#include <utility>  // move()
#include <vector>

#include <sys/socket.h>  // para usar el flag para hacer shutdown del socket

#include "../../include/common_src/protocol_utils.h"
#include "../../include/common_src/sockets.h"

#define MAX_TAM_COLA 10
#define PARTIDA_NO_ASIGNADA 0

ClienteAceptado::ClienteAceptado(Socket&& socket_cliente, uint16_t id_cliente):
        id_cliente(id_cliente),
        protocolo_server(std::move(socket_cliente)),
        was_closed(false),
        server_msg(MAX_TAM_COLA),
        sender(protocolo_server, id_cliente, was_closed, server_msg),
        receiver(nullptr),
        gameloop_id(PARTIDA_NO_ASIGNADA) {}

void ClienteAceptado::establecer_partida(GameloopMonitor& gameloop_monitor) {
    if (protocolo_server.crear_partida(was_closed) == CREAR_PARTIDA) {
        std::string nombre_partida;
        protocolo_server.recibir_nombre_partida(nombre_partida, was_closed);
        crear_partida(gameloop_monitor, nombre_partida);
    } else {
        joinearse_a_una_partida(gameloop_monitor);
    }
}

void ClienteAceptado::crear_partida(GameloopMonitor& gameloop_monitor,
                                    const std::string& nombre_partida) {
    std::cout << "** PARTIDA NUEVA CREADA CON NOMBRE: " << nombre_partida << " **" << std::endl;
    std::string personaje;
    protocolo_server.recibir_personaje(personaje, was_closed);
    gameloop_id = gameloop_monitor.crear_gameloop(nombre_partida, id_cliente, personaje);
    gameloop_monitor.obtener_gameloop(gameloop_id)
            ->agregar_queue_server_msg_de_cliente_aceptado(server_msg);
    receiver = std::make_unique<ServerReceiver>(protocolo_server, was_closed, gameloop_monitor,
                                                gameloop_id, id_cliente);
    protocolo_server.enviar_escenario((gameloop_monitor.obtener_gameloop(gameloop_id)->obtener_game()),was_closed);
    return;
}

void ClienteAceptado::joinearse_a_una_partida(GameloopMonitor& gameloop_monitor) {
    try {
        protocolo_server.enviar_partidas_disponibles(gameloop_monitor, was_closed);
        uint16_t gameloop_id = protocolo_server.recibir_id_partida(was_closed);
        std::string personaje;
        protocolo_server.recibir_personaje(personaje, was_closed);
        std::cout << " ** SE UNIO A LA PARTIDA CON id " << gameloop_id << " **" << std::endl;
        gameloop_monitor.obtener_gameloop(gameloop_id)
                ->agregar_queue_server_msg_de_cliente_aceptado(server_msg);
        gameloop_monitor.obtener_gameloop(gameloop_id)->agregar_cliente(id_cliente, personaje);
        receiver = std::make_unique<ServerReceiver>(protocolo_server, was_closed, gameloop_monitor,
                                                    gameloop_id, id_cliente);
        protocolo_server.enviar_escenario((gameloop_monitor.obtener_gameloop(gameloop_id)->obtener_game()),was_closed);
    } catch (const std::exception& e) {
        std::cerr << "Error al obtener partidas disponibles: " << e.what() << std::endl;
        throw;
    }
    return;
}

void ClienteAceptado::start() {
    receiver->start();
    sender.start();
}

bool ClienteAceptado::is_dead() {
    if ((receiver == nullptr || !receiver->is_alive()) || !sender.is_alive()) {
        std::cout << "El cliente " << id_cliente << " murio" << std::endl;
        return true;
    }
    return false;
}

void ClienteAceptado::stop() {
    std::cout << "El cliente " << id_cliente << " se detiene" << std::endl;
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
