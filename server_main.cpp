#include <iostream>
#include <exception>

#include "server_class.h"
#include "common_liberror.h"

int main(int argc, char *argv[]) { try {
    
    int ret = -1;

    // Chequeo de la ejecucion del programa
    if (argc!=2){
        throw LibError(
            -1,
            "Bad program call. Expected %s <hostname>",
            argv[0]);
    }
    
    // Creo la clase server para correr el servidor:
    Server server(argv[1]);

    server.run();

    ret = 0;
    return ret;

} catch (const std::exception& err) {
    std::cerr
        << "Something went wrong and an exception was caught: "
        << err.what()
        << std::endl;
    return -1;
} catch (...) {
    std::cerr << "Something went wrong and an unknown exception was caught."<<std::endl;
    return -1;
} }
