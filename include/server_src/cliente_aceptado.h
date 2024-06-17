#ifndef _SERVER_CLIENTE_ACEPTADO_H_
#define _SERVER_CLIENTE_ACEPTADO_H_

#include <list>
#include <memory>
#include <string>

#include "../../include/server_src/lobby.h"

#include "gameloop_class.h"
#include "gameloop_monitor.h"
#include "queue.h"
#include "server_protocol.h"
#include "server_receiver.h"
#include "server_sender.h"
#include "sockets.h"
#include "thread.h"

class ClienteAceptado {
private:
    uint16_t id_cliente;
    ProtocolServer protocolo_server;
    bool was_closed;
    Queue<std::shared_ptr<GameState>> server_msg;
    std::atomic<bool> lobby_off;     
    ServerSender sender;
    std::shared_ptr<ServerReceiver> receiver;
    uint16_t gameloop_id;
    Lobby lobby;

public:
    // Constructor
    // Recibe un socket cliente y una referencia al juego
    // Crea un protocolo server con el socket cliente y pone was_closed en false
    // Crea una cola de mensajes del servidor para el cliente
    // Crea un sender y un receiver con el protocolo server y el juego
    // Agrega la cola de mensajes del servidor al juego
    ClienteAceptado(Socket&& socket_cliente, GameloopMonitor& monitor_de_partidas);

    // void lobby(GameloopMonitor& gameloop_monitor);

    void establecer_partida(GameloopMonitor& gameloop_monitor);

    void crear_partida(GameloopMonitor& gameloop_monitor, const std::string& nombre_partida);

    void joinearse_a_una_partida(GameloopMonitor& gameloop_monitor);

    // Inicia el lobby, el sender y el receiver
    void start(GameloopMonitor& gameloop_monitor);

    // Devuelve true si el receiver o el sender estan muertos
    bool is_dead();

    // Detiene el sender y el receiver
    void stop();

    // Destructor
    // Libera la cola de mensajes del servidor
    ~ClienteAceptado();

    // Constructor y asignacion por copia deshabilitados
    ClienteAceptado(const ClienteAceptado&) = delete;
    ClienteAceptado& operator=(const ClienteAceptado&) = delete;

    ClienteAceptado(ClienteAceptado&& other) = delete;
    ClienteAceptado& operator=(ClienteAceptado&& other) = delete;
};

#endif
