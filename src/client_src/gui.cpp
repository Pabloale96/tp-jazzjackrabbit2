#include "../include/gui.h"

#include <chrono>
#include <exception>
#include <iostream>
#include <memory>
#include <thread>

#include "../include/escenario.h"
#include "../include/personaje.h"
#include "../include/protocol_utils.h"

Gui::Gui(int x, int y, int w, int h, bool& client_off, std::string& personaje,
         Queue<msgAccion>& client_commands):
        posx(x),
        posy(y),
        w(w),
        h(h),
        client_off(client_off),
        personaje(personaje),
        client_commands(client_commands) {}

Gui::~Gui() {}

void Gui::setGameState(GameState& gamestate, uint16_t client_id) {

    for (const auto& pair: gamestate.obtener_diccionario_de_personajes()) {
        if (pair.first == client_id) {
            posx = pair.second.obtener_posicion().get_posicion_x();
            posy = pair.second.obtener_posicion().get_posicion_y();
        }
    }
}

void Gui::run() {
    const nanoseconds rate_ns(static_cast<int>(1e9 / RATE));

    SDL2pp::SDL sdl(SDL_INIT_VIDEO);
    SDL2pp::SDLTTF ttf;

    SDL_DisplayMode displayMode;
    int monitorIndex = 1;

    int screenWidth = 600;
    int screenHeight = 800;

    SDL2pp::Window window("SDL2pp demo", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                          screenHeight, screenWidth, SDL_WINDOW_RESIZABLE);

    SDL2pp::Renderer renderer(window, -1, SDL_RENDERER_ACCELERATED);

    // crear clase para guardar todos los texturas:
    // mapa que indixe por cada uno de la textura.
    // {'jazz_walk': jazz_tex}
    // se podria mandar los frame_vector.

    ClaseTexturas texturas(renderer);

    std::unique_ptr<PersonajeGui> jugador;
    if (personaje == "j") {
        jugador = std::make_unique<JazzGui>(texturas);
    } else if (personaje == "s") {
        jugador = std::make_unique<SpazGui>(texturas);
    } else if (personaje == "l") {
        jugador = std::make_unique<LoriGui>(texturas);
    }
    Escenario escenario(renderer);

    int animacion = 0;
    int animacion_prev = 0;

    auto frame_start = steady_clock::now();

    unsigned int prev_ticks = SDL_GetTicks();

    while (1) {
        unsigned int frame_ticks = SDL_GetTicks();
        unsigned int frame_delta = frame_ticks - prev_ticks;
        int dif_x = 0;
        int dif_y = 0;
        prev_ticks = frame_ticks;
        SDL_Event event;
        // definir N it para las animaciones de frame.
        // dividite por X de la diapos que mostro leo.
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                return;
            } else if (event.type == SDL_KEYDOWN) {
                msgAccion msg_to_sent(0x00, false);
                switch (event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                    case SDLK_q:
                        client_off = true;
                        return;
                    case SDLK_s:
                        // enviar mensajer atacar 1 ((16bytes) (16bytes) (16bytes))
                        // push a client_commands
                        return;
                    case SDLK_RIGHT:
                        msg_to_sent = msgAccion(MOVER_DERECHA, true);
                        client_commands.push(msg_to_sent);
                        animacion = ANI_MOVER_DERECHA;
                        break;
                    case SDLK_LEFT:
                        // enviar mensaje mover izquierda 1
                        // push a client_commands
                        animacion = 2;
                        dif_x += frame_delta * 0.2;
                        break;
                }
            } else if (event.type == SDL_KEYUP) {
                switch (event.key.keysym.sym) {
                    case SDLK_RIGHT:
                        // enviar mensaje mover izquierda 0
                        animacion = 0;
                        break;
                    case SDLK_LEFT:
                        // enviar mensaje mover izquierda 0
                        animacion = 0;
                        break;
                }
            }
        }

        // Clear the screen
        renderer.Clear();
        escenario.show(posx, posy);
        jugador->show(animacion);
        renderer.Present();

        auto frame_end = steady_clock::now();
        auto rest = rate_ns - (frame_end - frame_start);

        if (rest.count() < 0) {
            auto behind = -rest;
            auto lost = behind - behind % rate_ns;
            frame_start += lost;
        } else {
            std::this_thread::sleep_for(rest);
        }
        frame_start += rate_ns;
    }
}


/*void Gui::setGameState( respuesta){

}*/
