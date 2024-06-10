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

/*
void ClienteAceptado::lobby(GameloopMonitor& gameloop_monitor) {
    lobby.start();
}*/

/*
void ClienteAceptado::establecer_partida(GameloopMonitor& gameloop_monitor) {
    if (protocolo_server.crear_partida(was_closed) == CREAR_PARTIDA) {
        std::string nombre_partida;
        protocolo_server.recibir_nombre_partida(nombre_partida, was_closed);
        crear_partida(gameloop_monitor, nombre_partida);
        protocolo_server.enviar_escenario(
                (gameloop_monitor.obtener_gameloop(gameloop_id)->obtener_game()), was_closed);
    } else {
        joinearse_a_una_partida(gameloop_monitor);
    }
}

void ClienteAceptado::crear_partida(GameloopMonitor& gameloop_monitor,
                                    const std::string& nombre_partida) {
    std::cout << "** PARTIDA NUEVA CREADA CON NOMBRE: " << nombre_partida << " **" << std::endl;
    uint8_t personaje = protocolo_server.recibir_personaje(was_closed);
    gameloop_id = gameloop_monitor.crear_gameloop(nombre_partida, id_cliente, personaje);
    gameloop_monitor.obtener_gameloop(gameloop_id)
            ->agregar_queue_server_msg_de_cliente_aceptado(server_msg);
    receiver = std::make_unique<ServerReceiver>(protocolo_server, was_closed, gameloop_monitor,
                                                gameloop_id, id_cliente);
    return;
}

void ClienteAceptado::joinearse_a_una_partida(GameloopMonitor& gameloop_monitor) {
    try {
        if (protocolo_server.enviar_partidas_disponibles(gameloop_monitor, was_closed) ==
            CREAR_PARTIDA) {
            if (protocolo_server.crear_partida(was_closed) == CREAR_PARTIDA) {
                std::string nombre_partida;
                protocolo_server.recibir_nombre_partida(nombre_partida, was_closed);
                crear_partida(gameloop_monitor, nombre_partida);
            } else {
                std::cout << "Error al crear partida" << std::endl;
            }
        } else {
            uint16_t gameloop_id = protocolo_server.recibir_id_partida(was_closed);
            uint8_t personaje = protocolo_server.recibir_personaje(was_closed);
            std::cout << " ** SE UNIO A LA PARTIDA CON id " << gameloop_id << " **" << std::endl;
            gameloop_monitor.obtener_gameloop(gameloop_id)
                    ->agregar_queue_server_msg_de_cliente_aceptado(server_msg);

            protocolo_server.enviar_escenario(
                    (gameloop_monitor.obtener_gameloop(gameloop_id)->obtener_game()), was_closed);

            gameloop_monitor.obtener_gameloop(gameloop_id)->agregar_cliente(id_cliente, personaje);
            receiver = std::make_unique<ServerReceiver>(protocolo_server, was_closed,
                                                        gameloop_monitor, gameloop_id, id_cliente);
        }
    } catch (const std::exception& e) {
        std::cerr << "Error al obtener partidas disponibles: " << e.what() << std::endl;
        throw;
    }
    return;
}
*/

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
