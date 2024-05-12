#include "common_protocol.h"
#include "common_socket.h"

#include <string.h>
#include <sstream>
#include <list>
#include <arpa/inet.h>
#include <iostream>
#include <algorithm>


Protocol::Protocol(const char * hostname,
    const char * servname) 
    :skt(hostname, servname) /* <-- construimos un `Socket` */
{}

Protocol::Protocol(Socket&& socket):skt(std::move(socket))
{}

Protocol::Protocol(){}

Protocol::~Protocol(){}

// manda un mensaje al servidor
void Protocol::send_msg_to_server(unsigned char & instrucciones) {
    bool was_closed = false;
    skt.sendall(&instrucciones, 1, &was_closed);
}

// manda un mensaje al cliente
void Protocol::send_msg_to_client(msg_client_t & actions,bool * was_closed) {
    skt.sendall(&actions, sizeof(actions), was_closed);
}

// el cliente espera una respuesta
msg_client_t Protocol::wait_response_client(bool * was_closed) {
    
    msg_client_t msg;
    skt.recvall(&msg.header, sizeof(msg.header), was_closed);
    skt.recvall(&msg.size_alived, sizeof(msg.size_alived), was_closed);
    skt.recvall(&msg.size_dead, sizeof(msg.size_dead), was_closed);
    skt.recvall(&msg.method, sizeof(msg.method), was_closed);
    return msg;
}

// el servidor espera una respuesta
unsigned char Protocol::wait_response_server(bool * was_closed) {
    unsigned char byte= 0x00; 
    skt.recvall(&byte, sizeof(byte), was_closed);
    return byte;
}

void Protocol::shutdown(){
    try{
        skt.shutdown(2);
    } catch (...) {
        return; // si hay un error continuo, significa que el cliente ya cerro.
    }
}
