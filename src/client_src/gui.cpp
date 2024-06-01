#include <iostream>
#include <exception>
#include <memory>

#include "../include/gui.h"
#include "../include/personaje.h"
#include "../include/escenario.h"

Gui::Gui(int x, int y, int w, int h,bool & client_off,std::string & personaje):
    posx(x),posy(y),w(w),h(h),client_off(client_off),personaje(personaje){}

Gui::~Gui(){}

void Gui::run() {

    const nanoseconds rate_ns(static_cast<int>(1e9 / RATE));

    SDL sdl(SDL_INIT_VIDEO);
    SDLTTF ttf;

    SDL_DisplayMode displayMode;
    int monitorIndex = 1;

    int screenWidth = 600;
    int screenHeight = 800;

    Window window("SDL2pp demo",
                  SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                  screenHeight, screenWidth,
                  SDL_WINDOW_RESIZABLE);

    Renderer renderer(window, -1, SDL_RENDERER_ACCELERATED);

    // crear clase para guardar todos los texturas:
    // mapa que indixe por cada uno de la textura. 
    // {'jazz_walk': jazz_tex}
    // se podria mandar los frame_vector.
    Surface jazz{Surface(IMG_PATH "/jazz.png")};
    Texture sprites{Texture(renderer, jazz.SetColorKey(true, SDL_MapRGB(jazz.Get()->format, 44, 102, 150)))};

    std::unique_ptr<Personaje> jugador;
    if (personaje == "j") {
        jugador = std::make_unique<Jazz>(renderer);
    } else if (personaje == "s") {
        jugador = std::make_unique<Spaz>(renderer);
    } else if (personaje == "l") {
        jugador = std::make_unique<Lori>(renderer);
    }
    Escenario escenario(renderer);

    int animacion = 0;
    int animacion_prev = 0;

	auto frame_start = steady_clock::now();;
	unsigned int prev_ticks = SDL_GetTicks();

	while (1) {

		unsigned int frame_ticks = SDL_GetTicks();
		unsigned int frame_delta = frame_ticks - prev_ticks;
        int dif_x=0;
        int dif_y=0;
		prev_ticks = frame_ticks;
        SDL_Event event;
        // definir N it para las animaciones de frame.
        // dividite por X de la diapos que mostro leo.
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                return;
            } else if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_ESCAPE: 
                    case SDLK_q:
                        client_off=true;
                        return;
                    case SDLK_s:
                        // enviar mensajer atacar 1 ((16bytes) (16bytes) (16bytes))
                        return;
                    case SDLK_RIGHT: 
                        // enviar mensaje mover derecha 1
                        animacion = 1;
                        dif_x -= frame_delta * 0.2;
                        break;
                    case SDLK_LEFT:
                        // enviar mensaje mover izquierda 1
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

        // Limpiar pantalla
        renderer.Clear();
        escenario.show(dif_x,dif_y);
        jugador->show(animacion);
        renderer.Present();

        auto frame_end = steady_clock::now();
    	auto rest = rate_ns - (frame_end-frame_start);

		if (rest.count()<0)
		{
            auto behind = -rest;
            auto lost = behind - behind % rate_ns;
            frame_start += lost;
		} else {
            std::this_thread::sleep_for(rest);
		}
        frame_start += rate_ns;
    }
}
