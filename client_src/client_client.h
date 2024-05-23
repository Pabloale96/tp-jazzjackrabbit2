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

    std::string toLowercase(const std::string& str);

    void imprimir_bienvenida();

    void imprimir_portada();

    void establecer_partida();

    void crear_partida();

    void unirse_a_partida();

    // Muestra las acciones posibles que puede realizar el cliente
    void acciones_posibles();

    // A partir de acá vienen las acciones que puede realizar el cliente
    // Disparar
    void disparar();

    // Correr
    void moverDerecha();
    void moverIzquierda();

    // Corer muy rápido
    void moverDerechaRapido();
    void moverIzquierdaRapido();

    // Saltar
    void saltar();

    // TODO: Chequear si estos 2 métodos son necesarios
    void moverArriba();
    void moverAbajo();


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
