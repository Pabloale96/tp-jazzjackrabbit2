#include "../include/gui.h"

#include <chrono>
#include <exception>
#include <iostream>
#include <memory>
#include <thread>

#include "../include/escenario.h"
#include "../include/personaje.h"

Gui::Gui() {}

Gui::~Gui() {}

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

    std::unique_ptr<Personaje> spaz = std::make_unique<Spaz>(renderer);
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

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                return;
            } else if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                    case SDLK_q:
                        return;
                    case SDLK_RIGHT:
                        animacion = 1;
                        dif_x -= frame_delta * 0.2;
                        break;
                    case SDLK_LEFT:
                        animacion = 2;
                        dif_x += frame_delta * 0.2;
                        break;
                }
            } else if (event.type == SDL_KEYUP) {
                switch (event.key.keysym.sym) {
                    case SDLK_RIGHT:
                        animacion = 0;
                        break;
                    case SDLK_LEFT:
                        animacion = 0;
                        break;
                }
            }
        }

        // Clear the screen
        renderer.Clear();
        escenario.show(dif_x, dif_y);
        spaz->show(animacion);
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
