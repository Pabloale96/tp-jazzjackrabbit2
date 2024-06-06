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
    int posx;
    int posy;
    int w;
    int h;
    bool& client_off;
    std::string& personaje;
    Queue<msgAccion>& client_commands;
    std::vector<msgPlataforma>& msg_plataformas;
    std::vector<PlatformGui> plataformas;

    int screenWidth = 600;
    int screenHeight = 800;

public:
    Gui(int, int, int, int, bool&, std::string&, Queue<msgAccion>&,std::vector<msgPlataforma>&);
    ~Gui();
    void run() override;
    void setGameState(GameState&, uint16_t);
    void setEscenario(ClaseTexturas &);
};

#endif
