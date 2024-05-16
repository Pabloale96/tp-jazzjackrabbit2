#include <iostream>
#include <exception>
#include <string>
#include <sstream>
#include <list>

#include "common_liberror.h"
#include "client_class.h"

int main(int argc, char *argv[]) { try {
    int ret = -1;    

    // Chequeo la ejecucion del programa
    if (argc!=3){
        throw LibError(
            -1,
            "Bad program call. Expected %s <hostname> <port>",
            argv[0]);
    }
    
    // Creo la clase cliente para correr el cliente:
    Client client(argv[1],argv[2]);

    client.run();

    ret = 0;
    return ret;

} catch (const std::exception& err) {
    std::cerr
        << "Something went wrong and an exception was caught: "
        << err.what()
        << std::endl;
    return -1;
} catch (...) {
    std::cerr << "Something went wrong and an unknown exception was caught."<< std::endl;
    return -1;
} }
