#include "../include/client_src/gui/gui.h"

Gui::Gui(int x, int y, bool& client_off, std::string& personaje, Queue<msgAccion>& client_commands,
         VectorMonitor<std::shared_ptr<PlatformGui>>& plataformas, uint16_t& ci):
        pos_x(x),
        pos_y(y),
        client_off(client_off),
        personaje(personaje),
        client_commands(client_commands),
        plataformas(plataformas),
        client_id(ci) {}

Gui::~Gui() {}

void Gui::setGameState(GameStateClient& gamestate) {

    dic_personajes = gamestate.obtener_diccionario_de_personajes();
    pos_x = gamestate.obtener_personaje(client_id)->obtener_posicion_x();
    pos_y = gamestate.obtener_personaje(client_id)->obtener_posicion_y();
    dic_personajes.erase(client_id);
}


void Gui::run() {
    const nanoseconds rate_ns(static_cast<int>(1e9 / RATE));

    SDL sdl(SDL_INIT_VIDEO);
    SDLTTF ttf;

    // SDL_DisplayMode displayMode;
    //  int monitorIndex = 1;

    Window window{Window("Jazz JackRabbit 2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                         screenHeight, screenWidth, SDL_WINDOW_RESIZABLE | SDL_WINDOW_HIDDEN)};

    Renderer renderer{Renderer(window, -1, SDL_RENDERER_ACCELERATED)};

    auto texturas = std::make_shared<ClaseTexturas>(renderer);

    // this->setEscenario(*texturas);

    std::unique_ptr<PersonajeGui> jugador;
    std::shared_ptr<std::vector<Frame>> frames;
    std::shared_ptr<std::vector<Frame>> frames_personajes;
    if (personaje == "j") {
        frames = texturas->findFrame(std::string(JAZZ_STAND));
        jugador = std::make_unique<JazzGui>(texturas, renderer.GetOutputWidth() / 2,
                                            renderer.GetOutputHeight() / 2, 4,
                                            frames);  // 4 ponerlo como define
    } else if (personaje == "s") {
        frames = texturas->findFrame(std::string(SPAZ_STAND));
        jugador = std::make_unique<SpazGui>(texturas, renderer.GetOutputWidth() / 2,
                                            renderer.GetOutputHeight() / 2, 4, frames);
    } else if (personaje == "l") {
        frames = texturas->findFrame(std::string(LORI_STAND));
        jugador = std::make_unique<LoriGui>(texturas, renderer.GetOutputWidth() / 2,
                                            renderer.GetOutputHeight() / 2, 4, frames);
    }


    for (size_t i = 0; i < plataformas.size(); i++) {
        std::shared_ptr<Frame> beach = std::make_shared<Frame>(
                texturas->findFrame(std::string(PLATFORM_BEACH_TYPE_1))->at(0));
        plataformas[i]->setFrame(beach);
    }

    Escenario escenario(plataformas);

    KeyboardHandler keyhandler;

    int animacion = ANI_STAND;

    auto frame_start = steady_clock::now();

    window.Show();
    while (1) {

        client_off = keyhandler.keyBoardManaged(animacion, jugador, client_commands);
        // Clear the screen
        renderer.Clear();

        escenario.show(pos_x, pos_y);
        for (const auto& [id, personaje]: dic_personajes) {
            std::unique_ptr<PersonajeGui> pers;
            int x = (personaje->obtener_posicion_x() - pos_x) * SCALING_VALUE_PIXEL_X;
            int y = (personaje->obtener_posicion_y() - pos_y) * SCALING_VALUE_PIXEL_Y;
            if (x <= (pos_x + renderer.GetOutputWidth() / 2) ||
                x <= (pos_x - renderer.GetOutputWidth() / 2) ||
                y <= (pos_y + renderer.GetOutputHeight() / 2) ||
                y <= (pos_y - renderer.GetOutputHeight() / 2)) {
                if (personaje->obtener_tipo_personaje() == (uint8_t)personajes::JAZZ) {
                    frames_personajes = texturas->findFrame(std::string(JAZZ_STAND));
                    pers = std::make_unique<JazzGui>(texturas, x, y, 5, frames_personajes);
                } else if (personaje->obtener_tipo_personaje() == (uint8_t)personajes::SPAZZ) {
                    frames_personajes = texturas->findFrame(std::string(SPAZ_STAND));
                    pers = std::make_unique<SpazGui>(texturas, x, y, 5, frames_personajes);
                } else if (personaje->obtener_tipo_personaje() == (uint8_t)personajes::LORI) {
                    frames_personajes = texturas->findFrame(std::string(LORI_STAND));
                    pers = std::make_unique<LoriGui>(texturas, x, y, 5, frames_personajes);
                }
                pers->show();  // personaje->obtener_animacion());
            }
        }
        jugador->show();
        renderer.Present();

        auto frame_end = steady_clock::now();
        auto rest = rate_ns - (frame_end - frame_start);

        if (rest.count() < 0) {
            auto behind = -rest;
            auto lost = behind - behind % rate_ns;
            frame_start += lost;
        }
        std::this_thread::sleep_for(rest);
        frame_start += rate_ns;

        if (client_off) {
            return;
        }
    }
}
