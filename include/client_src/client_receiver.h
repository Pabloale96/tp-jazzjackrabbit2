#ifndef _CLIENT_RECEIVER_H_
#define _CLIENT_RECEIVER_H_

#include <memory>
#include <string>

#include "client_protocol.h"
#include "game_state_monitor.h"
#include "queue.h"
#include "thread.h"

class ClientReceiver: public Thread {
private:
    ProtocolClient& protocolo_cliente;
    uint16_t& client_id;
    Queue<std::shared_ptr<GameStateClient>>& server_msg;
    ClaseTexturas & texturas;

public:
    // Constructor
    ClientReceiver(ProtocolClient& protocolo_cliente, uint16_t& client_id,
                   Queue<std::shared_ptr<GameStateClient>>& server_msg, ClaseTexturas & texturas);

    void run() override;

    // Destructor
    ~ClientReceiver();
};

#endif
