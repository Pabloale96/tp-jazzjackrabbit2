#include "../../include/server_src/server.h"

#include <iostream>
#include <utility>  // move()

#include "../../include/common_src/catedra/sockets.h"
#include "../../include/server_src/server_aceptador.h"

Server::Server(const std::string& servname): aceptador(servname.c_str()) { aceptador.start(); }

void Server::jugar() {
    try {
        std::cout << "****  Server started. Press 'q' to quit  ****" << std::endl;
        while (std::cin.get() != 'q') {
            // Loopeo hasta que encuentro un q o un ctrl+c
        }
        std::cout << "****  Server stopped. Proceeding to close  ****" << std::endl;
        // TODO: Notificar a los clientes que se va a cerrar el servidor
        aceptador.stop();
        aceptador.join();
        std::cout << "****  Server succesfully closed  ****" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error in server: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Unknows error in server" << std::endl;
    }
}

Server::~Server() {}
