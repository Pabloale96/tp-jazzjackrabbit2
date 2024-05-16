#ifndef _SERVER_RECEIVER_H_
#define _SERVER_RECEIVER_H_

#include <string>

#include "common_queue.h"
#include "common_thread.h"
#include "server_juego.h"
#include "server_protocol.h"

class ServerReceiver: public Thread {
private:
    ProtocolServer& protocolo_server;
    bool& was_closed;
    Juego& juego;

public:
    // Constructor
    ServerReceiver(ProtocolServer& protocolo_server, bool& was_closed, Juego& juego);

    void run() override;

    // Destructor
    ~ServerReceiver();
};

#endif
