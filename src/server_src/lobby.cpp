#include "../server_src/lobby.h"

Lobby::Lobby(ProtocolServer& protocolo_server, bool& was_closed, GameloopMonitor& gameloop_monitor, uint16_t gameloop_id , uint16_t id_cliente, Queue<std::shared_ptr<GameState>>& server_msg, std::shared_ptr<ServerReceiver>& receiver) :
    protocolo_server(protocolo_server),
    was_closed(was_closed),
    gameloop_monitor(gameloop_monitor), 
    gameloop_id(gameloop_id),
    id_cliente(id_cliente),
    server_msg(server_msg),
    receiver(receiver) {
    }

void Lobby::run() {
    std::cout << "El jugador " << id_cliente << " ha ingresado al lobby" << std::endl;
    try {
        protocolo_server.enviar_id_jugador(id_cliente, was_closed);
        establecer_partida(gameloop_monitor);
        receiver->start();
    } catch (const std::exception& e) {
        std::cerr << "Error en el lobby: " << e.what() << std::endl;
        throw;
    }
    return;
}

void Lobby::establecer_partida(GameloopMonitor& gameloop_monitor) {
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

void Lobby::crear_partida(GameloopMonitor& gameloop_monitor,
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

void Lobby::joinearse_a_una_partida(GameloopMonitor& gameloop_monitor) {
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


Lobby::~Lobby() {}
