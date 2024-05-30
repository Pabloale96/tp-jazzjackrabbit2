#ifndef _SERVER_SENDER_H_
#define _SERVER_SENDER_H_

#include <memory>
#include <string>

#include "queue.h"
#include "thread.h"
#include "game_state.h"
#include "server_protocol.h"

class ServerSender: public Thread {
private:
    ProtocolServer& protocolo_server;
    bool& was_closed;
    Queue<std::shared_ptr<GameState>>& server_msg;

public:
    // Constructor
    ServerSender(ProtocolServer& protocolo_server, bool& was_closed,
                 Queue<std::shared_ptr<GameState>>& server_msg);

    void run() override;
};

#endif
