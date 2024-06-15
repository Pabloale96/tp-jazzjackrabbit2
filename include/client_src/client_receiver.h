#ifndef _CLIENT_RECEIVER_H_
#define _CLIENT_RECEIVER_H_

#include <memory>
#include <string>

#include "client_protocol.h"
#include "queue.h"
#include "thread.h"
#include "gamestate_client_monitor.h"

class ClientReceiver: public Thread {
private:
    ProtocolClient& protocolo_cliente;
    uint16_t& client_id;
    Queue<std::shared_ptr<GameStateMonitorClient>>& server_msg;

public:
    // Constructor
    ClientReceiver(ProtocolClient& protocolo_cliente, uint16_t& client_id,
                   Queue<std::shared_ptr<GameStateMonitorClient>>& server_msg);

    void run() override;

    // Destructor
    ~ClientReceiver();
};

#endif
