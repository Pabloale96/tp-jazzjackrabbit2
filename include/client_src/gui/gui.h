#ifndef GUI_H
#define GUI_H

#include <chrono>
#include <exception>
#include <iostream>
#include <string>
#include <memory>
#include <thread>

#include <SDL2pp/SDL2pp.hh>

#include "gui_escenario.h"
#include "gui_personaje.h"
#include "./common_src/protocol_utils.h"

#include "game_state.h"
#include "gui_clase_texturas.h"
#include "gui_defines_frames.h"
#include "msgToSent.h"
#include "queue.h"
#include "../../common_src/thread.h"

#define RATE 15.0

using std::chrono::duration;
using std::chrono::nanoseconds;
using std::chrono::steady_clock;

using SDL2pp::Renderer;
using SDL2pp::Texture;
using SDL2pp::Window;
using SDL2pp::SDLTTF;
using SDL2pp::SDL;

class Gui: public Thread {
private:
    int pos_x =0;
    int pos_y =0;
    int w=0;
    int h=0;
    bool& client_off;
    std::string& personaje;
    Queue<msgAccion>& client_commands;
    std::vector<msgPlataforma>& msg_plataformas;
    uint16_t & client_id;
    std::vector<PlatformGui> plataformas;
    std::vector<msgPersonaje> personajes;
    std::unique_ptr<PersonajeGui> jugador;
    int screenWidth = 600;
    int screenHeight = 800;


public:
    Gui(int, int, int, int, bool&, std::string&, Queue<msgAccion>&,std::vector<msgPlataforma>&,uint16_t&);
    ~Gui();
    void run() override;
    void setGameState(GameState&);
    void setEscenario(ClaseTexturas &);
};

#endif
