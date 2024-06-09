#include "../../include/server_src/server.h"

#include <csignal>  // signal, sig_atomic_t
#include <iostream>
#include <utility>  // move()

#include "../../include/common_src/catedra/sockets.h"
#include "../../include/server_src/server_aceptador.h"

#define MAX_TAM_COLA 10

volatile sig_atomic_t stop_flag = 0;

void signal_handler(int signal) {
    if (signal == SIGINT) {
        stop_flag = 1;
    }
}

Server::Server(const std::string& servname): aceptador(servname.c_str()) {
    aceptador.start();
    std::signal(SIGINT, signal_handler);
}

void Server::jugar() {
    std::cout << "****  Server started. Press 'q' to quit  ****" << std::endl;
    while (!stop_flag && std::cin.get() != 'q') {
        // Loopeo hasta que encuentro un q o un ctrl+c
    }
    // TODO: Notificar a los clientes que se va a cerrar el servidor
    aceptador.stop();
    aceptador.join();
}

Server::~Server() {}
