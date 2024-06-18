#include "../server_src/lobby.h"

#include "../../include/common_src/excepciones.h"

Lobby::Lobby(ProtocolServer& protocolo_server, bool& was_closed, GameloopMonitor& gameloop_monitor,
             uint16_t gameloop_id, uint16_t id_cliente,
             Queue<std::shared_ptr<GameState>>& server_msg,
             std::shared_ptr<ServerReceiver>& receiver):
        protocolo_server(protocolo_server),
        was_closed(was_closed),
        gameloop_monitor(gameloop_monitor),
        gameloop_id(gameloop_id),
        id_cliente(id_cliente),
        server_msg(server_msg),
        receiver(receiver) {}

void Lobby::run() {
    std::cout << "El jugador " << id_cliente << " ha ingresado al lobby" << std::endl;
    try {
        protocolo_server.enviar_id_jugador(id_cliente, was_closed);
        establecer_partida(gameloop_monitor);
        if (protocolo_server.confirmar_fin_lobby(was_closed) == false) {
            std::cout << "Error en la confirmacion del fin del lobby" << std::endl;
            throw std::runtime_error("Error en la confirmacion del fin del lobby");
        }
        receiver->start();
    } catch (const ErrorEnviarDatos&) {
        std::cerr << "Error en el envio de escenario " << std::endl;
        throw;
    } catch (const std::exception& e) {
        std::cerr << "Error en el lobby: " << e.what() << std::endl;
        throw;
    }
    return;
}

void Lobby::establecer_partida(GameloopMonitor& gameloop_monitor) {
    uint16_t id_partida;
    if (protocolo_server.crear_partida(was_closed) == CREAR_PARTIDA) {
        std::string nombre_partida;
        protocolo_server.recibir_nombre_partida(nombre_partida, was_closed);
        id_partida = crear_partida(gameloop_monitor, nombre_partida);
    } else {
        id_partida = joinearse_a_una_partida(gameloop_monitor);
    }
    if (id_partida == 0) {
        throw std::runtime_error("Error al unirse a la partida");
    }
    receiver = std::make_unique<ServerReceiver>(protocolo_server, was_closed, gameloop_monitor,
                                                id_partida, id_cliente);
    protocolo_server.enviar_escenario(
            (gameloop_monitor.obtener_gameloop(id_partida)->obtener_game()), was_closed);
}

uint16_t Lobby::crear_partida(GameloopMonitor& gameloop_monitor,
                              const std::string& nombre_partida) {
    std::cout << "** PARTIDA NUEVA CREADA CON NOMBRE: " << nombre_partida << " **" << std::endl;
    uint8_t personaje = protocolo_server.recibir_personaje(was_closed);
    gameloop_id = gameloop_monitor.crear_gameloop(nombre_partida, id_cliente, personaje);
    gameloop_monitor.agregar_queue_server_msg_de_cliente_aceptado(gameloop_id, server_msg);
    return gameloop_id;
}

uint16_t Lobby::joinearse_a_una_partida(GameloopMonitor& gameloop_monitor) {
    try {
        if (protocolo_server.enviar_partidas_disponibles(gameloop_monitor, was_closed) ==
            CREAR_PARTIDA) {
            if (protocolo_server.crear_partida(was_closed) == CREAR_PARTIDA) {
                std::string nombre_partida;
                protocolo_server.recibir_nombre_partida(nombre_partida, was_closed);
                return crear_partida(gameloop_monitor, nombre_partida);
            } else {
                std::cout << "Error al crear partida" << std::endl;
            }
        } else {
            uint16_t gameloop_id = ntohs(protocolo_server.recibir_id_partida(was_closed));
            uint8_t personaje = protocolo_server.recibir_personaje(was_closed);
            std::cout << " ** SE UNIO A LA PARTIDA CON GAMELOOP ID " << gameloop_id << " **"
                      << std::endl;
            gameloop_monitor.agregar_queue_server_msg_de_cliente_aceptado(gameloop_id, server_msg);
            gameloop_monitor.agregar_cliente_al_gameloop(gameloop_id, id_cliente, personaje);
            return gameloop_id;
        }
    } catch (const std::exception& e) {
        std::cerr << "Error al obtener partidas disponibles: " << e.what() << std::endl;
        throw;
    }
    return 0;
}

Lobby::~Lobby() {}
