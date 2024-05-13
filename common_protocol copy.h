#ifndef HTTP_PROTOCOL_H
#define HTTP_PROTOCOL_H

#include "common_socket.h"
#include "server_structMsg.h"

#include <list>
#include <string>
#include <sstream>
#include <vector>

#define SIZE_MSG 6

class Protocol {
    private:
    Socket skt;

    public:

    explicit Protocol(const char * hostname,const char * servname);

    Protocol();
    explicit Protocol(Socket&&);
    ~Protocol();

    void send_msg_to_server(unsigned char &);
    void send_msg_to_client(msg_client_t & ,bool *);

    msg_client_t wait_response_client(bool * was_closed);
    unsigned char wait_response_server(bool * was_closed);

    void shutdown();
};

#endif
