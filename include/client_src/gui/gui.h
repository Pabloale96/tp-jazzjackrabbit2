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
#include "./common_src/protocol_utils.h"

#include "game_state.h"
#include "gui_clase_texturas.h"
#include "gui_defines_frames.h"
#include "gui_escenario.h"
#include "gui_personaje.h"
#include "msgToSent.h"
#include "gui_keyhandler.h"

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
    // posicion del jugador:
    int pos_x = 0;
    int pos_y = 0;

    // lista de jugadores conectados (llamamos personajes a los jugadores de otros clientes):
    std::map<uint16_t, std::shared_ptr<Personaje>> dic_personajes;

    bool& client_off;

    std::string& personaje;

    Queue<msgAccion>& client_commands;

    std::vector<msgPlataforma>& msg_plataformas;

    uint16_t& client_id;

    std::vector<PlatformGui> plataformas;

    std::unique_ptr<PersonajeGui> jugador;

    // tamanio de la pantalla:
    int screenWidth = 600;
    int screenHeight = 800;


public:
    Gui(int, int, bool&, std::string&, Queue<msgAccion>&, std::vector<msgPlataforma>&, uint16_t&);
    ~Gui();
    void run() override;
    void setGameState(GameState&);
    void setEscenario(ClaseTexturas&);
    void eventManaged(int&, std::unique_ptr<PersonajeGui>&);
    bool checkKeyPress(SDL_Keycode );
};

#endif
