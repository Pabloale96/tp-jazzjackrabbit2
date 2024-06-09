#include "../include/client_src/gui/gui.h"

Gui::Gui(int x, int y, bool& client_off, std::string& personaje, Queue<msgAccion>& client_commands,
         std::vector<msgPlataforma>& msg_plataformas, uint16_t& ci):
        pos_x(x),
        pos_y(y),
        client_off(client_off),
        personaje(personaje),
        client_commands(client_commands),
        msg_plataformas(msg_plataformas),
        client_id(ci) {}

Gui::~Gui() {}

void Gui::setGameState(GameState& gamestate) {
    personajes = gamestate.obtener_diccionario_de_personajes();
    pos_x = gamestate.obtener_personaje(client_id)->obtener_posicion().get_posicion_x();
    pos_y = gamestate.obtener_personaje(client_id)->obtener_posicion().get_posicion_y();
    personajes.erase(client_id);
}
void Gui::setEscenario(ClaseTexturas& texturas) {
    for (size_t i = 0; i < msg_plataformas.size(); i++) {
        PlatformGui plataforma(texturas, msg_plataformas[i]);
        plataformas.push_back(plataforma);
    }
}

void Gui::eventManaged(int& animacion) {

    SDL_Event event;
    // definir N it para las animaciones de frame.
    // dividite por X de la diapos que mostro leo.
    while (SDL_PollEvent(&event)) {
        msgAccion msg_to_sent(0x00, false);
        if (event.type == SDL_QUIT) {
            return;
        } else if (event.type == SDL_KEYDOWN) {
            msgAccion msg_to_sent(static_cast<uint8_t>(acciones::NULO), false);
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
                    if (animacion != ANI_MOVER_DERECHA) {
                        msg_to_sent =
                                msgAccion(static_cast<uint8_t>(acciones::MOVER_DERECHA), true);
                        client_commands.push(msg_to_sent);
                        animacion = ANI_MOVER_DERECHA;  // se ejecuta la animacion derecha
                    }
                    break;
                case SDLK_LEFT:
                    if (animacion != ANI_MOVER_IZQUIERDA) {
                        msg_to_sent =
                                msgAccion(static_cast<uint8_t>(acciones::MOVER_IZQUIERDA), true);
                        client_commands.push(msg_to_sent);
                        animacion = ANI_MOVER_IZQUIERDA;  // se ejecuta la animacion derecha
                    }
                    break;
                case SDLK_UP:
                    if (animacion != ANI_SALTAR) {
                        msg_to_sent = msgAccion(static_cast<uint8_t>(acciones::SALTAR), true);
                        client_commands.push(msg_to_sent);
                        animacion = ANI_SALTAR;  // se ejecuta la animacion derecha
                    }
                    break;
            }
        } else if (event.type == SDL_KEYUP) {
            switch (event.key.keysym.sym) {
                case SDLK_RIGHT:
                    if (animacion != ANI_STAND) {
                        msg_to_sent =
                                msgAccion(static_cast<uint8_t>(acciones::MOVER_DERECHA), false);
                        client_commands.push(msg_to_sent);
                        animacion = ANI_STAND;  // se ejecuta la animacion derecha
                    }
                    break;
                case SDLK_LEFT:
                    if (animacion != ANI_STAND) {
                        msg_to_sent =
                                msgAccion(static_cast<uint8_t>(acciones::MOVER_IZQUIERDA), false);
                        client_commands.push(msg_to_sent);
                        animacion = ANI_STAND;  // se ejecuta la animacion derecha
                    }
                    break;
                case SDLK_UP:
                    if (animacion != ANI_STAND) {
                        msg_to_sent = msgAccion(static_cast<uint8_t>(acciones::SALTAR), false);
                        client_commands.push(msg_to_sent);
                        animacion = ANI_STAND;  // se ejecuta la animacion derecha
                    }
                    break;
            }
        }
    }
}


void Gui::run() {
    const nanoseconds rate_ns(static_cast<int>(1e9 / RATE));

    SDL sdl(SDL_INIT_VIDEO);
    SDLTTF ttf;

    SDL_DisplayMode displayMode;
    int monitorIndex = 1;

    Window window{Window("Jazz JackRabbit 2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                         screenHeight, screenWidth, SDL_WINDOW_RESIZABLE | SDL_WINDOW_HIDDEN)};

    Renderer renderer{Renderer(window, -1, SDL_RENDERER_ACCELERATED)};

    ClaseTexturas texturas{ClaseTexturas(renderer)};

    setEscenario(texturas);

    std::unique_ptr<PersonajeGui> jugador;
    if (personaje == "j") {
        jugador = std::make_unique<JazzGui>(texturas, renderer.GetOutputWidth() / 2,
                                            renderer.GetOutputHeight() / 2);
    } else if (personaje == "s") {
        jugador = std::make_unique<SpazGui>(texturas, renderer.GetOutputWidth() / 2,
                                            renderer.GetOutputHeight() / 2);
    } else if (personaje == "l") {
        jugador = std::make_unique<LoriGui>(texturas, renderer.GetOutputWidth() / 2,
                                            renderer.GetOutputHeight() / 2);
    }

    Escenario escenario(plataformas);

    int animacion = ANI_STAND;

    auto frame_start = steady_clock::now();


    unsigned int prev_ticks = SDL_GetTicks();
    window.Show();
    while (1) {
        unsigned int frame_ticks = SDL_GetTicks();
        unsigned int frame_delta = frame_ticks - prev_ticks;
        int dif_x = 0;
        int dif_y = 0;
        prev_ticks = frame_ticks;

        this->eventManaged(animacion);
        // Clear the screen
        renderer.Clear();
        escenario.show();

        // std::cout << "client id: " << client_id << std::endl;
        // std::cout << "sizes personajes map: " << personajes.size() << std::endl;

        for (const auto& [_, personaje]: personajes) {
            std::unique_ptr<PersonajeGui> pers;
            int x = renderer.GetOutputWidth() / 2 +
                    (personaje->obtener_posicion().get_posicion_x() - pos_x);
            int y = renderer.GetOutputHeight() / 2 +
                    (personaje->obtener_posicion().get_posicion_y() - pos_y);
            // std::cout << (unsigned)personaje->obtener_tipo_personaje() << std::endl;
            if (personaje->obtener_tipo_personaje() == (uint8_t)personajes::JAZZ) {
                pers = std::make_unique<JazzGui>(texturas, x, y);
                pers->show(personaje->obtener_animacion());
            } else if (personaje->obtener_tipo_personaje() == (uint8_t)personajes::SPAZZ) {
                pers = std::make_unique<SpazGui>(texturas, x, y);
                pers->show(personaje->obtener_animacion());
            } else if (personaje->obtener_tipo_personaje() == (uint8_t)personajes::LORI) {
                pers = std::make_unique<LoriGui>(texturas, x, y);
                pers->show(personaje->obtener_animacion());
            }
        }
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

        if (client_off) {
            return;
        }
    }
}


/*void Gui::setGameState( respuesta){

}*/
