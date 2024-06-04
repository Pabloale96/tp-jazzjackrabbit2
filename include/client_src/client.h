#ifndef __CLIENT_CLIENT_H__
#define __CLIENT_CLIENT_H__

#include <memory>
#include <string>

#include "client_protocol.h"
#include "client_receiver.h"
#include "client_sender.h"
#include "gui.h"
#include "msgToSent.h"
#include "sockets.h"

class Client {
private:
    std::string hostname;
    std::string servicio;
    ProtocolClient protocolo_client;
    Queue<msgAccion> client_commands;
    ClientSender sender;
    Queue<std::shared_ptr<GameState>> server_msg;
    ClientReceiver receiver;
    bool client_off = false;
    std::string personaje;
    uint16_t client_id;
    Gui gui;

    std::string toLowercase(const std::string& str);

    void imprimir_bienvenida();

    void imprimir_portada();

    void establecer_partida();

    void crear_personaje();

    void crear_partida();

    void unirse_a_partida();

    void iniciar_hilos();

    void mostrar_estadisticas(const GameState& respuestas) const;

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