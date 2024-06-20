#include "../include/client_src/gui/gui.h"

Gui::Gui(Queue<msgAccion>& client_commands, std::unique_ptr<PersonajeGui> & jugador,
        std::shared_ptr<GameStateClient> & gamestate, std::vector<PlatformGui>& plataformas):
        client_commands(client_commands),
        jugador(jugador),
        gamestate(gamestate),
        plataformas(plataformas),
        escenario(Escenario(plataformas)){}

Gui::~Gui() {}

bool Gui::run(int h_window, int w_window) {
    
    bool client_off = keyhandler.keyBoardManaged( jugador, client_commands);

    if(client_off == true) {
        return true;
    }

    escenario.show(jugador->obtener_posicion_x(), jugador->obtener_posicion_y(),h_window,w_window);
    // cppcheck-suppress unusedVariable
    // Poner todo en una clase de enemigos para hacer enemigos ->show()
    /*for (const auto& [id, personaje]: gamestate->obtener_diccionario_de_personajes()) {
        std::unique_ptr<PersonajeGui> pers;
        int x = (personaje->obtener_posicion_x() - jugador->obtener_posicion_x()) * SCALING_VALUE_PIXEL_X;
        int y = (personaje->obtener_posicion_y() - jugador->obtener_posicion_y()) * SCALING_VALUE_PIXEL_Y;
        if (x <= (jugador->obtener_posicion_x() + renderer.GetOutputWidth() / 2) ||
            x <= (jugador->obtener_posicion_x() - renderer.GetOutputWidth() / 2) ||
            y <= (jugador->obtener_posicion_y() + renderer.GetOutputHeight() / 2) ||
            y <= (jugador->obtener_posicion_y() - renderer.GetOutputHeight() / 2)) {
                pers->show();  // personaje->obtener_animacion());
        }
    }*/
    jugador->show();
    return false;
}
