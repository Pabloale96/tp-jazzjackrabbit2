#include "../include/client_src/gui/gui.h"

Gui::Gui(int x, int y, int w, int h, bool& client_off, std::string& personaje,
         Queue<msgAccion>& client_commands,std::vector<msgPlataforma>& msg_plataformas,uint16_t & ci):
        pos_x(x),
        pos_y(y),
        w(w),
        h(h),
        client_off(client_off),
        personaje(personaje),
        client_commands(client_commands),
        msg_plataformas(msg_plataformas),
        client_id(ci) {}

Gui::~Gui() {}

void Gui::setGameState(GameState& gamestate) {
    
    for (const auto& pair: gamestate.obtener_diccionario_de_personajes()) {
        if (pair.first == client_id) {
            pos_x = pair.second.obtener_posicion().get_posicion_x();
            pos_y = pair.second.obtener_posicion().get_posicion_y();
        } else {
            msgPersonaje personaje(pair.first,pair.second);
            personajes.push_back(std::move(personaje));
        }
    }
}
void Gui::setEscenario(ClaseTexturas & texturas) {    
    for (size_t i = 0; i < msg_plataformas.size(); i++)
    {
        PlatformGui plataforma(texturas,msg_plataformas[i]);
        plataformas.push_back(plataforma);
    }
}

void Gui::run() {
    const nanoseconds rate_ns(static_cast<int>(1e9 / RATE));

    SDL sdl(SDL_INIT_VIDEO);
    SDLTTF ttf;

    SDL_DisplayMode displayMode;
    int monitorIndex = 1;

    Window window{Window("SDL2pp demo", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                        screenHeight, screenWidth, SDL_WINDOW_RESIZABLE  | SDL_WINDOW_HIDDEN)};

    Renderer renderer{Renderer(window, -1, SDL_RENDERER_ACCELERATED)};

    ClaseTexturas texturas{ClaseTexturas(renderer)};
    
    setEscenario(texturas);

    std::unique_ptr<PersonajeGui> jugador;
    if (personaje == "j") {
        jugador = std::make_unique<JazzGui>(texturas,renderer.GetOutputWidth()/2,renderer.GetOutputHeight()/2);
    } else if (personaje == "s") {
        jugador = std::make_unique<SpazGui>(texturas,renderer.GetOutputWidth()/2,renderer.GetOutputHeight()/2);
    } else if (personaje == "l") {
        jugador = std::make_unique<LoriGui>(texturas,renderer.GetOutputWidth()/2,renderer.GetOutputHeight()/2);
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
        SDL_Event event;
        // definir N it para las animaciones de frame.
        // dividite por X de la diapos que mostro leo.
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                return;
            } else if (event.type == SDL_KEYDOWN) {
                msgAccion msg_to_sent(0x00, false);
                
                switch (event.key.keysym.sym ) {
                    case SDLK_ESCAPE:
                    case SDLK_q:
                        client_off = true;
                        return;
                    case SDLK_s:
                        // enviar mensajer atacar 1 ((16bytes) (16bytes) (16bytes))
                        // push a client_commands
                        return;
                    case SDLK_RIGHT:
                        if (animacion != ANI_MOVER_DERECHA)
                        {
                            msg_to_sent = msgAccion(MOVER_DERECHA, true);
                            client_commands.push(msg_to_sent);
                            animacion = ANI_MOVER_DERECHA;  // se ejecuta la animacion derecha
                        }
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
        escenario.show();
        for (size_t i = 0; i < personajes.size(); i++)
        {
            std::unique_ptr<PersonajeGui> pers;
            int x = renderer.GetOutputWidth()/2 + SCALING_VALUE_PIXEL*(ntohs(personajes[i].personaje[POS_POSX_PERSONAJE]) - pos_x);
            int y = renderer.GetOutputHeight()/2 + SCALING_VALUE_PIXEL*(ntohs(personajes[i].personaje[POS_POSY_PERSONAJE]) - pos_y);
            std::cout << "tipo personaje: "<< personajes[i].personaje[POS_TIPO_PERSONAJE]<< std::endl;
            if (ntohs(personajes[i].personaje[POS_TIPO_PERSONAJE]) == static_cast<uint16_t>(TIPO_PERSONAJE::JAZZ)) {
                pers = std::make_unique<JazzGui>(texturas,x,y);
                pers->show(animacion);
            } else if (ntohs(personajes[i].personaje[POS_TIPO_PERSONAJE])  == static_cast<uint16_t>(TIPO_PERSONAJE::SPAZZ)) {
                pers = std::make_unique<SpazGui>(texturas,x,y);
                pers->show(animacion);
            } else if (ntohs(personajes[i].personaje[POS_TIPO_PERSONAJE])  == static_cast<uint16_t>(TIPO_PERSONAJE::LORI)) {
                pers = std::make_unique<LoriGui>(texturas,x,y);
                pers->show(animacion);
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
    }
}


/*void Gui::setGameState( respuesta){

}*/
