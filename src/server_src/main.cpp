#include <iostream>

#include "../../include/server.h"

#define SUCCESS 0
#define ERROR 1
#define PORT_ARG argv[1]

int main(int argc, char const* argv[]) {
    try {
        if (argc < 2) {
            throw std::runtime_error(
                    "Para correr el server se espera: ./server <servicename o puerto>");
        }
        std::string servname = PORT_ARG;
        Server server(servname);
        server.jugar();
        return SUCCESS;

    } catch (const std::exception& err) {
        std::cerr << "Something went wrong and an exception was caught in "
                     "server->main: \t"
                  << err.what() << "\n";
        return ERROR;
    } catch (...) {
        std::cerr << "Something went wrong and an unknown exception was caught in "
                     "server->main.\n";
        return ERROR;
    }
}
