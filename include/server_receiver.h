#ifndef _SERVER_RECEIVER_H_
#define _SERVER_RECEIVER_H_

#include <memory>
#include <string>

#include "queue.h"
#include "thread.h"
#include "gameloop_class.h"
#include "gameloop_monitor.h"
#include "server_protocol.h"

class ServerReceiver: public Thread {
private:
    ProtocolServer& protocolo_server;
    bool& was_closed;
    uint16_t cliente_id;
    Queue<std::shared_ptr<Comando>>& client_commands;

public:
    // Constructor
    ServerReceiver(ProtocolServer& protocolo_server, bool& was_closed,
                   GameloopMonitor& gameloop_monitor, uint16_t gameloop_id, uint16_t cliente_id);

    void run() override;

    // Destructor
    ~ServerReceiver();
};

#endif
