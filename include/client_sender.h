#ifndef _CLIENT_SENDER_H_
#define _CLIENT_SENDER_H_

#include <memory>
#include <string>

#include "client_protocol.h"
#include "msgToSent.h"
#include "queue.h"
#include "thread.h"

class ClientSender: public Thread {
private:
    ProtocolClient& protocolo_cliente;
    Queue<msgAccion>& client_commands;

public:
    // Constructor
    ClientSender(ProtocolClient& protocolo_cliente, Queue<msgAccion>& client_commands);

    void run() override;
};

#endif
