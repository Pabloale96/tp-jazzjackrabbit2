#ifndef _SERVER_RECEIVER_H_
#define _SERVER_RECEIVER_H_

#include <memory>
#include <string>

#include "../common_src/common_queue.h"
#include "../common_src/common_thread.h"
#include "../server_src/gameloop_class.h"
#include "../server_src/gameloop_monitor.h"
#include "../server_src/server_protocol.h"

class ServerReceiver: public Thread {
private:
    ProtocolServer& protocolo_server;
    bool& was_closed;
    Queue<std::shared_ptr<Comando>>& client_commands;

public:
    // Constructor
    ServerReceiver(ProtocolServer& protocolo_server, bool& was_closed,
                   GameloopMonitor& gameloop_monitor, uint16_t gameloop_id);

    void run() override;

    // Destructor
    ~ServerReceiver();
};

#endif
