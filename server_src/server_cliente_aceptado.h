#ifndef _SERVER_CLIENTE_ACEPTADO_H_
#define _SERVER_CLIENTE_ACEPTADO_H_

#include <memory>
#include <string>

#include "../common_src/common_queue.h"
#include "../common_src/common_sockets.h"
#include "../common_src/common_thread.h"
#include "../server_src/server_game_loop.h"
#include "../server_src/server_protocol.h"
#include "../server_src/server_receiver.h"
#include "../server_src/server_sender.h"

class ClienteAceptado {
private:
    ProtocolServer protocolo_server;
    bool was_closed;
    Queue<std::shared_ptr<ServerJuegoMensaje>> server_msg;
    GameLoop& juego;
    ServerSender sender;
    ServerReceiver receiver;

public:
    // Constructor
    // Recibe un socket cliente y una referencia al juego
    // Crea un protocolo server con el socket cliente y pone was_closed en false
    // Crea una cola de mensajes del servidor para el cliente
    // Crea un sender y un receiver con el protocolo server y el juego
    // Agrega la cola de mensajes del servidor al juego
    ClienteAceptado(Socket&& socket_cliente, GameLoop& juego);

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
