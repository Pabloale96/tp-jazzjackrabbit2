#ifndef __CLIENT_H__
#define __CLIENT_H__

#include <string>

#include "client_protocol.h"
#include "common_sockets.h"

class Client {
private:
    std::string hostname;
    std::string servicio;
    ProtocolClient protocolo_client;

    // Le envia al server un mensaje indicando su intención de atacar
    void atacar();

    // Espera hasta recibir la respuesta del server y la imprime
    void leer();

    // Espera la respuesta del server y la imprime
    void imprimir_respuesta(const Respuesta& respuesta);

public:
    // Constructor
    // Crea el protocolo para poder hablar con el server
    Client(const std::string& hostname, const std::string& servicio);

    // Lee por entrada estandar y parsea las acciones
    void jugar();

    // Destructor
    ~Client();
};


#endif
