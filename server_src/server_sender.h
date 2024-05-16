#ifndef _SERVER_SENDER_H_
#define _SERVER_SENDER_H_

#include <string>

#include "../common_src/common_queue.h"
#include "../common_src/common_thread.h"
#include "../server_src/server_juego.h"
#include "../server_src/server_protocol.h"

class ServerSender: public Thread {
private:
    ProtocolServer& protocolo_server;
    bool& was_closed;
    Juego& juego;
    Queue<ServerJuegoMensaje>* server_msg;

public:
    // Constructor
    ServerSender(ProtocolServer& protocolo_server, bool& was_closed, Juego& juego,
                 Queue<ServerJuegoMensaje>* server_msg);

    void run() override;
};

#endif
