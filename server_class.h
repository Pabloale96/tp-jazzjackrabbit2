#ifndef SERVER_H
#define SERVER_H

#include <map>
#include <string>
#include <sstream>
#include <list>

#include "common_protocol.h"
#include "common_thread.h"
#include "server_gameloop.h"
#include "server_structMsg.h"
#include <vector>

class Server {

    private:
    Socket skt_accept;

    public:
    explicit Server(char * servername);
    Server();
    ~Server();

    void run();
};
#endif
