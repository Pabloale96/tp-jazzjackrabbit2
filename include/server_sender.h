#ifndef _SERVER_SENDER_H_
#define _SERVER_SENDER_H_

#include <memory>
#include <string>

#include "game_state.h"
#include "queue.h"
#include "server_protocol.h"
#include "thread.h"

class ServerSender: public Thread {
private:
    ProtocolServer& protocolo_server;
    bool& was_closed;
    uint16_t cliente_id;
    Queue<std::shared_ptr<GameState>>& server_msg;

public:
    // Constructor
    ServerSender(ProtocolServer& protocolo_server,uint16_t id_cliente,bool& was_closed,
                 Queue<std::shared_ptr<GameState>>& server_msg);

    void run() override;
};

#endif
