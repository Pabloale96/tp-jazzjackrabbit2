#ifndef _SERVER_CLIENTE_ACEPTADO_H_
#define _SERVER_CLIENTE_ACEPTADO_H_

#include <list>
#include <memory>
#include <string>

#include "queue.h"
#include "sockets.h"
#include "thread.h"
#include "gameloop_class.h"
#include "gameloop_monitor.h"
#include "server_protocol.h"
#include "server_receiver.h"
#include "server_sender.h"

class ClienteAceptado {
private:
    uint16_t id_cliente;
    ProtocolServer protocolo_server;
    bool was_closed;
    Queue<std::shared_ptr<GameState>> server_msg;
    ServerSender sender;
    std::unique_ptr<ServerReceiver> receiver;
    uint16_t gameloop_id;

public:
    // Constructor
    // Recibe un socket cliente y una referencia al juego
    // Crea un protocolo server con el socket cliente y pone was_closed en false
    // Crea una cola de mensajes del servidor para el cliente
    // Crea un sender y un receiver con el protocolo server y el juego
    // Agrega la cola de mensajes del servidor al juego
    ClienteAceptado(Socket&& socket_cliente, uint16_t id_cliente);

    void establecer_partida(GameloopMonitor& gameloop_monitor);

    void crear_partida(GameloopMonitor& gameloop_monitor, const std::string& nombre_partida);

    void joinearse_a_una_partida(GameloopMonitor& gameloop_monitor);

    // Inicia el sender y el receiver
    void start();

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
