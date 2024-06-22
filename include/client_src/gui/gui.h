#ifndef GUI_H
#define GUI_H

#include <map>
#include <memory>
#include <vector>

#include "../../common_src/catedra/queue.h"
#include "../game_state_client.h"

#include "gui_clase_texturas.h"
#include "gui_defines_frames.h"
#include "gui_escenario.h"
#include "gui_keyhandler.h"
#include "gui_personaje.h"
//#include "gui_ventana.h"
#include "msgToSent.h"
#include "vector_monitor.h"

class Gui {
private:
    Queue<msgAccion>& client_commands;

    // lista de jugadores conectados (llamamos personajes a los jugadores de otros clientes):
    std::shared_ptr<PersonajeGui>& jugador;
    std::shared_ptr<GameStateClient>& gamestate;
    Escenario escenario;

    KeyboardHandler keyhandler;

    float posicion_jugador_x;
    float posicion_jugador_y;

public:
    Gui(Queue<msgAccion>& client_commands, std::shared_ptr<PersonajeGui>& jugador,
        std::shared_ptr<GameStateClient>& gamestate);
    ~Gui();
    bool setPosicionJugador(float, float);
    bool run(int h_window, int w_window);
};

#endif
