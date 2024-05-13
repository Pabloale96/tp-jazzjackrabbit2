#ifndef CLIENT_H
#define CLIENT_H

#include <vector>

#include "common_protocol.h"
#include "client_action.h"

#define DELIMITOR " "

class Client {

    private:
    Protocol protocol;
    Action action;
    bool was_closed = false;

    public:
    explicit Client(char * hostname, char * servername);
    ~Client();
    Client();

    void run();
};

#endif
