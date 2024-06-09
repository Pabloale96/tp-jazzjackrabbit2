#include <iostream>
#include <string>

#include "../../include/client_src/client.h"
#include "../../include/common_src/catedra/liberror.h"

#define SUCCESS 0
#define ERROR 1
#define HOSTNAME_ARG argv[1]
#define SERVICE_ARG argv[2]

int main(int argc, char const* argv[]) {
    try {
        if (argc < 3) {
            throw std::runtime_error("Para corer el cliente se espera: ./client <hostname o IP> "
                                     "<servicename o puerto>\n");
        }

        std::string hostname = HOSTNAME_ARG;
        std::string servicio = SERVICE_ARG;
        Client client(hostname, servicio);

        client.jugar();

        return SUCCESS;
    } catch (const LibError& err) {
        std::cerr << "Fallo la conexión con el servidor. Revisa si está levantado."
                  << "\n";
    } catch (const std::exception& err) {
        std::cerr << "Something went wrong and an exception was caught in "
                     "client->main: \t"
                  << err.what() << "\n";
        return ERROR;
    } catch (...) {
        std::cerr << "Something went wrong and an unknown exception was caught in "
                     "client->main.\n";
        return ERROR;
    }
}
