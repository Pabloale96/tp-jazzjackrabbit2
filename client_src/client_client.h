#ifndef __CLIENT_CLIENT_H__
#define __CLIENT_CLIENT_H__

#include <string>

#include "../client_src/client_protocol.h"
#include "../common_src/common_sockets.h"

class Client {
private:
    std::string hostname;
    std::string servicio;
    ProtocolClient protocolo_client;

    // Muestra las acciones posibles que puede realizar el cliente
    void acciones_posibles();

    // Le envia al server un mensaje indicando su intención de atacar
    void disparar();

    // Le envia al server un mensaje indicando su intención de moverse
    void moverDerecha();
    void moverIzquierda();
    void moverArriba();
    void moverAbajo();
    void saltar();

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
