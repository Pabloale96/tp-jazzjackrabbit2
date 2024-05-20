#ifndef _SERVER_RECEIVER_H_
#define _SERVER_RECEIVER_H_

#include <string>
#include <memory>

#include "../common_src/common_queue.h"
#include "../common_src/common_thread.h"
#include "../server_src/server_game_loop.h"
#include "../server_src/server_protocol.h"

class ServerReceiver: public Thread {
private:
    ProtocolServer& protocolo_server;
    bool& was_closed;
    Queue<std::shared_ptr<Comando>>& client_commands;

public:
    // Constructor
    ServerReceiver(ProtocolServer& protocolo_server, bool& was_closed,
                   Queue<std::shared_ptr<Comando>>& client_commands);

    void run() override;

    // Destructor
    ~ServerReceiver();
};

#endif
