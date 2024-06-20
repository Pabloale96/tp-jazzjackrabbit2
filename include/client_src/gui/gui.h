#ifndef GUI_H
#define GUI_H

#include <chrono>
#include <exception>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <thread>
#include <vector>

#include <SDL2pp/SDL2pp.hh>

#include "../../common_src/catedra/queue.h"
#include "../../common_src/catedra/thread.h"
#include "../../common_src/protocol_utils.h"
#include "../../common_src/vector_monitor.h"
#include "../game_state_client.h"

#include "gui_clase_texturas.h"
#include "gui_defines_frames.h"
#include "gui_escenario.h"
#include "gui_keyhandler.h"
#include "gui_personaje.h"
//#include "gui_ventana.h"
#include "msgToSent.h"
#include "vector_monitor.h"

#define RATE 60

using std::chrono::duration;
using std::chrono::nanoseconds;
using std::chrono::steady_clock;

using SDL2pp::Renderer;
using SDL2pp::SDL;
using SDL2pp::SDLTTF;
using SDL2pp::Texture;
using SDL2pp::Window;

class Gui: public Thread {
private:
    // mutable std::mutex m;  // Si no pongo mutable no puedo usar lock en metodos const

    // posicion del jugador:
    int pos_x = 0;
    int pos_y = 0;

    // lista de jugadores conectados (llamamos personajes a los jugadores de otros clientes):
    std::map<uint16_t, std::shared_ptr<PersonajeGui>> dic_personajes;

    std::atomic<bool>& client_off;

    std::string& personaje;

    Queue<msgAccion>& client_commands;

    // VectorMonitor<msgPlataforma>& msg_plataformas;

    uint16_t& client_id;

    VectorMonitor<std::shared_ptr<PlatformGui>>& plataformas;

    std::unique_ptr<PersonajeGui> jugador;

    // tamanio de la pantalla:
    int screenWidth = 600;
    int screenHeight = 800;


    //Ventana ventana(pos_x,pos_y,screenHeight, screenWidth,XMAX*SCALING_VALUE_PIXEL_X,YMAX*SCALING_VALUE_PIXEL_y);


public:
    Gui(int, int, std::atomic<bool>&, std::string&, Queue<msgAccion>&, VectorMonitor<std::shared_ptr<PlatformGui>>&, uint16_t&);
    ~Gui();
    void run() override;
    void setGameState(GameStateClient&);
    void setEscenario(ClaseTexturas&);
};

#endif
