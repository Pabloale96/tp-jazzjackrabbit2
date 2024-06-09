#include <iostream>

#include "../../include/server_src/server.h"
#include "../server_src/yaml_config.h"

#define SUCCESS 0
#define ERROR 1
#define PORT_ARG argv[1]
#define YAML_FILE "../config/config.yaml"

int main(int argc, char const* argv[]) {
    try {
        if (argc < 2) {
            throw std::runtime_error(
                    "Para correr el server se espera: ./server <servicename o puerto>");
        }

        std::string yaml_file = YAML_FILE;
        YAMLConfig config(yaml_file);
        config.loadConfig();

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
