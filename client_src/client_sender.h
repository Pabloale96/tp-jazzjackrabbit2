#ifndef _CLIENT_SENDER_H_
#define _CLIENT_SENDER_H_

#include <memory>
#include <string>

#include "../common_src/common_queue.h"
#include "../common_src/common_thread.h"
#include "../client_src/client_protocol.h"

class ClientSender: public Thread {
private:
    ProtocolClient& protocolo_cliente;
    Queue<TipoAccion>& client_commands;

public:
    // Constructor
    ClientSender(ProtocolClient& protocolo_cliente, 
                 Queue<TipoAccion>& client_commands);

    void run() override;
};

#endif
