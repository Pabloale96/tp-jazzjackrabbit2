#include "server_.h"

#include <iostream>
#include <utility>  // move()

#include "server_aceptador.h"
#include "server_juego.h"

#define MAX_TAM_COLA 10

Server::Server(const std::string& servname): juego(), aceptador(servname, juego) { juego.start(); }

void Server::jugar() {
    aceptador.start();
    while (std::cin.get() != 'q') {
        // Loopeo hasta que encuentro un q o un ctrl+c
    }
    aceptador.stop();
    aceptador.join();
    juego.stop();
    juego.join();
}

Server::~Server() {}
