#include "server_server.h"

#include <iostream>
#include <utility>  // move()

#include "../common_src/common_sockets.h"
#include "../server_src/server_aceptador.h"

#define MAX_TAM_COLA 10

Server::Server(const std::string& servname): aceptador(servname.c_str()) { aceptador.start(); }

void Server::jugar() {
    while (std::cin.get() != 'q') {
        // Loopeo hasta que encuentro un q o un ctrl+c
    }
    aceptador.stop();
    aceptador.join();
}

Server::~Server() {}
