#ifndef __CLIENT_CLIENT_H__
#define __CLIENT_CLIENT_H__

#include <memory>
#include <string>

#include "game_respuesta.h"
#include "client_protocol.h"
#include "client_receiver.h"
#include "client_sender.h"
#include "sockets.h"
#include "gui.h"

class Client {
private:
    std::string hostname;
    std::string servicio;
    ProtocolClient protocolo_client;
    Queue<TipoAccion> client_commands;
    ClientSender sender;
    Queue<std::shared_ptr<ClientGameRespuesta>> server_msg;
    ClientReceiver receiver;
    bool client_off = false;
    std::string personaje;
    Gui gui;
    


    std::string toLowercase(const std::string& str);

    void imprimir_bienvenida();

    void imprimir_portada();

    void establecer_partida();

    void crear_personaje();

    void crear_partida();

    void unirse_a_partida();

    void iniciar_hilos();

    // Muestra las acciones posibles que puede realizar el cliente
    void acciones_posibles();

    void ejecutar_accion(std::string& accion_actual);

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

    // Espera la respuesta del server y la imprime
    void imprimir_respuesta(const Respuesta& respuesta);

public:
    // Constructor
    // Crea el protocolo para poder hablar con el server
    Client(const std::string& hostname, const std::string& servicio);

    // Lee por entrada estandar y parsea las acciones
    void jugar();

    void stop_hilos();

    // Destructor
    ~Client();
};

#endif
