#ifndef __CLIENT_CLIENT_H__
#define __CLIENT_CLIENT_H__

#include <memory>
#include <string>
#include <vector>
#include <chrono>
#include <map>

#include <SDL2pp/SDL2pp.hh>

#include "../common_src/vector_monitor.h"

#include "client_protocol.h"
#include "client_receiver.h"
#include "client_sender.h"
#include "gui.h"
#include "msgToSent.h"
#include "sockets.h"


#define RATE 60

using std::chrono::duration;
using std::chrono::nanoseconds;
using std::chrono::steady_clock;

using SDL2pp::Renderer;
using SDL2pp::SDL;
using SDL2pp::SDLTTF;
using SDL2pp::Texture;
using SDL2pp::Window;

class Client {
private:

    std::string hostname;
    std::string servicio;
    ProtocolClient protocolo_client;
    Queue<msgAccion> client_commands;
    ClientSender sender;
    Queue<std::shared_ptr<GameStateClient>> server_msg;
    ClientReceiver receiver;
    uint16_t client_id;

    // GUI:

    // tamanio de la pantalla:
    int screenWidth = 600;
    int screenHeight = 800;

    // clases para que despues use gui.cpp:
    std::shared_ptr<PersonajeGui> jugador;
    std::vector<PlatformGui> plataformas;
    std::shared_ptr<GameStateClient> gamestate;

    // ventana con la creacion del renderer:
    Window window{Window("Jazz JackRabbit 2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                        screenHeight, screenWidth, SDL_WINDOW_RESIZABLE | SDL_WINDOW_HIDDEN)};

    Renderer renderer{Renderer(window, -1, SDL_RENDERER_ACCELERATED)};

    ClaseTexturas texturas{ClaseTexturas(renderer)};

    Gui gui;

    std::string toLowercase(const std::string& str);

    void imprimir_bienvenida();

    void imprimir_portada();

    void establecer_partida();

    void crear_personaje();

    void crear_partida();

    void unirse_a_partida();

    void crear_escenario();

    bool cerrar_lobby();

    void iniciar_hilos();

    void mostrar_estadisticas(const GameStateClient& respuestas) const;

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
