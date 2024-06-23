#include "../include/client_src/gui/gui.h"

Gui::Gui(Queue<msgAccion>& client_commands, std::shared_ptr<PersonajeGui>& jugador,
         GameStateClient& gamestate, std::vector<PlatformGui>& plataformas):
        client_commands(client_commands),
        jugador(jugador),
        gamestate(gamestate),
        plataformas(plataformas),
        escenario(Escenario(plataformas)), 
        posicion_jugador_x(0.0f), 
        posicion_jugador_y(0.0f) {}

Gui::~Gui() {}

bool Gui::setPosicionJugador(float posicion_x, float posicion_y) {
    bool flip = false;
    if (posicion_jugador_x > posicion_x) {
        flip = true;
    }
    posicion_jugador_x = posicion_x;
    posicion_jugador_y = posicion_y;
    return flip;
}

bool Gui::run(int h_window, int w_window, uint16_t client_id) {

    bool client_off = keyhandler.keyBoardManaged(client_commands, jugador->obtener_estado_actual());

    if (client_off) {
        return true;
    }
    escenario.show(posicion_jugador_x, posicion_jugador_y, h_window, w_window);
    
    for (auto& [id, enemigo]: gamestate.obtener_diccionario_de_enemigos()) {        
        float x = (enemigo.obtener_posicion_x() - posicion_jugador_x) *SCALING_VALUE_PIXEL_X + h_window/2; 
        float y = (enemigo.obtener_posicion_y() - posicion_jugador_y) *SCALING_VALUE_PIXEL_Y + w_window/2; 
        enemigo.setPosicion(x,y);
        if (x <= (posicion_jugador_x + h_window/2) || x <= (posicion_jugador_x - h_window/2) || y <=
            (posicion_jugador_y + w_window/2) || y <= (posicion_jugador_y - w_window/2)) { 
                
            enemigo.show(); 
        }
    }
    
    for (auto& [id, personaje]: gamestate.obtener_diccionario_de_personajes()) {        
        if(id == client_id) {
            continue;
        }
        float x = (personaje.obtener_posicion_x() - posicion_jugador_x) *SCALING_VALUE_PIXEL_X + h_window/2; 
        float y = (personaje.obtener_posicion_y() - posicion_jugador_y) *SCALING_VALUE_PIXEL_Y + w_window/2; 
        personaje.setPosicion(x,y);
        if (x <= (posicion_jugador_x + h_window/2) || x <= (posicion_jugador_x - h_window/2) || y <=
            (posicion_jugador_y + w_window/2) || y <= (posicion_jugador_y - w_window/2)) { 
                
            personaje.show(false); 
        }
    }
    jugador->show(true);

    return false;
}
