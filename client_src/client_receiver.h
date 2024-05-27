#ifndef _CLIENT_RECEIVER_H_
#define _CLIENT_RECEIVER_H_

#include <memory>
#include <string>

#include "../common_src/common_thread.h"
#include "../client_src/client_protocol.h"
#include "../client_src/client_game_respuesta.h"
#include "../common_src/common_queue.h"

class ClientReceiver: public Thread {
private:
    ProtocolClient& protocolo_cliente;
    Queue<std::shared_ptr<ClientGameRespuesta>>& server_msg;

public:
    // Constructor
    ClientReceiver(ProtocolClient& protocolo_cliente, 
                   Queue<std::shared_ptr<ClientGameRespuesta>>& server_msg);

    void run() override;

    // Destructor
    ~ClientReceiver();
};

#endif
